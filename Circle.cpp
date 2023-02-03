/**
 * @file Circle.cpp
 * @author Bill Black (you@domain.com)
 * @brief Circle class implementation for CSCI 3010
 * @version 1.0
 * @date 2023-02-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Circle.h"

/**
 * @brief Calculate n-factorial
 * 
 * Factorial originally didn't account for 0! == 1
 * 
 * @param number n
 * @return unsigned int factorial
 */
unsigned int Factorial(unsigned int number)
{
    unsigned int fac = 1;
    if (number == 0)
    {
        return 1;
    }

    for (unsigned int i = number; i > 0; --i)
    {
        fac *= i;
    }

    return fac;
}

/**
 * @brief Construct a new Circle:: Circle object with check for radius >= 0
 * 
 * @param p 
 * @param rad 
 */
Circle::Circle(Point p, int rad) : center_(p), radius_(rad)
{
    if (radius_ < 0)
    {
        radius_ = 0;
    }
}

/**
 * @brief Calculates Euclidean distances between centers to check overlap
 * 
 * Didn't originally calculate correctly
 * 
 * @param other Another Circle object
 * @return true if distance between centers is less than or equal
 * to the sum of their radii
 * @return false otherwise
 */
bool Circle::Overlaps(Circle &other)
{
    Point other_center = other.get_center();
    int other_radius = other.get_radius();

    int dx = this->center_.x - other_center.x;
    int dy = this->center_.y - other_center.y;

    double dist = sqrt(dx * dx + dy * dy);

    return (dist <= (radius_ + other_radius));


}

/**
 * @brief Calculates circle area
 * 
 * @return int Truncated area of circle
 */
int Circle::CalculateArea()
{
    return (radius_ * radius_ * M_PI);
}

/**
 * @brief increase circle radius by 1
 * 
 */
void Circle::Expand()
{
    radius_++;
}

/**
 * @brief decrease circle radius by 1 to a minimum of 0
 * 
 * Originally allowed for r < 0
 * 
 */
void Circle::Shrink()
{
    if (--radius_ < 0)
    {
        radius_ = 0;
    }
}
