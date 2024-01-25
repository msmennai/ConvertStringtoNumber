// ConvertStringtoNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int convert2Number(char* myStr,int size)
{
   
    if (size == 0)
        return 0;
    
   static int pos  = 0;
   int res;

   if (pos == 0 && !isdigit(myStr[pos++]))
       res = 0;
   else
       res = (myStr[pos++] - '0')* (pow(10, --size));

   return  res + convert2Number(myStr, size);  

}

int main()
{

    cout << "Hello World!\n";
    char myString[20]="\0";
    cout << "Enter your number string\n";
    cin >> myString;
    static int size = 0;
    bool negative = false;
    while (myString[size] != 0)
    {
        
        if ( !isdigit(myString[size]) )
        {
            if (size == 0 && myString[size] == '-' && myString[size+1] != 0)
                negative = true;
            else 
            {
                cout << "Not a valid Number\n";
                return 0;
            }
        }
        size++;
    }

   int result = convert2Number(myString,size-1);
   negative ? cout << result * -1 : cout <<result;
   return 0;
   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
