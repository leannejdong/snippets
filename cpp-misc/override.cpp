#include<iostream>
#include<memory>
using namespace std;

//Parent class or super class or base class
class Animal{
public:
   virtual void animalSound(){
      cout<<"This is a generic Function";
   }
};
//child class or sub class or derived class
class Dog : public Animal{
public:
   void animalSound(int a) {//without override specifier the compiler won't
     // catch the mismatch
      cout<<"Woof-virtual";
   }
};
int main(){
//    Animal *obj;
//    obj = new Dog();
//    obj->animalSound();

   std::unique_ptr<Animal> obj = make_unique<Dog>(); //make sure you use the derived pointer to see the difference
   obj->animalSound();
   return 0;
}

