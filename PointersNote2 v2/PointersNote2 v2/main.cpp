//
//  main.cpp
//  PointersNote2
//
//  Created by - on 2016/11/08.
//  Copyright © 2016 Eddie of The Ren. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <cstdint>

void example1b() {
    int length;
    int *ArrayPtr;
    cout << " Please enter the length of the array " << endl;
    cin >> length;
    
    ArrayPtr = new int[length];
    cout << "Please enter the elements of the array " << endl;
    for (int index = 0; index <= length -1; index++) {
        //Gets the value of the arrays
        cin >> ArrayPtr[index];
    }
    
    cout << "\nDisplaying the array in normalOrder: "<< endl;
    
    for (int index = 0; index <= length -1; index++) {
        
        int reverseCount = 0;
        //Prints the arrays in reverse
        cout << ArrayPtr[(reverseCount-index)]<<" ";
    }
    cout << endl;

    
    cout << "\nDisplaying the array in reverse: "<< endl;
    
    for (int index = 0; index <= length -1; index++) {
        
        int reverseCount = length-1;
        //Prints the arrays in reverse
        cout << ArrayPtr[(reverseCount-index)]<<" ";
    }
    
    cout << endl;
    
}

void example1c() {
    cout << "Dynamically initiating and then summing an array"<< endl;
    int length = 50;
    int *ArrayPtr;
    int sum = 0;
    cout << "     Array values: ";
    ArrayPtr = new int[length];
    for (int index = 0; index <= length -1; index++) {
        //Generates a random number for each array values
        ArrayPtr[index] = rand() %50 +1;
        //Prints this random value with a space afterwards
        cout << ArrayPtr[index] << " ";
        //adds this to the total sum
        sum += ArrayPtr[index];
    }
    
    cout << "\nThe sum is " << sum << endl;
    
}

void example1bMatrix() {
    
    int row;
    int column;
    int sum = 0;
    
    int **matrix; //two * are needed because it is a pointer to a pointer
    cout << "please enter the dimesion of the matrix" << endl;
    cin >> row;
    cin >> column;
    
    matrix=new int*[row]; //creates a new array of pointers to int objects for rows
    for(int i=0; i<row; ++i)
        matrix[i]= new int[column];//creates new 'column' number of locations
    
    cout << "Here is the array: " << endl << endl;
    for ( int i= 0; i<row; i++) {
        for ( int j=0; j<column; j++) {
            matrix[i][j] = rand() %1000 +1;
            sum += matrix[i][j];
        }
    }
    
    for (int r=0; r<row; r++){
        for (int c = 0; c< column; c++)
            printf("%-5d", matrix[r][c]);
            //cout << matrix[r][c]<<"\t";
        cout << endl;
    }
    
    
    int average = 0;
    average = sum / (row * column);
    cout << "The average value in this matrix is: " << average << endl;
}

void example1cMatrix() {
    
    int row;
    int column;
    int sum = 0;
    
    int **matrix; //two * are needed because it is a pointer to a pointer
    cout << "please enter the dimesion of the matrix" << endl;
    cin >> row;
    cin >> column;
    //column = row;
    matrix=new int*[row]; //creates a new array of pointers to int objects for rows
    for(int i=0; i<row; ++i)
        matrix[i]= new int[column];//creates new 'column' number of locations
    
    cout << "Here is the matrix " << endl;
    for ( int i= 0; i<row; i++) {
        for ( int j=0; j<column; j++) {
            //Assigns each matrix value a random number between 0-1000
            matrix[i][j] = rand() %1000 +1;
        }
    }
    
    for (int r=0; r<row; r++){
        cout << endl;
        for (int c = 0; c< column; c++)
            if (r == c) {
                //Prints the value of the matrix when they are on the main diagonal
                printf("%-5d", matrix[r][c]);

            } else {
                //Prints a blank when no on the main diagonal
                printf("%-5s", " ");

            }
        cout << endl;
    }
    
    
    //int average = 0;
    //average = sum / (row * column);
    //cout << "The average value in this matrix is: " << average << endl;
    
}

void example2Append() {
    
    int row;
    int column;
    int row2;
    int column2;
    
    int **matrix; //two * are needed because it is a pointer to a pointer
    cout << "please enter the dimesion matrix1 and matrix2 " << endl;
    cin >> row;
    cin >> column;
    
    matrix=new int*[row]; //creates a new array of pointers to int objects for rows
    //matrix3=new int*[row]; //creates a new array of pointers to int objects for rows
    
    
    
    for(int i=0; i<row; ++i) {
        matrix[i]= new int[column];//creates new 'column' number of locations
    }
    
    for ( int i = 0; i<row; i++) {
        for ( int j=0; j<column; j++) {
            matrix[i][j] = (rand() %1000) +1;
            //matrix[0][0] = 31;
            
        }
    }
    //int temp = matrix[0][0];
    
    int **matrix2; //two * are needed because it is a pointer to a pointer
    cin >> row2;
    cin >> column2;
    matrix2=new int*[row2]; //creates a new array of pointers to int objects for rows
    
    for(int i=0; i<row2; ++i) {
        matrix2[i]= new int[column2];//creates new 'column' number of locations
    }
    
    for ( int i= 0; i<row2; i++) {
        for ( int j=0; j<column2; j++) {
            
            matrix2[i][j] = (rand() %1000) +1;
        }
    }
    
    //matrix[0][0] = temp;
    cout << "\nMatrix 1: " << endl;
    for (int r=0; r<row; r++){
        for (int c = 0; c< column; c++) {
            printf("%-5d", matrix[r][c]);

            
        }
        cout << endl;
    }
    cout << "\nMatrix 2: " << endl;

    for (int r=0; r<row2; r++){
        for (int c = 0; c< column2; c++) {
            printf("%-5d", matrix2[r][c]);

            //cout << matrix2[r][c]<< "\t";
        }
        cout << endl;
    }
    
    cout << "\nThe big matrix with everything" << endl;
    int **matrix3; //two * are needed because it is a pointer to a pointer
    int row3;
    if (row2 > row) {
        row3 = row2;
    } else {
        row3 = row;
    }
    int column3 = column + column2;
    
    matrix3=new int*[row3]; //creates a new array of pointers to int objects for rows
    
    for(int i=0; i<row3; ++i) {
        matrix3[i]= new int[column3];//creates new 'column' number of locations
    }
    
    for ( int i= 0; i<row3; i++) {
        for ( int j=0; j<column3; j++) {
            if ((j < column) && (i <row)) {
                
                
                matrix3[i][j] =  matrix[i][j];
            } else if (( i < row2) && (j>=column)) {
                matrix3[i][j] =  matrix2[i][j-column];
            } else {
                matrix3[i][j] = 0;
            }
        }
    }
    
    for (int r=0; r<row3; r++){
        for (int c = 0; c< column3; c++) {
            printf("%-5d", matrix3[r][c]);

            //cout << matrix3[r][c]<< "\t";
        }
        cout << endl;
    }
    
}

int main(){
    srand(static_cast<uint16_t>(time(0)));
    
    cout << "\nExample 1a and 1b (Initializes and prints array)" << endl;
    //example1b();
    
    cout << "\nExample 1c (Finds sum of array)" << endl;
    //example1c();
    
    cout << "\nExample 1b-Matrix (Initializes matrix and finds its average value)" << endl;
    //example1bMatrix();
    
    cout << "\nExample 1c-Matrix (Only elements on the diagonal)" << endl;
    example1cMatrix();
    
    cout << "Example 2-Matrix Returns (Append 2 matrixes) " << endl;
    example2Append();
    
    
}
