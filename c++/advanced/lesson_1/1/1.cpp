#include <iostream>
using namespace std;

int fibonacci(int n = 0) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n - 2) + fibonacci(n - 1);
}


int fibonacci_cash(int *mas, int n) {
    int n1 = 0;
    int n2 = 1;
    // if(mas[n] == 0) mas[n] = fibonacci_cash(mas, n - 1) + fibonacci_cash(mas, n - 2);
    // for(size_t i = 2; i < n; i++) mas[i] = mas[i - 1] + mas[i - 2];
    for(size_t i = 2; i < n; i++) {
        auto cash = n1 + n2;
        n1 = n2;
        n2 = cash;
    }
    // return mas[n - 1];
    return n1 + n2;
}

int main() {
    cout << fibonacci(10) << endl;
    int mas[10] = {};
    mas[0] = 0;
    mas[1] = 1;
    cout << fibonacci_cash(mas, 10) << endl;
    for(size_t i = 0; i < 10; i++) cout << mas[i] << ' '; cout << endl;
    return 0;
}