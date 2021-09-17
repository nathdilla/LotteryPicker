// LotteryPicker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Power Ball selects 5 numbers in the range 1-69, inclusive, and one number in the range 1-26, inclusive, as the power ball.
The 5 numbers cannot have any repeat numbers.  Once the 5 numbers are selected, they are displayed in ascending order.

Create a class that that generates a lottery number picker.
Your class will have a method that must store all 6 numbers in an array and return an array. 
The method cannot be void. Your program should ask the user how many lottery numbers 
they would like to see and offer a chance to generate more.
To display the numbers, output the 5 main numbers and the power ball number as shown in the "Lottery Picker Sample Run."
*/

#include <iostream>

int ballNumbers[5];

int main()
{
    

    std::cout << "Hello World!\n";

 
}

int getLotteryNumbers(int numbers, int size)
{
    for (int i = 0; i < size; i++)
    {
        checkForRecurringNumbers(i, size);
    }
    return 0;
}

void checkForRecurringNumbers(int index, int size)
{
    ballNumbers[index] = rand();
    for (int j = 0; j < size; j++)
    {
        if (ballNumbers[index] == ballNumbers[j])
        {
            checkForRecurringNumbers(index, size);
        }
    }
}

//for loop
//while loop
//generate first number
//check if number equals any of the current numbers
//if yes, loop back
//if not, break loop