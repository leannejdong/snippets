#include <vector>

using std::vector;


struct Shape {
   virtual void draw() = 0;
};

struct Rectangle : Shape {
   void draw() override {}
};

struct Circle : Shape {
   void draw() override {}
};


struct Shapes {
    vector<Rectangle *> rectangles;
    vector<Circle *> circles;
};

static void drawAllSlow(const vector<Shape *> &shapes)
{
    for (Shape *sp : shapes) {
        sp->draw();
    }
}

static void drawAllFast(const Shapes &shapes)
{
    for (Rectangle *sp : shapes.rectangles) {
        sp->draw();
    }

    for (Circle *sp : shapes.circles) {
        sp->draw();
    }
}

static void slowExample()
{
    Rectangle r1;
    Rectangle r2;
    Rectangle r3;
    Circle c1;
    Circle c2;
    Circle c3;
    vector<Shape *> shapes;
    shapes.push_back(&r1);
    shapes.push_back(&c1);
    shapes.push_back(&r2);
    shapes.push_back(&c2);
    shapes.push_back(&r3);
    shapes.push_back(&c3);
    drawAllSlow(shapes);
}


static void fastExample()
{
    Shapes shapes;
    Rectangle r1;
    Rectangle r2;
    Rectangle r3;
    Circle c1;
    Circle c2;
    Circle c3;
    shapes.rectangles.push_back(&r1);
    shapes.circles.push_back(&c1);
    shapes.rectangles.push_back(&r2);
    shapes.circles.push_back(&c2);
    shapes.rectangles.push_back(&r3);
    shapes.circles.push_back(&c3);
    drawAllFast(shapes);
}


int main()
{
    slowExample();
    fastExample();
}
/*
If we have a container of pointers to a larger number of objects of different type,
then we can break this up into multiple containers, each for a single type.

It would be best to contrast the slow and fast version.

The "slow" version needed to be using virtual function calls that the compiler was unlikely to devirtualize
The "fast" version needed to avoid virtual function calls.

*/
