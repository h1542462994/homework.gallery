#pragma once
#include <utility>

#include "ReUnit.h"

namespace texting {
    class Edge {
    private:
    public:
        int startPoint;
        int endPoint;
        ReUnit reUnit;

        Edge(int startPoint, int endPoint, ReUnit reUnit): startPoint(startPoint), endPoint(endPoint), reUnit(std::move(reUnit)) {}
    };
}
