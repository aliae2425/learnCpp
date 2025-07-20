#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x;
    double y;
};

int length(const Point& p1, const Point& p2) {
    return static_cast<int>(sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y)));
}

int main() {
    std::vector<Point> points;

    std::cout << "Entrez les coordonées du premier point (x y) : ";
    Point p1;
    std::cin >> p1.x >> p1.y;
    points.push_back(p1);

    std::cout << "Entrez les coordonées du deuxième point (x y) : ";
    Point p2;
    std::cin >> p2.x >> p2.y;
    points.push_back(p2);

    int len = length(points[0], points[1]);
    std::cout << "La longueur entre les deux points est : " << len << std::endl;

    return 0;
}