#include <iomanip>
#include <iostream>
#include <string_view>

class Shape
{
public:
    virtual ~Shape() = default;

    virtual double area() const = 0;

    virtual std::string_view name() const = 0;

    void printInfo() const
    {
        std::cout
            << name()
            << " area = "
            << area()
            << '\n';
    }
};

class Circle : public Shape
{
public:
    explicit Circle(double radius)
        : radius_{radius}
    {
    }

    double area() const override
    {
        return 3.14
             * radius_
             * radius_;
    }

    std::string_view name() const override
    {
        return "Circle";
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

    double area() const override
    {
        return width_ * height_;
    }

    std::string_view name() const override
    {
        return "Rectangle";
    }

private:
    double width_;
    double height_;
};

int main()
{
    std::cout
        << std::fixed
        << std::setprecision(2);

    Circle circle{2.0};
    Rectangle rectangle{3.0, 4.0};

    circle.printInfo();
    rectangle.printInfo();

    return 0;
}