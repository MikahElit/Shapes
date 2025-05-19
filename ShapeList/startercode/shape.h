//  @author Muhammad Hakim
//  @date CS 251, Spring 2023.
//  @brief Project 4 - Shape List, University of Illinois Chicago
//  @description CanvasList class that maintains a linked list of shapes to be drawn to the screen.
//  The shapes include Circle, RightTriangle, and Rectangle classes, which are derived from the base Shape class. 

#pragma once
using namespace std;

class Shape
{
    protected:
        int x;
        int y;

public:
    // Default constructor
    Shape();

    // Constructor with parameters
    Shape(int x, int y);

    // Destructor
    virtual ~Shape();

    // Virtual function to create a copy of a shape
    virtual Shape* copy();

    // Getter functions for x and y coordinates
    int getX() const;
    int getY() const;

    // Setter functions for x and y coordinates
    void setX(int);
    void setY(int);

    // Virtual function to print the shape information
    virtual void printShape() const;
};
Shape::Shape() {
    x = 0;
    y = 0;
}

Shape::Shape(int x, int y) : x(x), y(y) {}


Shape::~Shape() {
    // Do nothing for now
}

Shape* Shape::copy() {
    return new Shape(x, y);
}

int Shape::getX() const {
    return x;
}

int Shape::getY() const {
    return y;
}

void Shape::setX(int x) {
    this->x = x;
}

void Shape::setY(int y) {
    this->y = y;
}

void Shape::printShape() const {
    cout << "It's a Shape at x: " << x << ", y: " << y << endl;
}

class Circle : public Shape 
{
    private:
        int radius;

public:
    // Default constructor
    Circle();

    // Constructor with radius parameter
    Circle(int r);

    // Constructor with x, y, and radius parameters
    Circle(int x, int y, int r);

    // Destructor
    virtual ~Circle();

    // Virtual function to create a copy of a circle
    virtual Circle* copy();

    // Getter function for radius
    int getRadius() const;

    // Setter function for radius
    void setRadius(int);

    // Virtual function to print the circle information
    virtual void printShape() const;
};
// Default constructor
Circle::Circle() : Shape(), radius(0) {}

// Constructor with radius
Circle::Circle(int r) : Shape(), radius(r) {}

// Constructor with coordinates and radius
Circle::Circle(int x, int y, int r) : Shape(x, y), radius(r) {}

// Destructor
Circle::~Circle() {}

// Returns the radius of the circle
int Circle::getRadius() const {
    return radius;
}

// Sets the radius of the circle
void Circle::setRadius(int r) {
    radius = r;
}

// Creates a copy of the circle object
Circle* Circle::copy() {
    return new Circle(*this);
}

// Prints the properties of the circle object
void Circle::printShape() const {
    cout << "It's a Circle at x: " << getX() << ", y: " << getY() << ", radius: " << radius << endl;
}



class Rectangle : public Shape 
{
    private:
        int width;
        int height;

public:
    // Default constructor
    Rectangle();

    // Constructor with width and height parameters
    Rectangle(int w, int h);

    // Constructor with x, y, width, and height parameters
    Rectangle(int x, int y, int w, int h);

    // Destructor
    virtual ~Rectangle();

    // Virtual function to create a copy of a rectangle
    virtual Rectangle* copy();

    // Getter functions for width and height
    int getWidth() const;
    int getHeight() const;

    // Setter functions for width and height
    void setWidth(int);
    void setHeight(int);

    // Virtual function to print the rectangle information
    virtual void printShape() const;
};

Rectangle::Rectangle() : width(0), height(0) {}

Rectangle::Rectangle(int w, int h) : width(w), height(h) {}

Rectangle::Rectangle(int x, int y, int w, int h) : Shape(x, y), width(w), height(h) {}

Rectangle::~Rectangle() {}

class Rectangle* Rectangle::copy() {
    return new Rectangle(*this);
}


int Rectangle::getWidth() const {
    return width;
}

int Rectangle::getHeight() const {
    return height;
}

void Rectangle::setWidth(int w) {
    width = w;
}

void Rectangle::setHeight(int h) {
    height = h;
}

void Rectangle::printShape() const {
    cout << "It's a Rectangle at x: " << getX() << ", y: " << getY() << ", with width: " << width << " and height: " << height << endl;
}


class RightTriangle : public Shape 
{
    private:
        int base;
        int height;

public:
    RightTriangle(); // default constructor
    RightTriangle(int b, int h); // constructor with base and height as arguments
    RightTriangle(int x, int y, int b, int h); // constructor with x, y, base and height as arguments

    virtual ~RightTriangle(); // destructor
    virtual RightTriangle* copy(); // virtual function to create a copy of the right triangle object

    int getBase() const; // function to get the base of the right triangle
    int getHeight() const; // function to get the height of the right triangle
    void setBase(int); // function to set the base of the right triangle
    void setHeight(int); // function to set the height of the right triangle

    virtual void printShape() const; // virtual function to print the details of the right triangle

};

RightTriangle::RightTriangle() : base(0), height(0)
{
}

RightTriangle::RightTriangle(int b, int h) : base(b), height(h)
{
}

RightTriangle::RightTriangle(int x, int y, int b, int h) : Shape(x, y), base(b), height(h)
{
}

RightTriangle::~RightTriangle()
{
}

RightTriangle* RightTriangle::copy()
{
    return new RightTriangle(*this);
}

int RightTriangle::getBase() const
{
    return base;
}

int RightTriangle::getHeight() const
{
    return height;
}

void RightTriangle::setBase(int b)
{
    base = b;
}

void RightTriangle::setHeight(int h)
{
    height = h;
}

void RightTriangle::printShape() const
{
    cout << "It's a Right Triangle at x: " << getX() << ", y: " << getY() << " with base: " << base << " and height: " << height << endl;
}
