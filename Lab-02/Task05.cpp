#include<iostream>
using namespace std;

int main(){
    int rows1, cols1, rows2, cols2;
    cout << "Enter the number of rows and columns of the 1st matrix: ";
    cin >> rows1 >> cols1;

    int** matrix1 = new int*[rows1];
    for (int i = 0; i < rows1; ++i)
    {
        matrix1[i] = new int[cols1];
    }
    cout << "Enter the number of rows and columns of the 2nd matrix: ";
    cin >> rows2 >> cols2;
    int** matrix2 = new int*[rows2];
    for (int i = 0; i < rows2; ++i)
    {
        matrix2[i] = new int[cols2];
    }
    cout << "Enter the Elements of the 1st matrix of size of " << rows1 << "x" << cols1 << ": ";
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            cin >> matrix1[i][j];
        }
        
    }

    cout << "Enter the Elements of the 2nd matrix of size of " << rows2 << "x" << cols2 << ": ";
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            cin >> matrix2[i][j];
        }
        
    }
    if (rows1==rows2 && cols1==cols2)
    {
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; i < cols1; i++)
            {
                matrix1[i][j] = matrix1[i][j] + matrix2[i][j];
            }
            
        }
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; i < cols1; i++)
            {
                matrix2[i][j] = matrix1[i][j] - matrix2[i][j];
            }
            
        }
    }
    else
        cout << "Addition & subtraction not possible as the size doesn't matches!" << endl;
    

    cout << "Addition of the elements of both matrix is: " << endl;
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "Subtraction of the elements of both matrix is: " << endl;
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            cout << matrix2[i][j] << " ";
        }
         cout << endl;
    }
    for (int i = 0; i < rows1; ++i)
    {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for (int i = 0; i < rows2; ++i)
    {
        delete[] matrix2[i];
    }
    delete[] matrix2;
}