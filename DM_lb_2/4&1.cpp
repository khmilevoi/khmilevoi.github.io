#include <algorithm>
#include <iterator>
#include <vector> //4 и 1
#include <iostream>

using namespace std;

void kol(int item[], int length)
{
    vector<char> v;
    
    for (int i = 0; i != length; i++)
        v.push_back(item[i]);

    while (next_permutation(v.begin(), v.end()))
    {
        copy(
            v.begin(),
            v.end(),
            ostream_iterator<char>(cout, " "));
        cout << endl;
    }
}

int main()
{
    const int size = 5;
    int array[size] = {'a', 'b', 'c', 'd', 'e'};

    for (int i = 0; i < size; i++)
        cout << array[i] << ends;
    cout << endl;

    kol(array, size);

    return 0;
}