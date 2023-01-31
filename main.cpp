#include "Circle.h"

int main() {
    Point p1;

    p1.x = 5;
    p1.y = 3;

    Circle c1(p1, 3);

    c1.CalculateArea();

    return 0;
}
