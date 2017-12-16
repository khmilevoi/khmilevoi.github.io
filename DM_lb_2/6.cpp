#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm> //8
using namespace std;

void main()
{
    vector<int> itog(7);
    fill(itog.begin(), itog.end(), 1);

    for(int i = 6; i >= 0; i--)
    {
        copy(
            itog.begin(),
            itog.end(),
            ostream_iterator<int>(cout, " "));
        cout << endl;

        while (next_permutation(itog.begin(), itog.end()))
            {
                copy(
                    itog.begin(),
                    itog.end(),
                    ostream_iterator<int>(cout, " "));
                cout << endl;
            }

        itog[i] = 2;
    }

    copy(
            itog.begin(),
            itog.end(),
            ostream_iterator<int>(cout, " "));
        cout << endl;
        
}