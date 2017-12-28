#include <iostream>//2
#include <ctime>
#include <algorithm> //for sort
using namespace std;

int main()
{
    srand(time(0));
    int i, j;
    int** matrix;
    matrix = new int*[9]; 

    for(i = 0; i < 9; i++)
        matrix[i] = new int[9];

    for(i = 0; i < 9; i++) 
        for(j = 0; j < 9; j++) 
            matrix[i][j] = 1 + rand() % 10;

    int max = 0;
    for(i = 0; i < 9; i++) 
    {
        for(j = 0; j < 9; j++) 
            if(matrix[j][i] > max)
                max = matrix[j][i];

        cout << "V " << i + 1 << " stovpchicu max el = " << max << endl;
        max = 0; 
    }
    for(i = 0; i < 9; i++) 
    {
        for(j = 0; j < 9; j++) 
            cout << matrix[i][j] << ends;
        cout << endl;
    }
    cout << endl;
    sort(matrix[2], matrix[2] + 9);
    for(i = 0; i < 9; i++) 
    {
        for(j = 0; j < 9; j++) 
            cout << matrix[i][j] << ends;
        cout << endl;
    }
    cout << endl << max << endl;

}  