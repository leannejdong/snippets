#include <variant>
#include <vector>
#include <iostream>
//when yoweu want a variable that can be one of a few things
//This make std::variant appealing
using std::ostream;
using Real = double;

struct Point {
    Real x,y;

    friend ostream& operator<<(ostream &s, const Point &p)
    {
        return s << "{" << p.x << "," << p.y << "}";
    }
};

struct Circle {
    Point center;
    Real radius;

    friend ostream& operator<<(ostream &s, const Circle &x)
    {
        return s << "Circle(center=" << x.center << ", radius=" << x.radius << ")";
    }
};

struct Square {
    Point center;
    Real width;

    friend ostream& operator<<(ostream &s, const Square &x)
    {
        return s << "Square(center=" << x.center << ", width=" << x.width << ")";
    }
};

struct Triangle {
    Point v1;
    Point v2;
    Point v3;

    friend ostream& operator<<(ostream &s, const Triangle &x)
    {
        return s << "Triangle(" << x.v1 << ", " << x.v2 << ", " << x.v3 << ")";
    }
};


int main()
{
    using Shape = std::variant<Circle,Square,Triangle>;

    std::vector<Shape> shapes = {
        Circle{{1,2},5},
        Square{{3,5},7},
        Triangle{{0,0},{-1,2},{3,7}}       
    };

    auto print = [](auto x){ std::cout << x << "\n"; };

    for (auto &shape : shapes) {
        std::visit(print, shape);
    };
}
