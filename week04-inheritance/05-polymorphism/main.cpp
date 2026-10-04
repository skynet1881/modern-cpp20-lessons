#include <iomanip>
#include <iostream>
#include <string_view>
#include <vector>

class Shape
{
public:
    virtual ~Shape() = default;

    virtual std::string_view name() const = 0;

    virtual double area() const = 0;
};

class Circle : public Shape
{
public:
    explicit Circle(double radius)
        : radius_{radius}
    {
    }

    std::string_view name() const override
    {
        return "Circle";
    }

    double area() const override
    {
        return 3.14
             * radius_
             * radius_;
    }

private:
    double radius_;
};

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height)
        : width_{width},
          height_{height}
    {
    }

    std::string_view name() const override
    {
        return "Rectangle";
    }

    double area() const override
    {
        return width_ * height_;
    }

private:
    double width_;
    double height_;
};

class Triangle : public Shape
{
public:
    Triangle(double base, double height)
        : base_{base},
          height_{height}
    {
    }

    std::string_view name() const override
    {
        return "Triangle";
    }

    double area() const override
    {
        return 0.5 * base_ * height_;
    }

private:
    double base_;
    double height_;
};

void printShapes(
    const std::vector<const Shape*>& shapes)
{
    for (const Shape* shape : shapes)
    {
        std::cout
            << shape->name()
            << ": "
            << shape->area()
            << '\n';
    }
}

double totalArea(
    const std::vector<const Shape*>& shapes)
{
    double total{0.0};

    for (const Shape* shape : shapes)
    {
        total += shape->area();
    }

    return total;
}

int main()
{
    std::cout
        << std::fixed
        << std::setprecision(2);

    Circle circle{2.0};
    Rectangle rectangle{3.0, 4.0};
    Triangle triangle{5.0, 2.0};

    std::vector<const Shape*> shapes{
        &circle,
        &rectangle,
        &triangle
    };

    printShapes(shapes);

    std::cout
        << "----------------\n"
        << "Total area: "
        << totalArea(shapes)
        << '\n';

    return 0;
}