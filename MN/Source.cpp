#include <iostream>

using namespace std;

class Square 
{
protected:
    double side; 
public:
    Square(double s) : side(s) {}
    double getSide() const { return side; }
    double area() const { return side * side; }
};

class Circle 
{
protected:
    double radius; 
public:
    Circle(double r) : radius(r) {}
    double getRadius() const { return radius; }
    double area() const { return 3.14 * radius * radius; }
};

class CircleInSquare : public Square, public Circle 
{
public:
    CircleInSquare(double s) : Square(s), Circle(s / 2) {}
    double remainingArea() const 
    {
        return Square::area() - Circle::area(); 
    }

    double area() const 
    {
        return Square::area() + Circle::area(); 
    }
};

int main() 
{
    double sideLength;
    cout << "Enter the side length of the square: ";
    cin >> sideLength;

    CircleInSquare circleInSquare(sideLength);
    cout << "Area of the square: " << circleInSquare.Square::area() << endl;
    cout << "Area of the circle: " << circleInSquare.Circle::area() << endl;
    cout << "Remaining area inside the square: " << circleInSquare.remainingArea() << endl;

    return 0;
}
