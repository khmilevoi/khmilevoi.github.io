#include <iostream>
#include <vector>

std::vector<std::vector<double>> matrix_multiplication(
    const std::vector<std::vector<double>> first_matrix,
    const std::vector<std::vector<double>> secon_matrix) {

    std::vector<std::vector<double>> product_of_multiplication(first_matrix.size(), std::vector<double>(secon_matrix[0].size()));
    
    for (size_t row = 0; row < first_matrix.size(); ++row) {
        for (size_t col = 0; col < secon_matrix[0].size(); ++col) {
            for (size_t inner = 0; inner < secon_matrix.size(); ++inner) {
                product_of_multiplication[row][col] += first_matrix[row][inner] * secon_matrix[inner][col];
            }
        }
    }
    return product_of_multiplication;
}

void print_of_matrix(const std::vector<std::vector<double>> &matrix) {

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

double activation_function(const double number) {

    if (number >= 0.5) {
        return 1;
    }
    else {
        return 0;
    }
}

std::vector<std::vector<double>> normalization_of_matrix(std::vector<std::vector<double>> &matrix) {

    std::vector<std::vector<double>> product(matrix.size(), std::vector<double>(matrix[0].size()));

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            product[i][j] = activation_function(matrix[i][j]);
        }
    }
    return product;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const bool VALUE_OF_X = 0;
    const bool VALUE_OF_Y = 1;

    std::cout << VALUE_OF_X << ' ' << VALUE_OF_Y << '\n';

    std::vector<std::vector<double>> input = { 
        {(double)VALUE_OF_X}, 
        {(double)VALUE_OF_Y}
    };

    std::vector<std::vector<double>> weigth_input_to_output = { 
        {0.4, 0.4}
        // {0.5, 0.5}
    };  


    std::vector<std::vector<double>> hidden_output = matrix_multiplication(weigth_input_to_output, input);

    std::vector<std::vector<double>> output = normalization_of_matrix(hidden_output);

    print_of_matrix(output);

    return 0;
}
