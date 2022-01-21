#include <iostream>
using namespace std;

class Shape{
    virtual int no_of_corners() = 0;
};

class Rectangle : public Shape{
    private:
    static const int corners = 4;

    public:
    int no_of_corners(){
        return corners;
    }
};

class Triangle : public Shape{
    private:
    static const int corners = 3;

    public:
    int no_of_corners(){
        return corners;
    }
};

int main(void){

    Rectangle myRect;
    Triangle myTria;

    cout << myRect.no_of_corners() << endl;
    

    return 0;
}