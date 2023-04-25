//
// Created by Mir on 11/04/2022.
//

#ifndef TASK0701_POINT_H
#define TASK0701_POINT_H
#include <iostream>

class Point {
private:
    int x, y;
    static int lastX;
    static int lastY;

public:
    Point();
    Point(int x, int y);

    int getX() const;
    int getY() const;

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};


#endif //TASK0601_POINT_H
