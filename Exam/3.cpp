#include <iostream>//2
#include <ctime>
using namespace std;

int main()
{
        srand(time(0));
        int i, j;
        int** matrix;

        matrix = new int*[7]; 
        for(i = 0; i < 7; i++) 
            matrix[i] = new int[7];

        for(i = 0; i < 7; i++) 
            for(j = 0; j < 7; j++) 
                matrix[i][j] = 1 + rand() % 100;

        int max = 0;

        for(i = 0; i < 7; i++) 
            for(j = 0; j < 7; j++) 
                if(matrix[i][j] > max && (matrix[i][j] % 7) == 0)
                    max = matrix[i][j];

        for(i = 0; i < 7; i++) 
        {
            for(j = 0; j < 7; j++) 
                cout << matrix[i][j] << ends;
            cout << endl;
        }

        cout << endl << max << endl << endl;

        for(i = 0; i < 7; i++) 
            for(j = 0; j < 7; j++) 
                if(matrix[i][j] != matrix[6 - j][6 - i])
                {
                    cout << "Ne simetrichna" << endl;
                    return 0;
                }

    cout << "SIMETRIA!!!!!!!";
    return 0;
}   