
// implement callback with lambda, unit test given
#include <cassert>
#include <functional>
#include <iostream>
int Plus(const int a, int(*GetValue)())
{
    return GetValue() + a;
}

bool update_progress_was_called = false;


// An example of a callback function
bool updateProgress(int pct) {
  
   std::cout << pct << "% complete...\n";
   update_progress_was_called = true;
   return(true);
}

// alias 
using FuncPtrBoolInt = bool(*)(int);
using FakeFuncPtr = std::function<bool(int)> ;

// A function that runs for a while
void longOperation(FakeFuncPtr f) {

   for (long l = 0; l < 100000000; l++)
      if (l % 10000000 == 0)
         f(l / 1000000);
}


int main()
{
    longOperation(updateProgress);
    assert(update_progress_was_called);
    std::cout << "update_progress_was_called\n";
    auto value_getter = [](){return 1;};
    int res = Plus(1, value_getter);

    int a;
    auto test = [value = a]()mutable{return value++;};
    int res1 = test();
    return 0;

}

/* error
we are trying to modify a member variable in a const function. It is like
int main::lambda::operator()(const lambda* hidden)
{
  return hidden->value++;
}
The hidden pointer points to a constant lambda object hence the error.*/
