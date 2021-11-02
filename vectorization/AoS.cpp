#include <array>
#include <iostream>
//Array of Struc (AoS)
struct team{
    int roll_no;
    char grade;
    float marks;
};

void display(struct team team_record[3])
{

    for (int i{0}; i < 3; ++i){
        std::cout << "Roll number: " << team_record[i].roll_no  << "\n";
        std::cout << "Grade: " << team_record[i].grade  << "\n";
        std::cout << "Average marks: " << team_record[i].marks  << "\n";

    }
}

int main()
{
    struct team team_record[3]
        = { { 1, 'A', 89.5f },
            { 2, 'C', 67.5f },
            { 3, 'B', 70.5f } };
    display(team_record);
    return 0;
}


