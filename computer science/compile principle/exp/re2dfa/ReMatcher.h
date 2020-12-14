#pragma once
#include <iostream>
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
        bool openDebug = true;
    };
}

