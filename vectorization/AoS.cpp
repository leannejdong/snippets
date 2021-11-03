#include <array>
#include <iostream>
//Array of Struc (AoS)
struct team{
    int roll_no;
    char grade;
    float marks;
};

void display(std::array<team, 3> record)
{

    for (int i{0}; i < 3; ++i){
        std::cout << "Roll number: " << record[i].roll_no  << "\n";
        std::cout << "Grade: " << record[i].grade  << "\n";
        std::cout << "Average marks: " << record[i].marks  << "\n";

    }
}

int main()
{
    std::array<team, 3> record = {{{ 1, 'A', 89.5f },
            { 2, 'C', 67.5f },
            { 3, 'B', 70.5f }}};
    display(record);
    return 0;
}


