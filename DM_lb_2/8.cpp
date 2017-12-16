#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm> //8
using namespace std;
int n, sum[40];
vector<int> itog;
void print_terms(int left, int min = 0, int i = 0)
{
    if (left < 0 || min == n)
        return;
    sum[i] = min;
    if (min != 0)
    {
        print_terms(left - min, min, i + 1);
    }
    print_terms(left - 1, min + 1, i);

    if (left == 0)
    {
        for (int j = 0; j < 15; j++)
            if (sum[j] != 0)
            {
                itog.push_back(sum[j]);
                cout << sum[j] << (sum[j + 1] != 0 ? '+' : ' ');

                if (j == i)
                    break;
            }
        cout << endl;

        while (next_permutation(itog.begin(), itog.end()))
        {
            copy(
                itog.begin(),
                itog.end(),
                ostream_iterator<int>(cout, "+"));
            cout << endl;
        }
        itog.clear();
    }
}
int main()
{
    cin >> n;
    print_terms(n);

    return 0;
}