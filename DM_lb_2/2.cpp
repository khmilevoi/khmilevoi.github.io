#include <iostream>
using namespace std; //2

int main()
{
    for(int i = 1; i <= 5; i++)
        for(int j = i + 1; j <= 5; j++)
            cout << i << ends << j << endl;
    return 0;
}