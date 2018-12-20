#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using std::vector;
typedef vector<vector<double>> vector_of_vectors;

vector_of_vectors matrix_multiplication(const vector_of_vectors &first_matrix, const vector_of_vectors &second_matrix) {

    vector_of_vectors product_by_multiplication;
    size_t number_of_rows_of_matrix_1 = first_matrix.size();
    size_t number_of_colums_of_matrix_1 = first_matrix[0].size();
    size_t number_of_rows_of_matrix_2 = second_matrix.size();
    size_t number_of_colums_of_matrix_2 = second_matrix[0].size();

    try {
        if(number_of_colums_of_matrix_1 != number_of_rows_of_matrix_2) {
            throw "ERROR> invalide data";
        }
    } catch(char *error) {
        std::cout << error << '\n';
    }

    product_by_multiplication.resize(number_of_rows_of_matrix_1);
    for(size_t i = 0; i < number_of_rows_of_matrix_1; ++i) {
        product_by_multiplication[i].resize(number_of_colums_of_matrix_2);
        for(size_t j = 0; j < number_of_colums_of_matrix_2; ++j) {
            for(size_t k = 0; k < number_of_colums_of_matrix_1; ++k) {
                product_by_multiplication[i][j] += first_matrix[i][k] * second_matrix[k][j];
            }
        }
    }

    return product_by_multiplication;
}

void print_of_matrix(const vector_of_vectors &matrix) {

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

class Neural_network {
  public:
    Neural_network(const double learning_rate = 0.1, const double number_of_inputs = 2, const double number_of_hidden_neuron = 8) : learning_rate(learning_rate) {

        weight_0_1.resize(number_of_hidden_neuron);
        for(auto &i : weight_0_1) {
            i.resize(number_of_inputs);
            for(auto &j : i) {
                j = double(rand() % 10) / 10;
            }
        }
        weight_1_2.resize(1);
        for(auto &i : weight_1_2) {
            i.resize(number_of_hidden_neuron);
            for(auto &j : i) {
                j = double(rand() % 10) / 10;
            }
        }

    }

    double sigmoid(const double x) {

        return 1 / (1 + std::exp(-x));
    }

    vector_of_vectors sigmoid_mapper(const vector_of_vectors &matrix) {

        vector_of_vectors product(matrix.size(), vector<double>(matrix[0].size()));
        for(size_t i = 0; i < product.size(); ++i) {
            for(size_t j = 0; j < product[0].size(); ++j) {
                product[i][j] = this->sigmoid(matrix[i][j]);
            }
        }

        return product;
    }

    vector_of_vectors predict(const vector_of_vectors &inputs) {

        inputs_1 = matrix_multiplication(weight_0_1, inputs);
        outputs_1 = this->sigmoid_mapper(inputs_1);

        inputs_2 = matrix_multiplication(weight_1_2, outputs_1);
        outputs_2 = this->sigmoid_mapper(inputs_2);

        return outputs_2;
    }

    void train(const vector_of_vectors &inputs, const double expexted_predict) {


        double actual_predict = 0.0;
        vector_of_vectors error_layer_1;
        double error_layer_2 = 0.0;
        vector_of_vectors gradient_layer_1;
        double gradient_layer_2 = 0.0;
        vector_of_vectors weigth_delta_layer_1;
        double weigth_delta_layer_2 = 0.0;

        inputs_1 = matrix_multiplication(weight_0_1, inputs);
        outputs_1 = this->sigmoid_mapper(inputs_1);

        inputs_2 = matrix_multiplication(weight_1_2, outputs_1);
        outputs_2 = this->sigmoid_mapper(inputs_2);
        actual_predict = outputs_2[0][0];

        error_layer_2 = actual_predict - expexted_predict;
        gradient_layer_2 = this->sigmoid(actual_predict) * (1 - this->sigmoid(actual_predict));
        weigth_delta_layer_2 = error_layer_2 * gradient_layer_2;

        for(size_t i = 0; i < weight_1_2.size(); ++i) {
            for(size_t j = 0; j < weight_1_2[0].size(); ++j) {
                weight_1_2[i][j] -= outputs_1[j][i] * weigth_delta_layer_2 * this->learning_rate;
            }
        }

        error_layer_1.resize(weight_1_2.size());
        for(size_t i = 0; i < error_layer_1.size(); ++i) {
            error_layer_1[i].resize(weight_1_2[0].size());
            for(size_t j = 0; j < error_layer_1[0].size(); ++j) {
                error_layer_1[i][j] = weight_1_2[i][j] * weigth_delta_layer_2;
            }
        }

        gradient_layer_1.resize(weight_1_2.size());
        for(size_t i = 0; i < gradient_layer_1.size(); ++i) {
            gradient_layer_1[i].resize(weight_1_2[0].size());
            for(size_t j = 0; j < gradient_layer_1[0].size(); ++j) {
                gradient_layer_1[i][j] = this->sigmoid(outputs_1[j][i]) * (1 - this->sigmoid(outputs_1[j][i]));
            }
        }

        weigth_delta_layer_1.resize(weight_1_2.size());
        for(size_t i = 0; i < weigth_delta_layer_1.size(); ++i) {
            weigth_delta_layer_1[i].resize(weight_1_2[0].size());
            for(size_t j = 0; j < weigth_delta_layer_1[0].size(); ++j) {
                weigth_delta_layer_1[i][j] = error_layer_1[i][j] * gradient_layer_1[i][j];
            }
        }

        for(size_t i = 0; i < weight_0_1.size(); ++i) {
            for(size_t j = 0; j < weight_0_1[0].size(); ++j) {
                weight_0_1[i][j] -= inputs[j][0] * weigth_delta_layer_1[0][i] * this->learning_rate;
            }
        }        
    }

  private:
    const  double learning_rate;
    vector_of_vectors inputs_1;
    vector_of_vectors weight_0_1;
    vector_of_vectors outputs_1;
    vector_of_vectors inputs_2;
    vector_of_vectors weight_1_2;
    vector_of_vectors outputs_2;
    
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    srand(time(NULL));

    const size_t EPOCH = 5000;
    const double LERANING_RATE = 0.05;

    vector<vector<vector<double>>> train = {
        {{0}, {0}},
        {{0}, {1}},
        {{1}, {0}},
        {{1}, {1}}
    };
    
    vector<double> correct_predict = {0, 1, 0, 0};

    Neural_network network(LERANING_RATE, train[0].size(), 50);

    size_t j = 0;
    for(size_t i = 0; i < EPOCH; ++i) {
        for(size_t j = 0; j < train.size(); ++j) {
            network.train(train[j], correct_predict[j]);
        }
        if(i % (EPOCH / 100) == 0 ) {
            std::system("cls");
            std::cout << "Progress: " << double(i) / EPOCH * 100 << "%\n";
            std::cout << "Traning loss: " << std::pow(network.predict(train[j])[0][0] - correct_predict[j], 2) << "\n\n";
        }
    }
    
    for(size_t i = 0; i < train.size(); ++i) {
        std::cout << "Input: \n";
        print_of_matrix(train[i]);
        std::cout << "Predict: ";
        double expexted_predict = network.predict(train[i])[0][0];
        std::cout << std::round(expexted_predict) << '(' << expexted_predict << ") ";
        std::cout << (std::round(expexted_predict) == correct_predict[i] ? "Correct!\n" : "Wrong\n");
        std::cout << "Correct predict: ";
        std::cout << correct_predict[i] << "\n\n";
    }    

    return 0;
}