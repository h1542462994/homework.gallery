#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include "ReUnit.h"
#include "NfaBuilder.h"

using namespace std;
namespace texting {
    class ReBuilder {
    private:
        int index = 0;
        int printIndex = 0;
        string text;
        vector<ReUnit> data;
        vector<int> leftLocations;
        vector<int> orLocations;
    public:
        bool openDebug = true;
        explicit ReBuilder(string text, bool openDebug = true): text(std::move(text)), openDebug(openDebug) {
        }


        void debugPrint() {
            if (openDebug) {
                cout << "==============sq " << printIndex++ << "=============" << endl;
                cout << "data: ";
                for (auto & i : data) {
                    cout << i.getExpression() << "  ";
                }
                cout << endl;
                cout << "orLocations: ";
                for (auto & v : orLocations) {
                    cout << v << " ";
                }
                cout << endl;
                cout << "leftLocations: ";
                for (auto & v: leftLocations) {
                    cout << v << " ";
                }
                cout << endl;
                cout << "=================================" << endl;
            }
        }
        void debugPrintTempUnits(vector<ReUnit>& vs) {
            cout << "<<<<<<< wrap <<<<<<<" << endl;
            cout << "tempUnits: ";
            for (auto & v: vs) {
                cout << v.getExpression() << "  ";
            }
            cout << endl;
        }

        int lastLeftLocation() {
            if (leftLocations.empty()) {
                return -1;
            } else {
                return leftLocations.back();
            }
        }

        void wrap() {
            int startIndex = lastLeftLocation() + 1;
            vector<ReUnit> tempUnits = {};
            // whether to add a node to tempUnits
            bool needCreateAnchor = true;
            // to wrap the sequence of concat
            for (int i = startIndex; i < data.size(); ++i) {

                ReUnit top = data[i];
                // if the top is or separator
                if (top.getUnitType() == UnitType::unit && top.getExpression() == "|"){
                    needCreateAnchor = true;
                    // to remove a record from list stores |
                    orLocations.pop_back();
                } else {
                    // if need to add a node to tempUnits
                    if (needCreateAnchor) {
                        needCreateAnchor = false;
                        tempUnits.emplace_back(top);
                    } else {
                        // must be a reference
                        ReUnit& tempTop = tempUnits.back();
                        if (tempTop.getUnitType() == UnitType::concatGroup) {
                            tempTop.childrenRef().emplace_back(top);
                        } else {
                            ReUnit replaceTop = ReUnit::concatGroup({tempTop, top});
                            tempUnits.pop_back();
                            tempUnits.emplace_back(replaceTop);
                        }
                    }
                }
                debugPrintTempUnits(tempUnits);
            }

            // to remove the sequence
            while (data.size() > startIndex) {
                data.pop_back();
            }
            // to remove if the top is (
            if (!data.empty()) {
                data.pop_back();
                // to remove a record form list stores (
                leftLocations.pop_back();
            }

            if (!tempUnits.empty()) {
                data.emplace_back(ReUnit::orGroup(tempUnits));
            } else {
                data.emplace_back(tempUnits[0]);
            }

        }

        NfaBuilder compileToReUnit() {
            int count = text.size();
            while (index < count) {
                string t = text.substr(index, 1);
                if (t == "*") {
                    auto u = data.back();
                    data.pop_back();
                    data.emplace_back(ReUnit::star(u));
                } else if(t == "?") {
                    auto u = data.back();
                    data.pop_back();
                    data.emplace_back(ReUnit::optional(u));
                } else if(t == "+") {
                    auto u = data.back();
                    data.emplace_back(ReUnit::any(u));
                } else if(t == "|") {
                    // 记录当前符号的位置
                    orLocations.emplace_back(data.size());
                    data.emplace_back(ReUnit::unit(t));
                } else if(t == "(") {
                    // 记录当前符号的位置
                    leftLocations.emplace_back(data.size());
                    data.emplace_back(ReUnit::unit(t));
                } else if(t == ")") {
                    wrap();
                } else {
                    data.emplace_back(ReUnit::unit(t));
                }
                ++index;
                debugPrint();
            }
            wrap();
            debugPrint();
            cout << endl;
            return NfaBuilder(data.front(), true);
        }

    };
}
