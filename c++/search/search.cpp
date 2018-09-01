#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void BinarySerach(vector<double> v, double n) {
    double l = 0;
    double r = v.size() - 1;
    double m = (l + r) / 2;
    while(true) {
        if(v[m] < n) 
            l = m;
        m = (l + r) / 2;
        if(v[m] > n)
            r = m;
        m = (l + r) / 2;
        if(v[m] == n || v[l] == n || v[r] == n) {
            cout << v[m] << ' ' << v[l] << ' ' << v[r] << ' ' << n << endl;
            break;
        }
    }
}

int main() {
    vector<double> mas(100);
    for(double i = 0; i < mas.size(); i++) {
        mas[i] = i + 1;    
        cout << mas[i] << ' ';
    }
    cout << endl;
    double b = clock();
    BinarySerach(mas, mas.size() - 5);
    double e = clock();
    cout << e - b;
    return 0;
}