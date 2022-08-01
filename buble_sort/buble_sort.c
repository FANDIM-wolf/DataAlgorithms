#include <stdio.h>

void buble_sort(){
int n, i, j;
     scanf_s("%d", &n);
    int a[n];
    /* count n elements*/

    /* create a array*/
    for(i = 0 ; i < n; i++) {
        scanf_s("%d", &a[i]);
    }
    for(i = 0 ; i < n - 1; i++) {
       /* compare two elements*/
       for(j = 0 ; j < n - i - 1 ; j++) {
           if(a[j] > a[j+1]) {
              /* if they break order , change each other*/
              int tmp = a[j];
              a[j] = a[j+1] ;
              a[j+1] = tmp;
           }
        }
    }
}

int main()
{
  buble_sort();
  return 0;
}
