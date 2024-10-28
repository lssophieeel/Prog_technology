#include <iostream>

class shape_base {
public:
    virtual shape_base* copy() const = 0;
    virtual void print_details() const = 0;
    virtual ~shape_base() { }
};

class rectangle_shape : public shape_base {
private:
    double width;
    double height;

public:
    rectangle_shape(double w, double h) : width(w), height(h) {}

    shape_base* copy() const override {
        return new rectangle_shape(*this);
    }

    void print_details() const override {
        std::cout << "Rectangle: Width = " << width << ", Height = " << height << std::endl;
    }
};

class circle_shape : public shape_base {
private:
    double radius;

public:
    circle_shape(double r) : radius(r) {}

    shape_base* copy() const override {
        return new circle_shape(*this);
    }

    void print_details() const override {
        std::cout << "Circle: Radius = " << radius << std::endl;
    }
};

int main() {
    circle_shape circlePrototype(3);
    rectangle_shape rectanglePrototype(10, 15);

    shape_base* clonedCircle = circlePrototype.copy();
    shape_base* clonedRectangle = rectanglePrototype.copy();

    clonedCircle->print_details();
    clonedRectangle->print_details();

    delete clonedCircle;
    delete clonedRectangle;

    return 0;
}
