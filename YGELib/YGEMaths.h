
// YGEMaths.h

// Header file 

//Created by Nick Bofilios 2010



namespace YGELib
{

	//!  myMathFuncs class
    /*!
        Generic math functions
     */

    class myMathFuncs
    {
    public:
        // Returns a + b
       static double Add(double a, double b);
	 
        // Returns a - b
       static double Subtract(double a, double b);

        // Returns a * b
       static double Multiply(double a, double b);

        // Returns a / b
        // Throws DivideByZeroException if b is 0
       static double Divide(double a, double b);
    };


}
