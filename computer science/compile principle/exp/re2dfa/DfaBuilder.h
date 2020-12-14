#pragma once
#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <map>
#include <string>
#include <set>
#include "Edge.h"
#include "SortedSet.h"

using namespace std;
using namespace util;

namespace texting {
    // DfaBuilder，用于编译DfaBuilder到ReMatcher
    class DfaBuilder {
    private:
        // 继承于NfaBuilder
        int maxPoint;
        vector<Edge> edges;
        // 点集的闭包
        vector<SortedSet<int>> pointClosures;
        // unit集合
        SortedSet<string> options;
        // 跳跃点
        map<string, vector<Edge>> jumpEdges;

        // 新的点集合
        vector<SortedSet<int>> newPoints;
        vector<vector<SortedSet<int>>> newEdges;

        void addSkipEdge(const Edge& edge){
            jumpEdges[edge.reUnit.getExpression()].emplace_back(edge);
        }
        void initialize() {
            for (int i = 0; i < edges.size(); ++i) {
                edges[i].index = i;
            }

            // 初始化存储区
            for (int i = 0; i <= maxPoint; ++i) {
                pointClosures.emplace_back();
                pointClosures[i].add(i);
            }

            // 进行统计
            for (const auto& edge: edges) {
                auto type = edge.reUnit.getUnitType();
                if (type == UnitType::unit) {
                    string content = edge.reUnit.getExpression();
                    options.add(content);
                    pointClosures[edge.startPoint].add(edge.startPoint);
                    addSkipEdge(edge);
                } else if (type == UnitType::empty) {
                    pointClosures[edge.startPoint].add(edge.endPoint);
                }
            }
            debugPrintInitialize();
        }

    public:
        bool openDebug = true;
        DfaBuilder(int maxPoint, vector<Edge> edges, bool openDebug = true): maxPoint(maxPoint), edges(std::move(edges)), openDebug(openDebug) {
            initialize();
        }
        void debugPrintInitialize() {
            if (openDebug) {
                printClosures();
                cout << endl;
                printOptions();
                cout << endl;
                printSkipEdges();
            }
        }
        void debugPrint() {
            if (openDebug) {
                printTable();
            }
        }
        SortedSet<int> jumpEdgeIndexAt(int option){
            auto data = jumpEdges.find(options[option])->second;
            SortedSet<int> set;
            for (const auto& v: data) {
                set.add(v.index);
            }
            return set;
        }
        void putPoint(const SortedSet<int>& point) {
            if (point.size() == 0) {
                return;
            }
            for (const auto& p: newPoints) {
                if (p == point){
                    return;
                }
            }
            newPoints.emplace_back(point);
        }
        int findPointIndex(const SortedSet<int>& point) {
            for (int i = 0; i < newPoints.size(); ++i) {
                if (newPoints[i] == point) {
                    return i;
                }
            }
            return -1;
        }
        // 跳边
        SortedSet<int> jump(const SortedSet<int>& point, int option) {
            // 获取与option有关的边
            SortedSet<int> es = jumpEdgeIndexAt(option);
            SortedSet<int> result;
            // 查找每一条边
            for (auto e: es.data) {
                // 找到边
                Edge edge = edges[e];
                // 如果边的起始点位于point集合内
                if (point.contains(edge.startPoint)) {
                    // 那么将endPoint的闭包加入result集合
                    result.addAnother(pointClosures[edge.endPoint]);
                }
            }
            return result;
        }
        string getCombinationPointAndPointIndex(const SortedSet<int>& point) {
            ostringstream o_str;
            if (point.size() == 0) {
                o_str << "/";
            } else {
                if (point.contains(1)){
                    o_str << "*";
                }
                o_str << findPointIndex(point) << ",";
                o_str << point;
            }

            return o_str.str();
        }
        // 进行编译
        void compile() {
            int proceedIndex = 0;
            putPoint(pointClosures[0]); // 放置初始点集
            // 构建表格
            while (proceedIndex < newPoints.size()) {
                auto point = newPoints[proceedIndex];
                newEdges.emplace_back();
                for (int i = 0; i < options.size(); ++i) {
                    //auto collection = newEdges[proceedIndex];
                    auto newPoint = jump(point, i);
                    putPoint(newPoint);
                    newEdges[proceedIndex].emplace_back(newPoint);
                }
                proceedIndex++;
            }
            debugPrint();
        }
        void printClosures() {
            int count = pointClosures.size();
            cout << "==========pointClosures==========" << endl;
            cout << " | " << setw(6) << "point" << " | " << "closure" << endl;
            for (int i = 0; i < count; ++i) {
                cout << " | " << setw(6) << i << " | " << pointClosures[i] << endl;
            }
            cout << "=================================";
        }
        void printOptions() {
            cout << "options:" << options;
        }
        void printSkipEdges(){
            cout << " | " << setw(6) <<  "option" << " | " << "edges" << endl;
            cout << "==========jumpEdges==========" << endl;
            for (int i = 0; i < options.size(); ++i) {
                cout << " | " << setw(6) << options[i] << " | " << jumpEdgeIndexAt(i) << endl;
            }
            cout << "=============================" << endl;
        }
        void printTable(){
            cout << "===============table=============" << endl;
            cout << " | " << setw(20) << "point" << " | ";
            for (int i = 0; i < options.size(); ++i) {
                cout << setw(20) << options[i] << " | ";
            }
            cout << endl;
            for (int i = 0; i < newEdges.size(); ++i) {
                auto collection = newEdges[i];
                cout << " | " << setw(20) << getCombinationPointAndPointIndex(newPoints[i]) << " | ";
                for (int j = 0; j < options.size(); ++j) {
                    cout << setw(20) << getCombinationPointAndPointIndex(newEdges[i][j]) << " | ";
                }
                cout << endl;
            }

        }

    };
}
