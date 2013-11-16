/*
reverse the bit representation of a number
Assuming the number is positive.
Written by Xi Wang
11/15/2013
*/

#include <iostream>
using namespace std;

int reverseBit(int num)
{
    int first = 1;
    int len = 1;
    while(first<=num)
    {
        first<<=1;
        len <<=1;
    }
    first>>=1;
    len>>=1;
    int result = 0;
    int last = 1;
    int count = 1;
    while(first>=last)
    {

        first = first&num;
        last = last&num;
        while(first>count)
        {
            first>>=1;
            last<<=1;
        }
        result = result |first;
        result = result |last;
        count<<=1;
        first = len>>1;
        last = count;
        len>>=1;
    }
    return result;
    }
int main()
{
   int number =13;
   cout<<number<<endl;
   int number2 = reverseBit(number);
   cout<<number2<<endl;

   return 0;
}
