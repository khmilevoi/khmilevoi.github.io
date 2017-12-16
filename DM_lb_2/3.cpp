#include <iostream>
using namespace std; //2

int main()
{
    int A[] = {1, 2, 3, 4};

    for(int i = 0; i < 4; i++)
        cout << A[i] << endl; 

    for(int i = 0; i < 4; i++)
        for(int j = 1 + i; j < 4; j++)
            cout << A[i] << ends << A[j] << endl;

    for(int i = 0; i < 4; i++)
        for(int j = 1 + i; j < 4; j++)
            for(int u = 1 + j; u < 4; u++)
                cout << A[i] << ends << A[j] << ends << A[u] << endl;


    for(int i = 0; i < 4; i++)
        for(int j = 1 + i; j < 4; j++)
            for(int u = 1 + j; u < 4; u++)
                for(int b = 1 + u; b < 4; b++)
                    cout << A[i] << ends << A[j] << ends << A[u] << ends << A[b] << endl;

    cout << "/0";

    return 0;
}