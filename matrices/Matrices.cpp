#include<iostream>



using namespace std;

int MAX = 60;
int MIN = 0;

int** createRandomArray(int rows, int cols) {
    // dynamically allocate array
    int** arr_r = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr_r[i] = new int[cols];
    }

    // set random seed
    srand(time(NULL));

    // fill array with random numbers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr_r[i][j] = rand() % 12340;
        }
    }

    // return dynamically allocated array
    return arr_r;
}
int** createArray(int rows, int cols) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {

        arr[i] = new int[cols];
    }
    return arr;
}
void createModelMatrix(int** arr, int rows, int cols) {

    //check higher and below edge numbers 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i == MAX && j == MIN) || (i == MIN && j == MIN) || (i == MIN && j == MAX) || (i == MAX && j == MAX)) {
                arr[i][j] = 2;

            }
            else {
                arr[i][j] = 1;
            }

        }
    }
    //check edge numbers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i == MAX && j != 0 && j != MAX) || (i == MIN && j != MAX && j != MIN)) {

                arr[i][j] = 3;


            }

        }
    }
    //check edge numbers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i != MAX && j != MIN) || (i != MIN && j != MIN) || (i != MIN && j != MAX) || (i != MAX && j != MAX)) {

                if (j == MIN && i != MAX && i != MIN) {
                    arr[i][j] = 4;
                }


            }

        }
    }
    //check edge numbers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i != MAX && j != MIN) || (i != MIN && j != MIN) || (i != MIN && j != MAX) || (i != MAX && j != MAX)) {

                if (j == MAX && i != MAX && i != MIN) {
                    arr[i][j] = 4;
                }


            }

        }
    }

}

int** createModel_Relationes_Summa(int** arr_model, int ** arr_origin , int rows, int cols) {

    // dynamically allocate array
    int** arr_r = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr_r[i] = new int[cols];
    }

    // set random seed
    srand(time(NULL));

    // fill array with random numbers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr_r[i][j] = 0;
        }
    }

    //check higher and below edge numbers 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr_model[i][j] == 2) {
                if (i == MAX && j == MIN)
                {
                    arr_r[i][j] += arr_origin[MAX - 1][j];
                    arr_r[i][j] += arr_origin[MAX][MAX];
                    arr_r[i][j] += arr_origin[i][j + 1];

                }
                if (j == MAX && i == MIN)
                {
                    arr_r[i][j] += arr_origin[i][MAX - 1];
                    arr_r[i][j] += arr_origin[MIN][MIN];
                    arr_r[i][j] += arr_origin[i + 1][j];
                }
                if (i == MIN &&  j == MIN)
                {
                    arr_r[i][j] += arr_origin[i][j+1];
                    arr_r[i][j] += arr_origin[i + 1][j];
                    arr_r[i][j] += arr_origin[MIN][MAX];
                }
                if (i == MAX && j == MAX)
                {
                    arr_r[i][j] += arr_origin[i-1][j];
                    arr_r[i][j] += arr_origin[i][j -1];
                    arr_r[i][j] += arr_origin[MAX][MIN];
                }
               
            }
            if (arr_model[i][j] == 3) {
                if (i == MIN) {
                    arr_r[i][j] += arr_origin[i][j - 1];
                    arr_r[i][j] += arr_origin[i][j + 1];
                    arr_r[i][j] += arr_origin[MAX][j];

                }
                if (i == MAX) {
                    arr_r[i][j] += arr_origin[i][j - 1];
                    arr_r[i][j] += arr_origin[i][j + 1];
                    arr_r[i][j] += arr_origin[MIN][j];

                }

            }
            if (arr_model[i][j] == 4) {
                if (j == MIN) {
                    arr_r[i][j] += arr_origin[i-1][j];
                    arr_r[i][j] += arr_origin[i+1][j];
                    arr_r[i][j] += arr_origin[i][j+1];

                }
                if (j == MAX) {
                    
                    arr_r[i][j] += arr_origin[i - 1][j];
                    arr_r[i][j] += arr_origin[i + 1][j];
                    arr_r[i][j] += arr_origin[i][j - 1];
                }

            }
            if (arr_model[i][j] == 1) {
                
                    arr_r[i][j] += arr_origin[i - 1][j];
                    arr_r[i][j] += arr_origin[i + 1][j];
                    arr_r[i][j] += arr_origin[i][j + 1];
                    arr_r[i][j] += arr_origin[i][j - 1];

            }
        }
    }
    return arr_r;

}

int main()
{
    int rows = 61;
    int cols = 61;
    int** arr = createArray(rows, cols);
    createModelMatrix(arr, rows, cols);
    int** arr_r = createRandomArray(rows, cols);
    int** new_arr = createModel_Relationes_Summa(arr,arr_r,rows,cols);
    // Print the array to verify that it's been filled with 1's
    /*
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */
    // Print the array to verify that it's been filled with 1's
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr_r[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    // Print the array to verify that it's been filled with 1's
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << new_arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // Free the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    int end;
    cin >> end;

    return 0;
}