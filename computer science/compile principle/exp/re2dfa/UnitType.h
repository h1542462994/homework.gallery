#pragma once
#include <string>
using namespace std;

namespace texting {
    class UnitType {
    public:
        static const int empty;
        static const int unit;
        static const int star;
        static const int optional;
        static const int any;
        static const int concatGroup;
        static const int orGroup;
    };
    const int UnitType::empty = -1;
    const int UnitType::unit = 0;
    const int UnitType::star = 1;
    const int UnitType::optional = 2;
    const int UnitType::any = 3;
    const int UnitType::concatGroup = 4;
    const int UnitType::orGroup = 5;
}

