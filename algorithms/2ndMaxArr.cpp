#include <array>
#include <algorithm>
#include <iostream>

/*
Write a C++ function to find the second largest element in an array of integers. The function 
should take in the following parameters:
An integer array
An integer representing the size of the array
The function should return an integer representing the 
second largest element in the array. If the array has less than two elements, the function should return -1.
*/
constexpr int N=5;
constexpr int M=4;

int findSecondLargest0(int arr[], int size) {
    int largest = arr[0], secondLargest = -1;
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] != largest && (secondLargest == -1 || arr[i] > secondLargest)) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}
int findSecondLargest1(std::array<int, N> arr) {
    int largest = arr[0], secondLargest = -1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] != largest && (secondLargest == -1 || arr[i] > secondLargest)) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int findSecondLargest2(std::array<int, M> arr) {
    auto maxIt = std::max_element(arr.begin(), arr.end());
    auto secondMaxIt = std::max_element(arr.begin(), maxIt);
    return (secondMaxIt != maxIt) ? *secondMaxIt : -1;
}

int main() {
    //std::array<int, 6> arr1{ { 2, 3, 6, 6, 8, 9 } };
    int arr1[] = { 2, 3, 6, 6, 8, 9 } ;
    int size1 = sizeof(arr1) / sizeof(*arr1);

    std::array<int, 5> arr2{ { 9, 9, 9, 9, 9 } };
    std::array<int, 4> arr3{ { 1, 2, 3, 4 } };
    std::array<int, 1> arr4{ { 1 } };

    std::cout << findSecondLargest0(arr1, size1) << std::endl; // Expected output: 8
    std::cout << findSecondLargest1(arr2) << std::endl; // Expected output: -1
    std::cout << findSecondLargest2(arr3) << std::endl; // Expected output: 3

    return 0;
}


/*
calculate the sum of two matrices. The function should take in the following parameters:

Two integer matrices, each represented as a two-dimensional integer array
Two integer values representing the number of rows and columns in each matrix
The function should return a two-dimensional integer array representing the sum of the two matrices. If the matrices have different sizes, the function should return an empty matrix.
*/

/*
implement a binary search algorithm. The program should take in the following parameters:
An integer array, sorted in ascending order
An integer representing the size of the array
An integer value to be searched
The program should return an integer representing the index of the searched value in the array. If the value is not found in the array, the program should return -1.

int binarySearch(int arr[], int size, int value);

*/



