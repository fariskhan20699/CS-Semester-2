
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// ---------------------------------------------
// ABSTRACT BASE CLASS (Abstraction)
// ---------------------------------------------
class Shape {
protected:
    string color;

public:
    Shape(string c = "Red") : color(c) {}

    // Pure virtual functions — must be overridden (Abstraction)
    virtual double area()      const = 0;
    virtual double perimeter() const = 0;
    virtual string name()      const = 0;

    // Virtual destructor
    virtual ~Shape() {}

    // Friend class declaration
    friend class ShapePrinter;
};


// ---------------------------------------------
// DERIVED CLASS 1: Circle
// ---------------------------------------------
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r, string c = "Red") : Shape(c), radius(r) {}

    double area()      const override { return M_PI * radius * radius; }
    double perimeter() const override { return 2 * M_PI * radius; }
    string name()      const override { return "Circle"; }

    friend class ShapePrinter; // Friend class
};


// ---------------------------------------------
// DERIVED CLASS 2: Rectangle
// ---------------------------------------------
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w, string c = "Blue") : Shape(c), length(l), width(w) {}

    double area()      const override { return length * width; }
    double perimeter() const override { return 2 * (length + width); }
    string name()      const override { return "Rectangle"; }

    friend class ShapePrinter; // Friend class
};


// ---------------------------------------------
// DERIVED CLASS 3: Triangle
// ---------------------------------------------
class Triangle : public Shape {
private:
    double a, b, c; // three sides

public:
    Triangle(double a, double b, double c, string col = "Green")
        : Shape(col), a(a), b(b), c(c) {}

    double area() const override {
        double s = (a + b + c) / 2.0; // Heron's formula
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double perimeter() const override { return a + b + c; }
    string name()      const override { return "Triangle"; }

    friend class ShapePrinter; // Friend class
};


// ---------------------------------------------
// FRIEND CLASS: ShapePrinter
// Accesses private/protected members directly
// ---------------------------------------------
class ShapePrinter {
public:
    // Polymorphism: Shape* pointer calls correct overridden function
    void printDetails(const Shape* s) const {
        cout << "-------------------------------" << endl;
        cout << "Shape     : " << s->name()      << endl;
        cout << "Color     : " << s->color       << endl; // accessing protected via friend
        cout << "Area      : " << s->area()      << endl;
        cout << "Perimeter : " << s->perimeter() << endl;
    }

    // Friend accesses private members of Circle directly
    void printCircleRadius(const Circle* c) const {
        cout << "Circle Radius (private): " << c->radius << endl;
    }

    // Friend accesses private members of Rectangle directly
    void printRectDimensions(const Rectangle* r) const {
        cout << "Rectangle Length x Width (private): "
             << r->length << " x " << r->width << endl;
    }
};


// ---------------------------------------------
// MAIN
// ---------------------------------------------
int main() {
    cout << "===============================" << endl;
    cout << "   OOP Shape Calculator (C++)  " << endl;
    cout << "===============================" << endl;

    // Shape pointers array — Polymorphism in action
    Shape* shapes[3];
    shapes[0] = new Circle(7.0, "Red");
    shapes[1] = new Rectangle(5.0, 3.0, "Blue");
    shapes[2] = new Triangle(3.0, 4.0, 5.0, "Green");

    ShapePrinter printer;

    // Polymorphism: same function call, different behavior
    for (int i = 0; i < 3; i++) {
        printer.printDetails(shapes[i]);
    }

    cout << "\n--- Friend Class: Private Access ---" << endl;
    printer.printCircleRadius(static_cast<Circle*>(shapes[0]));
    printer.printRectDimensions(static_cast<Rectangle*>(shapes[1]));

    cout << "-------------------------------" << endl;

    // Clean up
    for (int i = 0; i < 3; i++) delete shapes[i];

    return 0;
}
