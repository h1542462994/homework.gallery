#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "DfaBuilder.h"
#include "Edge.h"
#include "UnitType.h"
using namespace std;
using namespace texting;

namespace texting {
    // NfaBuilder，用于编译ReUnit到DfaBuilder
    class NfaBuilder {
    private:
        int maxPoint = 0;
        vector<Edge> edges;
        int printIndex = 0;
    public:
        bool openDebug = true;
        NfaBuilder() = default;
        explicit NfaBuilder(const ReUnit& root, bool openDebug = true): openDebug(openDebug) {
            maxPoint = 1;
            edges = {Edge(0, 1, root)};
        }
        // 获取一个新的点
        int newPoint() {
            return ++maxPoint;
        }
        void debugClean() {
            printIndex = 0;
        }
        void debugPrint(int proceedIndex, bool before = false) {
            if (openDebug) {
                if (before) {
                    cout << "=============before " << printIndex++ << "=============" << endl;
                }
                cout << "line:" << proceedIndex << endl;
                cout << *this << endl;
                if (!before) {
                    cout << "===================================" << endl;
                }
            }
        }
        // 编译成DFA
        DfaBuilder compileToDfa() {
            debugClean();
            int proceedIndex = 0;
            while (proceedIndex < edges.size()) {
                debugPrint(proceedIndex, true);
                auto current = edges[proceedIndex];
                auto type = current.reUnit.getUnitType();
                if(type == UnitType::unit || type == UnitType::empty) {
                    proceedIndex++;
                } else {
                    if(type == UnitType::star) {
                        // 复杂边解构
                        // 先移除复杂边
                        edges.erase(edges.cbegin() + proceedIndex);
                        proceedStar(current);
                    } else if(type == UnitType::optional) {
                        edges.erase(edges.cbegin() + proceedIndex);
                        proceedOptional(current);
                    } else if(type == UnitType::any) {
                        edges.erase(edges.cbegin() + proceedIndex);
                        proceedAny(current);
                    } else if(type == UnitType::concatGroup) {
                        edges.erase(edges.cbegin() + proceedIndex);
                        proceedConcatGroup(current);
                    } else if(type == UnitType::orGroup) {
                        edges.erase(edges.cbegin() + proceedIndex);
                        proceedOrGroup(current);
                    } else {
                        // 不处理
                        proceedIndex++;
                    }
                }
                debugPrint(proceedIndex);
            }
            return DfaBuilder(maxPoint, edges, openDebug);
        }
        // 处理a*或者(ab)*的情况
        void proceedStar(const Edge& edge) {
            int point = newPoint();

            // 增加一条空边
            edges.emplace_back(edge.startPoint, point, ReUnit::empty());
            // 增加一条环边，其边内容为子元素
            edges.emplace_back(point, point, edge.reUnit.first());
            // 增加一条空边
            edges.emplace_back(point, edge.endPoint, ReUnit::empty());
        }
        // 处理a?或者(ab)?的情况
        void proceedOptional(const Edge& edge) {
            // 添加一条边，其为?的子元素
            edges.emplace_back(edge.startPoint, edge.endPoint, edge.reUnit.first());
            // 添加一条空边
            edges.emplace_back(edge.startPoint, edge.endPoint, ReUnit::empty());
        }
        // 处理a+的情况，分解为aa*的解决方式
        void proceedAny(const Edge& edge) {
            // 添加一个点
            int point = newPoint();
            auto child = edge.reUnit.first();
            // a边
            edges.emplace_back(edge.startPoint, point, child);
            // a*边
            edges.emplace_back(point, edge.endPoint, ReUnit::star(child));
        }
        // 处理a|b或者a|b*的情况
        void proceedOrGroup(const Edge& edge) {
            // 或边不需要创建新的点集，只需要拆分边就可以了
            for(const auto& unit: edge.reUnit.getChildren()) {
                edges.emplace_back(edge.startPoint, edge.endPoint, unit);
            }
        }
        // 处理abc或者ab(abc*)的情况
        void proceedConcatGroup(const Edge& edge) {
            int count = edge.reUnit.getChildren().size();
            int oldPoint = edge.startPoint; // 起始点为edge.startPoint
            for (int i = 0; i < count; ++i) {
                // 获取当前点
                auto current = edge.reUnit.getChildren()[i];
                if (i < count - 1) {
                    // 创建一个点并添加一条边
                    int point = newPoint();
                    edges.emplace_back(oldPoint, point, current);
                    oldPoint = point;
                } else {
                    // 最后一项时，不需要添加点
                    edges.emplace_back(oldPoint, edge.endPoint, current);
                }
            }
        }
        // 打印所有的边
        friend ostream & operator << (ostream& o_str, const NfaBuilder& v){
            o_str << " | " << setw(5) << "index"  << " | " << setw(6) << "start" << " | " << setw(6) << "end" << " | " << setw(10) << "type" << " | " << "expression" << endl;
            int edgeCount = v.edges.size();
            for (int i = 0; i < edgeCount; ++i) {
                auto edge = v.edges[i];
                o_str << " | " << setw(5) << i << " | " << setw(6) << edge.startPoint << " | " << setw(6) << edge.endPoint << " | " << setw(10) << edge.reUnit.getUnitTypeString() << " | " << edge.reUnit.getExpression();
                if (i < edgeCount - 1){
                    o_str << endl;
                }
            }
            return o_str;
        }
    };
}
