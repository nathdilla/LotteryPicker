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

-Nathan Dilla 9/19/21
*/

#include <iostream>
#include <ctime>
#include<cstdlib>
#include <algorithm>
using namespace std;

void randomize(int* arr, int size, int index, int limit) // randomizing function
{
    while (true) //infinite loop search for unique, random number
    {
        arr[index] = rand() % limit;
        for (int j = 0; j < size; j++)
        {
            if (arr[index] == arr[j]) //if similar to another number, loop back
            {
                continue;
            }
        }
        break; //assume no similatiy, break loop
    }
    
}

int* lottery(int* arr, int size)
{
    for (int i = 0; i < size; i++) //loop through each cel in array
    {
        if (i == size - 1) //if final index (power ball) call randomize limit 1-26
        {
            randomize(arr, size, i, 27);
        }
        else
        {
            randomize(arr, size, i, 70); //call randomize for other 5 numbers
        }
        
    }
    return arr;
}

void printArray(const int* list, int size) //prints array
{
    for (int i = 0; i < size; i++)
        std::cout << list[i] << " ";
}

int main()
{
    srand(time(0)); //generate random seed from unix time
    string response;
    while (true) //infinite loop asking user
    {
        std::cout << "\n Would you like to generate a lottery? (Y/N)" << endl;
        std::cin >> response; // store answer from prompt
        if (response == "Y") 
        {
            int list[6]; //declare new array
            int* ptr = lottery(list, 6); //create poiner from returned randomized lottery numbers
            sort(ptr, ptr + 6); //sort to ascending order
            printArray(ptr, 6); //print array
        }
        else
        {
            cout << "Goodbye";
            break; //break loop from answering no.
        }
    }
    return 0;
}