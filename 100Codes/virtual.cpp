
#include <cmath>
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

    cerr << "n: " << n << "\n";
    //std::vector<Person*> per(n);
    std::vector<std::unique_ptr<Person>> per(n);
    for(int i = 0; i < n; ++i){
        cin >> val;
        if(val == 1) {
            //per[i] = new Professor;
            per[i] = std::make_unique<Professor>();

        } else {
            per[i] = std::make_unique<Student>();
        }
        per[i]->getdata();
    }

    for(int i = 0; i < n; ++i){
        per[i]->putdata();
    } 
    //  for(int i = 0; i < n; ++i){
    //     delete per[i];
    //  }
     

    return 0;

}






//https://godbolt.org/z/YMTTMsT5r
