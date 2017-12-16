#include <iostream>
using  namespace std;
int n, sum[40];// 12
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
        for (int j = 0; j <= i; ++j)
            cout << sum[j] << (j != i ? '+' : '\n');
        cout << endl;
    }
}
int main()
{
    cin >> n;
    print_terms(n);

    return 0;
}