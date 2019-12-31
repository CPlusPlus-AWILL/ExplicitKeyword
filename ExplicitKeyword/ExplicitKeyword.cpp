#include <iostream>

class Point
{
public:
    Point() :_x(0), _y(0) {}
    Point(int x, int y) :_x(x), _y(y) {}

public:
    int _x;
    int _y;
};

class Size
{
public:
    explicit Size(const Point& pt):width(pt._x), height(pt._y)
    {
        std::cout << "Size construction." << std::endl;
    }

    Size& operator = (const Point& pt)
    {
        width = pt._x;
        height = pt._y;
        std::cout << "Size assignment." << std::endl;

        return *this;
    }

    operator Point()
    {
        std::cout << "Size conversion." << std::endl;
        return Point(width, height);
    }

public:
    int width;
    int height;
};

void function(const Size& sz)
{
    std::cout << "size function." << std::endl;
    return;
}

int main()
{
    // use explicit keyword.
    Point pt;
    Size sz1(pt);
    //Size sz2 = pt;  // error
    sz1 = pt;
    pt = Point(sz1);
    function(sz1);

    //// remove the explicit keyword.
    //Size sz3(pt);
    //Size sz4 = pt;
    //sz2 = pt;
    //pt = Point(sz3);
    //function(pt);
    
    return 0;
}
