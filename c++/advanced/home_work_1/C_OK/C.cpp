#include <fstream>
#include <vector>
#include <algorithm>

void generate_subset(
    std::vector<int>::iterator left_iterator, 
    std::vector<int>::iterator right_iterator,
    std::vector<long long> &sequence_of_sum
) {

    int list_size = right_iterator - left_iterator;

    int mask_size = 1 << list_size;

    for (int iteration_of_mask = 0; iteration_of_mask < mask_size; ++iteration_of_mask) {

        long long sum_of_iteration = 0;

        int power = 0;

        for (
            auto element_of_list = left_iterator; 
            element_of_list != right_iterator; 
            ++element_of_list
        ) {

            if (iteration_of_mask & (1 << power)) {
                sum_of_iteration += *element_of_list;
            }

            ++power;
        }

        sequence_of_sum.push_back(sum_of_iteration);
    }
}

int number_of_subsets(std::vector<int> &list, const long long max_weight) {

    std::vector<long long> left_sum;
    std::vector<long long> right_sum;

    generate_subset(list.begin(), list.begin() + list.size() / 2, left_sum);

    generate_subset(list.begin() + list.size() / 2, list.end(), right_sum);

    std::sort(right_sum.begin(), right_sum.end());

    std::vector<long long>::iterator left;
    std::vector<long long>::iterator right;

    int answer = 0;

    for (int index = 0; index < left_sum.size(); ++index) {

        left = std::lower_bound(right_sum.begin(), right_sum.end(), - left_sum[index]);

        right = std::upper_bound(right_sum.begin(), right_sum.end(), max_weight - left_sum[index]);

        answer += right - left;
    }

    return answer;
}

int main() {

    std::ifstream in("input.txt");

    int number_of_things = 0;

    in >> number_of_things;

    std::vector<int> things;

    for (int thing = 0; thing < number_of_things; ++thing) {

        int cash = 0;
        in >> cash;
        things.push_back(cash);
    }

    long long max_weight = 0;

    in >> max_weight;

    in.close();

    std::ofstream out("output.txt");

    out << number_of_subsets(things, max_weight);

    out.close();

    return 0;
}
