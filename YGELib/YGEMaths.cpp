

// YGEMaths.cpp

// Maths functions

// Nick Bofilios 2010


#include "YGEMaths.h"

#include <stdexcept>

using namespace std;

namespace YGELib
{
    double myMathFuncs::Add(double a, double b)
    {
        return a + b;
    }

    double myMathFuncs::Subtract(double a, double b)
    {
        return a - b;
    }

    double myMathFuncs::Multiply(double a, double b)
    {
        return a * b;
    }

    double myMathFuncs::Divide(double a, double b)
    {
        if (b == 0)
        {
            throw new invalid_argument("b cannot be zero!");
        }

        return a / b;
    }
}
