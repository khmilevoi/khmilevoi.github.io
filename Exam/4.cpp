#include <iostream>//3
#include <fstream> // for we could work with files
#include <vector> 
#include <algorithm> //for min_element
#include <iterator> 
#include <numeric> // for аccumulate
using namespace std;
 
int main()
{
    int b;
    vector <int> v;
    ifstream input("1.txt", ios_base::binary);
    while(input)
    {
        input >> b;
        v.push_back(b);
    }

    v.erase(v.end(), v.end());

    copy( v.begin(),   // итератор начала массива
          v.end(),     // итератор конца массива
          ostream_iterator<int>(cout," ")   //итератор потока вывода
        );

    cout << endl;

    vector<int>::iterator result = min_element(v.begin(), v.end());
    cout << accumulate(result + 1, v.end(), 0);
    input.close();
    return 0;
}