#include <iostream>
using std::cout;
class Base{
    int * _ptr;
    int _val;

    public:
    Base(): _ptr{new int(0)}, _val{0}{}
    Base(const Base& rhs){
        _ptr = new int;
        *_ptr = *rhs._ptr;
        _val = rhs._val;
    }
    void setPtr(int ptr) { *_ptr = ptr; }
    void setVal(int val) { _val = val; }
    int getPtr() {return *_ptr; }
    int getVal() {return _val; }
    ~Base()
    {
        delete _ptr;
    }
};

int main(){
    Base b1;
    b1.setPtr(10); b1.setVal(15);
    Base b2 = b1;
    b2.setPtr(50);

    cout << "b1 ptr: " << b1.getPtr() << "\n";
    cout << "b1 val: " << b1.getVal() << "\n";
    cout << "b2 ptr: " << b2.getPtr() << "\n"; // here changing b2 ptr automatically change the b1 ptr
    cout << "b2 val: " << b2.getVal() << "\n";

}

// https://compiler-explorer.com/z/KvTvqvedT
