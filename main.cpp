#include <iostream>
#include <vector>
#include "VectorUtil.h"

int main() {
    using namespace std::string_literals;
    system(("chcp "s + std::to_string(65001)).c_str());

    std::cout << "Demonstration of printColor: " << std::endl;
    std::vector<std::string> stringVector = { "hello", "world", "how", "are", "you!!"};
    printColor(stringVector);

    std::cout << std::endl << "Demonstration of slice and printSlice: " << std::endl;
    std::vector<std::vector<int>> doubleVector;
    std::vector<int> vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    doubleVector = slice(vector, 5);
    printSlice(doubleVector);

    std::cout << std::endl << "Demonstration of removeDuplicates: " << std::endl;
    std::vector<int> duplicates = {1, 1, 2, 3, 4, 4 , 5, 1, 3, 2, 10, 6, 7, 2, 1, 4, 5, 6}, noDuplicates;
    noDuplicates = removeDuplicates(duplicates);
    print(noDuplicates);

    std::cout << std::endl << "Demonstration of bubble sort: " << std::endl;
    print(duplicates);
    bubbleSort(duplicates);
    print(duplicates);

    std::cout << std::endl << "Demonstration of equalElements: " << std::endl;
    std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vec2 = {2, 23, 4, 10, 12};
    std::vector<int> equal = equalElements(vec1, vec2);
    print(equal);

    std::vector<Point> vec3 = {Point(0, 9), Point(1, 1), Point(23,0), Point(1, 2), Point(1, 3), Point(10, 10)};
    std::vector<Point> vec4 = {Point(1,2), Point(1, 1), Point(23, 0)};
    std::vector<Point> vec5 = equalElements(vec3, vec4);
    print(vec5);

    std::cout << std::endl << "Demonstration of countIdentical: " << std::endl;
    std::vector<int> vecInt = {1, 1, 2, 3, 3, 3, 5, 6, 7, 8, 1, 1, 2, 2, 3, 5};
    int val = 5;
    std::cout << "Number of times: " + std::to_string(countIdentical(vecInt, val)) << std::endl;
    return 0;
}
