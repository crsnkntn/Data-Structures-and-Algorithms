#include "Graph.h"
#include <math.h>

struct Point {
    double x;
    double y;

    Point (double a, double b) : x(a), y(b) {}
};

struct Distance {
    double distance_function (Point& p1, Point& p2) {
        return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }
};

template <typename State, class CostFunction>
Graph<State, CostFunction>::Graph (std::initializer_list<State*> il) {
    for (auto i : il)
        states.push_back(i);
}

template <typename State, class CostFunction>
Graph<State, CostFunction>::~Graph () {}

int main () {
    Graph<Point, Distance> graph {new Point(1.1, 1.2)};
}