#include <vector>
#include <fstream>
#include <iostream>

long long count_of_palindroms(std::vector<long long> vector) {

    std::vector<std::vector<int>> results(vector.size() + 1, std::vector<int>(vector.size() + 1));

    for(long long i = 1; i <= vector.size(); ++i) {
        for(long long j = 0; j <= vector.size() - i; ++j) {
            int position = j + i;
            int count = results[j + 1][position];
            int cash = vector[j];
          std::cout << i << ' ' << j << ' ' << position << ' ' << count << ' ' << cash << '\n';

            for(long long k = j; k < position; ++k) {
                if(vector[k] == cash) {
                    count += 1 + results[j + 1][k];
                }
            }

            results[j][position] = count;
        }
    }
    for(auto i : results) {
      for(auto j : i) {
        std::cout << j << ' ';
      }
      std::cout << '\n';
    }

    return results[0][vector.size()];
}

int main() {

    long long amount_of_tshirts = 0;

    std::vector<long long> tshirts;

    std::ifstream in("input.txt");

    in >> amount_of_tshirts;

    for(long long i = 0; i < amount_of_tshirts; ++i) {
        int cash = 0;
        in >> cash;
        tshirts.push_back(cash);
    }

    in.close();


    std::ofstream out("output.txt");
    
    out << count_of_palindroms(tshirts) % 1000000000;

    out.close();

    return 0;
}