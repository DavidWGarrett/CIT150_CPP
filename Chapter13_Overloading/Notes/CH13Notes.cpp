#include <iostream>
using namespace std;

class Count
{
private:
    int value;
public:
    // constructor to initialize count to 5
    Count() : value(5) {}
    //overload ++ when used as prefix
    void operator ++()
    {
        ++value;
    }
    void display()
    {
        cout << "Count: " << value << endl;
    }
};

class Complex
{
private:
    float real;
    float imag;
public:
    Complex()
    {
        real = 0;
        imag = 0;
    }

    void input()
    {
        cout << "Enter real and imaginary parts respectively: ";
        cin >> real;
        cin >> imag;
    }

    Complex operator + (const Complex& obj)
    {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;

        return temp;
    }

    void output()
    {
        if (imag < 0)
        {
            cout << "\nOutput Complex Number: " << real << imag << "i";
        }
        else
        {
            cout << "\nOutput Complex Number: " << real <<  "+" << imag << "i";
        }
    }
};



class rectangleType
{
public:
    rectangleType() { length = 0.0; width = 0.0; }
    rectangleType(double l, double w) { length = l; width = w; }
    //The functions setDimension, getLength, getWidth, area,
    //perimeter, print, and the constructors are the same as before.
    rectangleType doubleDimensions();
    double area() { return length * width; }
    //Postcondition: length = 2 * length;
    // width = 2 * width;
private:
    double length;
    double width;
};

rectangleType rectangleType::doubleDimensions()
{
    length = 2 * length;
    width = 2 * width;
    return *this;
}

int main()
{
    rectangleType oldYard(20.00, 10.00);
    //Line 7
    rectangleType newYard;

    newYard = oldYard.doubleDimensions();
    //Line 11
    cout << "Line 12: Area of newYard = "
        << newYard.area() << endl;
    cout << "OLD YARD = "
        << oldYard.area() << endl;


    Complex complex1, complex2, result;

    cout << "Enter first complex number:\n";
    complex1.input();
    cout << "Enter second complex number:\n";
    complex2.input();

    result = complex1 + complex2;
    result.output();

    //Count count1;
    //++count1;

    //count1.display();
    //return 0;
}

