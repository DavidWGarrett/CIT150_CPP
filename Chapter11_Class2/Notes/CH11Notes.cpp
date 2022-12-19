#include <iostream>
#include <iomanip>

void fill(int** p, int rowSize, int columnSize);
void print(int** p, int rowSize, int columnSize);

using namespace std;
/*
class Animal
{
public:
    void eat() { cout << "I can eat" << endl; }
    void sleep() { cout << "I can sleep" << endl; }
    void setColor(string clr) { color = clr; }
    string getColor() { return color; }
private:
    string color;
protected:
    string type;
    string color;
};
class Dog: public Animal
{
public:
    void bark() { cout << "I can bark" << endl; }
    void setType(string tp) { type = tp; }
    //void setColor(string clr) { color = clr; } //NOT ACCESSIBLE private variable
    void displayInfo(string);
};

void Dog::displayInfo(string c)
{
    cout << "I am a " << Dog::type << endl;
    cout << "My color is " << c << endl;
}
*/

class Base
{
public:
    void print() { cout << "Base function" << endl; }
};

class Derived : public Base
{
public:
    void print() { cout << "Derived Function" << endl; }
};

int pointerPrac()
{
    int x = 27;
    int* p = nullptr;
    //p = &x;

    cout << "Value of x is " << x << endl;
    cout << "Value of p is " << p << endl;
    //cout << "Value of *p is " << *p << endl;

    int* pp;
    int arr[] = { 10, 34, 13, 76, 5, 46 };
    pp = arr;

    for (int i = 0; i < 6; i++)
    {
        cout << *pp << endl;
        pp++;
    }

    int* first;
    int* second;

    first = new int[10];
    second = first;

    int num;
    cout << "enter total num of students: ";
    cin >> num;
    float* ptr;

    ptr = new float[num];
    cout << "Enter gpa of students: " << endl;

    for (int i = 0; i < num; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> *(ptr + i);
    }

    cout << "\nDisplaying GPA of students" << endl;

    for (int i = 0; i < num; i++)
    {
        cout << "Student " << i + 1 << ": " << *(ptr + i) << endl;
    }

    delete[] ptr;

    return 0;
}

int mainp()
//Line 6
{
    //Line 7
    int** board;
    //Line 8
    int rows;
    //Line 9
    int columns;
    //Line 10
    cout << "Line 11: Enter the number of rows "
        << "and columns: ";
    //Line 11
    cin >> rows >> columns;
    //Line 12
    cout << endl;
    //Line 13
    //Create the rows of board
    board = new int* [rows];
    //Line 14
    //Create the columns of board
    for (int row = 0; row < rows; row++)
        //Line 15
        board[row] = new int[columns];
    //Line 16
    //Insert elements into board
    fill(board, rows, columns);
    //Line 17
    cout << "Line 18: Board:" << endl;
    //Line 18
    //Output the elements of board
    print(board, rows, columns);
    //Line 19
    return 0;
    //Line 20
}
//Line 21
void fill(int** p, int rowSize, int columnSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        cout << "Enter " << columnSize << " number(s)"
            << " for row number " << row << ": ";
        for (int col = 0; col < columnSize; col++)
            cin >> p[row][col];
        cout << endl;
    }
}

void print(int** p, int rowSize, int columnSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < columnSize; col++)
            cout << setw(5) << p[row][col];
        cout << endl;
    }
}

void test(int* n1, int* n2)
{
    *n1 = 10;
    *n2 = 11;
}

int main2()
{
    int a = 5;
    int b = 5;

    test(&a, &b);

    cout << "value of a and b: " << a << " - " << b << endl;
    return 0;
}


int main()
{
    main2();
}

