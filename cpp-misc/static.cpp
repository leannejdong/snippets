using std::cerr;

struct A {
    static const int x = 3;  //after removal of static. the ctor now initializing x 
// instead of y. The y is initialized to 0, because it isn't specified.
    const int y;
};


int main()
{
    A a1{1};  // a1.y is 1
    A a2{2};  // a2.y is 2

    cerr << "a1.y = " << a1.y << "\n";
    cerr << "a2.y = " << a2.y << "\n";
    cerr << "a1.x = " << a1.x << "\n";
    cerr << "a2.x = " << a2.x << "\n";
 }
