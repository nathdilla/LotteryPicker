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
#include <ctime>
#include<cstdlib>

int* lottery(int* arr, int size)
{
    /* Some operations on arr[] */
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            for (int j = 0; j < size; j++)
            {
                if (arr[i] == arr[j])
                {
                    arr[i] = rand() % 27;
                }
            }
        }
        else
        {
            for (int j = 0; j < size; j++)
            {
                if (arr[i] == arr[j])
                {
                    arr[i] = rand() % 70;
                }
            }
        }
        
    }


    return arr;
}

void printArray(const int* list, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << list[i] << " ";
}

int main()
{
    srand(time(0));
    int list[6];
    int* ptr = lottery(list, 6);
    printArray(ptr, 6);
    
    
       

    return 0;
}



//for loop
//while loop
//generate first number
//check if number equals any of the current numbers
//if yes, loop back
//if not, break loop