#pragma once

#include "Shape.hpp"

class Triangle : public Shape{
    private:
    static const int corners = 3;

    public:
    int no_of_corners(){
        return corners;
    }
};