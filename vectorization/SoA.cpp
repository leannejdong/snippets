#include <array>
#include <iostream>
//struct of array (SoA)
struct candidate{
    int roll_no;
    char grade;
    std::array<float, 4> marks;
};

void display(struct candidate a1)
{
    std::cout << "Roll number : " << a1.roll_no << "\n";
    std::cout << "Grade : " << a1.grade << "\n";
    std::cout << "Marks secured: \n";

    for (int i{0}; i < a1.marks.size(); ++i){
        std::cout << "Subject" << i + 1 << " : " << a1.marks[i] << "\n";
    }
}

int main()
{
    struct candidate A{1, 'A', {98.5, 77, 89, 79.5}};
    display(A);
    return 0;
}


