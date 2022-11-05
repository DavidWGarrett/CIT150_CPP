// David Garrett
// Chapter 5 Lab 2
// 10-4-2022

#include <iostream>
using namespace std;

int main()
{
    int i, sum = 0; 

    /* 
    * i is initialized to 1 and will increase by 1 after each iteration of
    * the for loop.The loop will iterate twenty - five times or when i reaches
    * 26 since i <= 25 will evaluate to false.
    * 
    * At beginning of loop, the i value is added to the sum variable. The sum variable
    * will have the value of all the i values from all iterations
    * 
    * A message is printed out to user that will tell user what the total sum of all
    * the numbers between 1 and i
    */ 

    for (i = 1; i <= 25; i++)
    {
        sum += i;
        cout << "The sum of 1 through  " << i << " is " << sum << endl;
    }
}