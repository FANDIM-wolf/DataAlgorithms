
//library to solve tasks related to matrices

#include<iostream>



using namespace std;

int MAX = 99;
int MIN = 0;

int** createArray(int rows, int cols) {
    int** arr = new int*[rows];
    for(int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    return arr;
}

void createModelMatrix(int** arr, int rows, int cols) {
    
    //check higher and below edge numbers 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if( (i == MAX && j == MIN ) || (i == MIN && j == MIN) || (i == MIN && j == MAX) || (i == MAX && j == MAX ) ){
                arr[i][j] = 2;
                
            }
            else{
                 arr[i][j] = 1;
            }
            
        }
    }
    //check edge numbers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if((i == MAX && j != 0 && j != MAX) || (i == MIN && j != MAX && j != MIN)  ){
                
                    arr[i][j] = 3;
                
                
            }
            
        }
    }
     //check edge numbers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if( (i != MAX && j != MIN ) || (i != MIN && j != MIN) || (i != MIN && j != MAX) || (i != MAX && j != MAX )  ){
                
                    if(j == MIN && i != MAX && i != MIN ){
                         arr[i][j] = 4;
                    }
                
                
            }
            
        }
    }
    //check edge numbers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if( (i != MAX && j != MIN ) || (i != MIN && j != MIN) || (i != MIN && j != MAX) || (i != MAX && j != MAX )  ){
                
                    if(j == MAX && i != MAX && i != MIN ){
                         arr[i][j] = 4;
                    }
                
                
            }
            
        }
    }
    
}

int main()
{
    int rows = 100;
    int cols = 100;
   int** arr = createArray(rows, cols);
    createModelMatrix(arr, rows, cols);
    
    // Print the array to verify that it's been filled with 1's
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}
