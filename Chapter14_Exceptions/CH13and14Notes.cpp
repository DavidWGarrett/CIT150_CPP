#include <iostream>
#include <exception>

using namespace std;

struct MyException : public exception
{
    const char* what() const throw()
    {
        return "C++ Exception";
    }
};

template <typename T>
T add(T num1, T num2)
{
    return (num1 + num2);
}

template <class G>
class Number
{
private:
    G num;
public:
    Number(G n) : num(n) {}

    G getNum() { return num; }
};

double division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by 0 dum dum";
    }

    return (a / b);
}


int asoif()
{
    int result1;
    double result2;

    result1 = add(2, 3);
    cout << "add 2 and 3 =" << result1 << endl;

    result2 = add(2.2, 3.3);
    cout << "2.2 + 3.3 = " << result2 << endl;

    return 0;
}

int main44()
{
    Number<int> numberInt(7);

    Number<double>numberDouble(7.7);

    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;

    return 0;
}

int main445()
{
    int x = 50;
    int y = 0;

    double z = 0;

    try
    {
        z = division(x, y);
        cout << "Z = " << z;
    }
    catch (const char* msg)
    {
        cerr << msg << endl;
    }

    return 0;
}

int main()
{
    try
    {
        throw MyException();
    }
    catch (MyException &e)
    {
        cout << "MyException is caought" << endl;
        cout << e.what() << endl;
    }
    catch (...)
    {
        //blahblahhhh
    }

    return 0;
}