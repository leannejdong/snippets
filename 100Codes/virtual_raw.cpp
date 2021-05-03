/*
This problem is to get you familiar with virtual functions. Create three classes Person, Professor and Student. 
The class Person should have data members name and age. 
The classes Professor and Student should inherit from the class Person.
The class Professor should have two integer members: publications and cur_id. 
There will be two member functions: getdata and putdata. 
The function getdata should get the input from the user: the name, age and publications of the professor. 
The function putdata should print the name, age, publications and the cur_id of the professor.
The class Student should have two data members: marks, which is an array of size  and cur_id. 
It has two member functions: getdata and putdata. 
The function getdata should get the input from the user: the name, age, and the marks of the student in  subjects. 
The function putdata should print the name, age, sum of the marks and the cur_id of the student.
For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from .

Solve this problem using virtual functions, constructors and static variables. You can create more data members if you want.

Note: Expand the main function to look at how the input is being handled.
*/
//#include <cmath>
#include <cstdio>
#include <array>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <memory>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::array;

class Person {
    protected:
    string name;
    int age;

    public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
    virtual ~Person() {cout << "clean up" << "\n"; };

};

class Professor : public Person{
    int publications, cur_id;
    static int seq_id;
// the variable is gonna be kept in memory during the life time of our program
    public:
    Professor(){
        seq_id++;
        cur_id = seq_id;
    }
    void getdata() override{
        cin >> name >> age >> publications;
    }
    void putdata() override{
        cout << name << " " << age << " " << publications << " " << seq_id << "\n";
    }
};
class Student: public Person{
    array<int, 6> marks;
    //int marks[6];
    int cur_id;
    static int seq_id;

    public:
    Student(){
        seq_id++;
        cur_id = seq_id;
    }
    virtual void getdata() override{
        cin >> name >> age;
        for(int &m : marks) cin >> m;
      // for(int i=0; i<6; i++) cin >> marks[i];
    }
    virtual void putdata() override{
        int mark_total = 0;
        for(int &m : marks) mark_total += m;
       // for(int i=0; i<6; i++) mark_total += marks[i];
        cout << name << " " << age << " " << mark_total << " " << seq_id << "\n";
    }
};
int Professor::seq_id = 0;
int Student::seq_id = 0;

int main()
{

    int n; int val;
    cin >> n;

    //cerr << "n: " << n << "\n";
    std::vector<Person*> per(n);
    //Person *per[n];
    for(int i = 0; i < n; ++i){
        cin >> val;
        if(val == 1) {
            per[i] = new Professor;
        } else {
            per[i] = new Student;
        }
        per[i]->getdata();
    }

    for(int i = 0; i < n; ++i){
        per[i]->putdata();
    } 
     for(int i = 0; i < n; ++i){
        delete per[i];
     }
     

    return 0;

}






//https://godbolt.org/z/qsz68s8bW
