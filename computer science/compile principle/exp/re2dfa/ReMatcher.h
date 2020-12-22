#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include "Edge.h"
#include "SortedSet.h"
using namespace std;
using namespace util;

namespace texting {
    // 匹配的有限自动机
    class ReMatcher {
    private:
        int maxPoint;
        vector<Edge> edges;
        SortedSet<int> terminals;
    public:
        ReMatcher(int maxPoint, vector<Edge> edges, SortedSet<int> terminals, bool openDebug = true): maxPoint(maxPoint), edges(std::move(edges)), terminals(std::move(terminals)), openDebug(openDebug) {
            debugPrint();
        }

        bool openDebug = true;

        void debugPrint() const {
            if (openDebug) {
                cout << "====================dfa====================" << endl;
                cout << *this << endl;
                cout << "===========================================" << endl;
            }
        }

        string wrapPointWithStart(int point) const {
            if (terminals.contains(point)) {
                return "*" + to_string(point);
            } else {
                return " " + to_string(point);
            }
        }

        // 打印所有的边
        friend ostream & operator << (ostream& o_str, const ReMatcher& v){
            o_str << "  | " << setw(5) << "index"  << " | " << setw(6) << "start" << " | " << setw(6) << "end" << " | " << setw(10) << "type" << " | " << "expression" << endl;
            int edgeCount = v.edges.size();
            for (int i = 0; i < edgeCount; ++i) {
                auto edge = v.edges[i];
                o_str << " | " << setw(5) << i << " | " << setw(6) << v.wrapPointWithStart(edge.startPoint) << " | " << setw(6) << v.wrapPointWithStart(edge.endPoint) << " | " << setw(10) << edge.reUnit.getUnitTypeString() << " | " << edge.reUnit.getExpression();
                if (i < edgeCount - 1){
                    o_str << endl;
                }
            }
            return o_str;
        }
    };
}

