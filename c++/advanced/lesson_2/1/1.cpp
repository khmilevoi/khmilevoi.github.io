#include <iostream>
using namespace std;

int prices[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int cut(int n) {
    if(n == 0) return 0;
    int result = 0;
    for(size_t i = 1; i < n + 1; i++) result = __max(result, prices[i - 1] + cut(n - i));
    return result;
}

int cut_cash(int n, int *cash) {
    int result = 0;
    cash[0] = 0;
    for(size_t i = 1; i < n + 1; i++) {
        result = 0;
        for(size_t j = 1; j < i + 1; j++)
            result = __max(result, prices[j - 1] + cash[i - j]);
        cash[i] = result;
    }
    return cash[n];
}

int cut_cash_splits(int n, int *cash, int *splits) {
    cash[0] = 0;
    int result = 0;
    int candidate = 0;
    for(size_t i = 1; i < n + 1; i++) {
        result = -1;
        for(size_t j = 1; j < i + 1; j++) {
            candidate = prices[j - 1] + cash[i - j];
            if(candidate > result) {
                result = candidate;
                splits[i] = j;
            }
        }
        cash[i] = result;
    }
    int size = n;
    while(size > 0) {
        cout << splits[size] << ' ';
        size -= splits[size];
    }
    cout << endl;
    return cash[n];
}

int main() {
    int exemple = 10;
    cout << cut(exemple) << endl;
    int cash[11] = {};
    int splits[11] = {};
    for(size_t i = 0; i < exemple + 1; i++) cash[i] = -1;
    cout << cut_cash(exemple, cash) << endl;
    for(size_t i = 0; i < exemple + 1; i++) cout << cash[i] << ends;
    cout << endl;
    cout << cut_cash_splits(exemple, cash, splits) << endl;
    for(size_t i = 0; i < exemple + 1; i++) cout << splits[i] << ends;
    cout << endl;
    return 0;
}