#include <stdio.h>
#define ALLOCATE_SIZE 1000


//function to sort the elements of the array
void insertionSort(int arr[] , int length_of_array){

    for(int  i = 1 ; i<length_of_array;i++){
        int tmp = arr[i];

        int j = i - 1;

        while(tmp < arr[j] && j >= 0){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = tmp;
    }

}

int main()
{
    int arr[] = {9,23,3,4,1,2};
    int length = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr , length);
  return 0;
}
