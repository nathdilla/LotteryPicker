//
//  main.cpp
//  LotteryPicker
//
//  Created by Nathan Dilla on 9/25/21.
//

// insert code here...
/*
 Power Ball selects 5 numbers in the range 1-69, inclusive, and one number in the range 1-26, inclusive, as the power ball. The 5 numbers cannot have any repeat numbers.  Once the 5 numbers are selected, they are displayed in ascending order.

 Create a class that that generates a lottery number picker. Your class will have a method that must store all 6 numbers in an array and return an array.  The method cannot be void. Your program should ask the user how many lottery numbers they would like to see and offer a chance to generate more. To display the numbers, output the 5 main numbers and the power ball number as shown in the "Lottery Picker Sample Run."
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

int getRandomNumber(int * array, int limit, int size)
{
    int randomNumber = rand() % limit;
    for (int i = 0; i < size; i++)
    {
        if(randomNumber == array[i])
        {
            getRandomNumber(array, limit, size);
        }
    }
    return randomNumber;
}

int * getNumbers()
{
    static int arr[6];
    for (int i = 0; i < 5; i++)
    {
        arr[i]=getRandomNumber(arr, 70, 5);
    }
    sort(arr, arr+5);
    arr[5] = getRandomNumber(arr, 27, 5);
    return arr;
}

int main(int argc, const char * argv[]) {
    int numberOfArrays;
    
    srand(time(0));
    while(true)
    {
        cout << "How many winning numbers would you like to see?  ";
        cin >> numberOfArrays;
        
        for (int i = 0; i < numberOfArrays; i++)
        {
            int * arr = getNumbers();
            cout << "Your numbers are: ";
            for (int i = 0; i < 5; i++)
            {
                cout << arr[i] << " -";
            }
            
            cout<<"Powerball: "<<arr[5];
            cout << endl;
        }
        
        cout<<"would you like to see more numbers? (y/n)";
        string input;
        cin>>input;
        if(input == "y")
        {
            continue;
        }
        else
        {
            break;
        }
    }
    
    cout<<"Goodbye! :-)";
    return 0;
}
