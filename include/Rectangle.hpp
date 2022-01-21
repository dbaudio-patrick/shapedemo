#pragma once

#include "Shape.hpp"

class Rectangle : public Shape{
    private:
    static const int corners = 4;

    public:
    int no_of_corners(){
        return corners;
    }
};