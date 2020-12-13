#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include "UnitType.h"
using namespace std;

namespace texting {
    /**
     * ReUnit存储，标识一个RegularExpression的节点
     */
    class ReUnit {
    private:
        /**
         * 节点的类型，定义于UnitType
         */
        int unitType = UnitType::unit;
        /**
         * 节点的数据，仅用于UnitType == unit时。
         */
        string data;
        /**
         * 子节点，默认为空集合
         */
        vector<ReUnit> children;
    public:
        int getUnitType() const {
            return unitType;
        }
        string getUnitTypeString(){
            if (unitType == UnitType::empty) {
                return "(empty)";
            } else if(unitType == UnitType::star) {
                return "(*)";
            } else if(unitType == UnitType::any) {
                return "(+)";
            } else if(unitType == UnitType::unit) {
                return "(unit)";
            } else if(unitType == UnitType::optional) {
                return "(?)";
            } else if(unitType == UnitType::concatGroup) {
                return "(concat)";
            } else {
                return "(|)";
            }
        }
        string getData() const {
            return data;
        }
        vector<ReUnit> getChildren() const {
            return children;
        }
        ReUnit first() const{
            return getChildren()[0];
        }
        /**
         * 返回空串
         */
        static ReUnit empty() {
            ReUnit unit;
            unit.unitType = UnitType::empty;
            return unit;
        }
        /**
         * 一个简单的字符单元 like:a
         */
        static ReUnit unit(const string& text){
            ReUnit unit;
            unit.unitType = UnitType::unit;
            unit.data = text;
            unit.children = {};
            return unit;
        }
        /**
         * 一个简单的闭包 like:a* (ab)*
         */
        static ReUnit star(ReUnit child){
            ReUnit unit;
            unit.unitType = UnitType::star;
            unit.children = {std::move(child)};
            return unit;
        }
        /**
         * 匹配0次或1次 like:a? (ab)?
         */
        static ReUnit optional(ReUnit child){
            ReUnit unit;
            unit.unitType = UnitType::optional;
            unit.children = {std::move(child)};
            return unit;
        }
        /**
         * 匹配1次或多次 like:a+ (ab)+
         */
        static ReUnit any(ReUnit child) {
            ReUnit unit;
            unit.unitType = UnitType::any;
            unit.children = {std::move(child)};
            return unit;
        }
        /**
         * 匹配联合式
         */
        static ReUnit concatGroup(vector<ReUnit> children) {
            ReUnit unit;
            unit.unitType = UnitType::concatGroup;
            unit.children = std::move(children);
            return unit;
        }
        /**
         * 匹配联合或式
         */
        static ReUnit orGroup(vector<ReUnit> children) {
            ReUnit unit;
            unit.unitType = UnitType::orGroup;
            unit.children = std::move(children);
            return unit;
        }

        string getExpression() const {
            if (unitType == UnitType::empty) {
                return "{empty}";
            } else if (unitType == UnitType::unit) {
                return data;
            } else if(unitType == UnitType::star) {
                return first().getExpression() + "*";
            } else if(unitType == UnitType::optional) {
                return first().getExpression() + "?";
            } else if (unitType == UnitType::any) {
                return first().getExpression() + "+";
            } else if (unitType == UnitType::concatGroup) {
                return getExpressionOfConcatGroup();
            } else if (unitType == UnitType::orGroup) {
                return getExpressionOfOrGroup();
            }
            return "";
        }
        string getExpressionOfConcatGroup() const {
            ostringstream o_str;
            for (const auto& token: getChildren()) {
                auto c = token.getChildren();
                if (c.size() > 1) {
                    o_str << "(";
                }
                o_str << token.getExpression();
                if (c.size() > 1) {
                    o_str << ")";
                }
            }
            return o_str.str();
        }
        string getExpressionOfOrGroup() const {
            ostringstream o_str;
            for(size_t i = 0; i < getChildren().size(); ++i) {
                auto c = getChildren()[i].children;
                if (c.size() > 1) {
                    o_str << "(";
                }
                o_str << getChildren()[i].getExpression();
                if (c.size() > 1) {
                    o_str << ")";
                }
                if(i < getChildren().size() - 1){
                    o_str << "|";
                }
            }
            return o_str.str();
        }

    };
}


