

/*******************************************************************************
*
* Program: Insertion Sort Algorithm Implementation
* 
* Description: Implementation of the insertion sort algorithm in C++.
*
* 
*
* Author: Michel Kommel https://vk.com/id589731556
*
*******************************************************************************/

#include <iostream>

using namespace std;





void insertion_sort(int a[], int length)
{
  
  for (int i = 1; i < length; i++)
  {

    int key = a[i];
    int j = i - 1;

  
    while (j >= 0 && a[j] > key) 
    {
      a[j + 1] = a[j];
      j = j - 1;
      cout<<"j:"<<j<<endl;
    }

  
    a[j + 1] = key;
  }
}

int main()
{

  int a[] = {7,2,3,5,4};
  int length = 5;
  
  
  insertion_sort(a, length);
  
  // Output each array index/value after it has been sorted.

  for (int i = 0; i < length; i++)
  {
    cout << "a[" << i << "] = " << a[i] << endl;
  }
  
  return 0;
}

