//
// Created by anzef on 17. 04. 2023.
//

#ifndef NALOGA0701_VECTORUTIL_H
#define NALOGA0701_VECTORUTIL_H


#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "ColorCode.h"
#include "PrintUtility.h"
#include "Point.h"

template<typename T>
void fillDefault(std::vector<T> &vector, int n){
    for(int i = 0; i < n; i++){
        vector.push_back(T());
    }
}

template<>
void fillDefault(std::vector<int> &vector, int n){
    std::srand(std::time(nullptr));
    for(int i = 0; i < n; i++){
        vector.push_back(std::rand() % 100);
    }
}

template<typename T>
void print(std::vector<T> vector){
    for(T i : vector){
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

template<typename T>
std::vector<T> reverse(std::vector<T> &vector){
    std::vector<T> reversedVector;
    for(int i = vector.size(); i > 0; i--){
        reversedVector.push_back(vector[i-1]);
    }
    return reversedVector;
}

template<typename T>
std::vector<T> mergeVectors(std::vector<std::vector<T>> &vector){
    std::vector<T> mergedVector;
    for(std::vector<T> i : vector){
        mergedVector.reserve(mergedVector.size() + i.size());
        mergedVector.insert(mergedVector.end(), i.begin(), i.end());
    }
    return mergedVector;
}

template<typename T>
void printColor(std::vector<T> &vector){
    for(T i : vector){
        PrintUtility::print(ColorCode::Green, i);
        std::cout << std::endl;
    }
}

template<typename T>
std::vector<std::vector<T>> slice(std::vector<T> vector, int n){
    int index = 0, allElements = vector.size(), reserveSpace;
    if(vector.size() % n == 0){
        reserveSpace = vector.size() / n;
    } else{
        reserveSpace = vector.size() / n + 1;
    }
    std::vector<std::vector<T>> returnVector(reserveSpace);

    for(int i = 0; i < vector.size(); i++){
        for(int j = 0; j < n; j++){
            if(allElements == 0){
                break;
            }
            returnVector[i].push_back(vector[index]);
            index++;
            allElements--;
        }
    }
    return returnVector;
}

template<typename T>
std::vector<T> removeDuplicates(std::vector<T> vector){
    std::vector<T> noDuplicates;

    for(T v : vector){
        bool condition = true;
        for(T o : noDuplicates){
            if(o == v){
                condition = false;
                break;
            }
        }
        if(condition) {
            noDuplicates.push_back(v);
        }
    }
    return noDuplicates;
}

template<typename T>
void printSlice(std::vector<std::vector<T>> &vector){
    for(const std::vector<int>& i : vector){
        for(int j : i){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
void bubbleSort(std::vector<T> &vector){
    for (int i = 0; i < vector.size() - 1; i++) {
        for (int j = 0; j < vector.size() - i - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                std::swap(vector[j], vector[j + 1]);
            }
        }
    }
}

template<typename T>
int countIdentical(std::vector<T> &vector, T element){
    int counter = 0;
    for(T v : vector){
        if(v == element){
            counter++;
        }
    }
    return counter;
}

template<typename T>
std::vector<T> equalElements(std::vector<T> &vec1, std::vector<T> &vec2){
    std::vector<T> allEquals;
    for(T e1 : vec1){
        for(T e2 : vec2){
            if(e1 == e2){
                allEquals.push_back(e1);
            }
        }
    }
    return allEquals;
}

template<>
std::vector<Point> equalElements(std::vector<Point> &vec1, std::vector<Point> &vec2){
    std::vector<Point> allEquals;
    for(Point e1 : vec1){
        for(Point e2 : vec2){
            if(e1.getX() == e2.getX() && e1.getY() == e2.getY()){
                allEquals.push_back(e1);
            }
        }
    }
    return allEquals;
}


#endif //NALOGA0701_VECTORUTIL_H
