#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using std::vector;
typedef vector<vector<double>> vector_of_vectors;
const double EXP = 0.000000000001;

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
    Neural_network(const double learning_rate = 0.1, const size_t number_of_inputs = 2, const size_t number_of_hidden_neuron = 8, const size_t number_of_layers = 3) : learning_rate(learning_rate) {

        weight_input_to_layers.resize(number_of_hidden_neuron);
        for(auto &i : weight_input_to_layers) {
            i.resize(number_of_inputs);
            for(auto &j : i) {
                j = double(rand() % 10) / 10;
            }
        }

        Inputs.resize(number_of_layers);
        for(auto &i : Inputs) {
            i.resize(number_of_hidden_neuron);
            for(auto &j : i) {
                j.resize(number_of_hidden_neuron);
            }
        }
        Outputs.resize(number_of_layers);
        for(auto &i : Outputs) {
            i.resize(number_of_hidden_neuron);
            for(auto &j : i) {
                j.resize(number_of_hidden_neuron);
            }
        }
        Weights.resize(number_of_layers);
        for(auto &i : Weights) {
            i.resize(number_of_hidden_neuron);
            for(auto &j : i) {
                j.resize(number_of_hidden_neuron);
                for(auto &k : j) {
                    k = double(rand() % 10) / 10;
                }
            }
        }
        
        weight_layes_to_output.resize(1);
        for(auto &i : weight_layes_to_output) {
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


        inputs_begin = matrix_multiplication(weight_input_to_layers, inputs);
        outputs_begin = sigmoid_mapper(inputs_begin);
        
        Inputs[0] = matrix_multiplication(Weights[0], outputs_begin);
        Outputs[0] = sigmoid_mapper(Inputs[0]);

        for(size_t i = 1; i < Weights.size(); ++i) {
            Inputs[i] = matrix_multiplication(Weights[i], Outputs[i - 1]);
            Outputs[i] = sigmoid_mapper(Inputs[i]);
        }

        inputs_end = matrix_multiplication(weight_layes_to_output, Outputs[Outputs.size() - 1]);
        outputs_end = sigmoid_mapper(inputs_end);

        return outputs_end;

    }

    void train(const vector_of_vectors &inputs, const double expexted_predict) {

        double actual_predict = 0.0;
        vector_of_vectors error_of_hidden_layers;
        double error_layer = 0.0;
        vector_of_vectors gradient_of_hidden_layers;
        double gradient_layer = 0.0;
        vector_of_vectors weight_delta_of_hidden_layers;
        double weight_delta_layer = 0.0;


        inputs_begin = matrix_multiplication(weight_input_to_layers, inputs);
        outputs_begin = sigmoid_mapper(inputs_begin);
        
        Inputs[0] = matrix_multiplication(Weights[0], outputs_begin);
        Outputs[0] = sigmoid_mapper(Inputs[0]);

        for(size_t i = 1; i < Weights.size(); ++i) {
            Inputs[i] = matrix_multiplication(Weights[i], Outputs[i - 1]);
            Outputs[i] = sigmoid_mapper(Inputs[i]);
        }

        inputs_end = matrix_multiplication(weight_layes_to_output, Outputs[Outputs.size() - 1]);
        outputs_end = sigmoid_mapper(inputs_end);
        actual_predict = outputs_end[0][0];

        error_layer = actual_predict - expexted_predict;
        gradient_layer = sigmoid(actual_predict) * (1 - sigmoid(actual_predict));
        weight_delta_layer = error_layer * gradient_layer;

        for(size_t i = 0; i < weight_layes_to_output.size(); ++i) {
            for(size_t j = 0; j < weight_layes_to_output[0].size(); ++j) {
                weight_layes_to_output[i][j] -= Outputs[Outputs.size() - 1][j][i] * weight_delta_layer * learning_rate;
            }
        }

        error_of_hidden_layers.resize(weight_layes_to_output.size());
        for(size_t i = 0; i < error_of_hidden_layers.size(); ++i) {
            error_of_hidden_layers[i].resize(weight_layes_to_output[0].size());
            for(size_t j = 0; j < error_of_hidden_layers[i].size(); ++j) {
                error_of_hidden_layers[i][j] = weight_layes_to_output[i][j] * weight_delta_layer;
            }
        }

        gradient_of_hidden_layers.resize(weight_layes_to_output.size());
        for(size_t i = 0; i < gradient_of_hidden_layers.size(); ++i) {
            gradient_of_hidden_layers[i].resize(weight_layes_to_output[0].size());
            for(size_t j = 0; j < gradient_of_hidden_layers[0].size(); ++j) {
                gradient_of_hidden_layers[i][j] = sigmoid(outputs_end[i][j]) * (1 - sigmoid(outputs_end[i][j]));
            }
        }

        weight_delta_of_hidden_layers.resize(weight_layes_to_output.size());
        for(size_t i = 0; i < weight_delta_of_hidden_layers.size(); ++i) {
            weight_delta_of_hidden_layers[i].resize(weight_layes_to_output[0].size());
            for(size_t j = 0; j < weight_delta_of_hidden_layers[0].size(); ++j) {
                weight_delta_of_hidden_layers[i][j] = error_of_hidden_layers[i][j] * gradient_of_hidden_layers[i][j];
            }
        }        

        size_t number_of_layers = Weights.size();
        size_t number_rows = Weights[0].size();
        size_t number_cols = Weights[0][0].size();

        for(size_t i = 0; i < number_rows; ++i) {
            for(size_t j = 0; j < number_cols; ++j) {
                Weights[Weights.size() - 1][i][j] -= Outputs[Outputs.size() - 2][i][j] * weight_delta_of_hidden_layers[0][i] * learning_rate;
            }
        }

        for(int layer = number_of_layers - 2; layer >= 0; --layer) {

            error_of_hidden_layers.resize(number_rows);
            for(size_t i = 0; i < error_of_hidden_layers.size(); ++i) {
                error_of_hidden_layers[i].resize(number_cols);
                for(size_t j = 0; j < error_of_hidden_layers[i].size(); ++j) {
                    error_of_hidden_layers[i][j] = Weights[layer + 1][i][j] * weight_delta_of_hidden_layers[0][i];
                }
            }

            gradient_of_hidden_layers.resize(number_rows);
            for(size_t i = 0; i < gradient_of_hidden_layers.size(); ++i) {
                gradient_of_hidden_layers[i].resize(number_cols);
                for(size_t j = 0; j < gradient_of_hidden_layers[0].size(); ++j) {
                    gradient_of_hidden_layers[i][j] = sigmoid(Outputs[layer][i][j]) * (1 - sigmoid(Outputs[layer][i][j]));
                }
            }

            weight_delta_of_hidden_layers.resize(number_rows);
            for(size_t i = 0; i < weight_delta_of_hidden_layers.size(); ++i) {
                weight_delta_of_hidden_layers[i].resize(number_cols);
                for(size_t j = 0; j < weight_delta_of_hidden_layers[0].size(); ++j) {
                    weight_delta_of_hidden_layers[i][j] = error_of_hidden_layers[i][j] * gradient_of_hidden_layers[i][j];
                }
            } 

            for(size_t i = 0; i < number_rows; ++i) {
                for(size_t j = 0; j < number_cols; ++j) {
                    Weights[layer][i][j] -= Outputs[layer + 1][j][0] * weight_delta_of_hidden_layers[i][j] * learning_rate;
                }
            }

        }

        error_of_hidden_layers.resize(number_rows);
        for(size_t i = 0; i < error_of_hidden_layers.size(); ++i) {
            error_of_hidden_layers[i].resize(number_cols);
            for(size_t j = 0; j < error_of_hidden_layers[i].size(); ++j) {
                error_of_hidden_layers[i][j] = Weights[0][i][j] * weight_delta_of_hidden_layers[0][i];
            }
        }

        gradient_of_hidden_layers.resize(number_rows);
            for(size_t i = 0; i < gradient_of_hidden_layers.size(); ++i) {
                gradient_of_hidden_layers[i].resize(number_cols);
                for(size_t j = 0; j < gradient_of_hidden_layers[0].size(); ++j) {
                    gradient_of_hidden_layers[i][j] = sigmoid(Outputs[0][i][j]) * (1 - sigmoid(Outputs[0][i][j]));
                }
        }

        weight_delta_of_hidden_layers.resize(number_rows);
        for(size_t i = 0; i < weight_delta_of_hidden_layers.size(); ++i) {
            weight_delta_of_hidden_layers[i].resize(number_cols);
            for(size_t j = 0; j < weight_delta_of_hidden_layers[0].size(); ++j) {
                weight_delta_of_hidden_layers[i][j] = error_of_hidden_layers[i][j] * gradient_of_hidden_layers[i][j];
            }
        } 

        for(size_t i = 0; i < weight_input_to_layers.size(); ++i) {
            for(size_t j = 0; j < weight_input_to_layers[0].size(); ++j) {
                weight_input_to_layers[i][j] -= inputs[j][0] * weight_delta_of_hidden_layers[0][i] * learning_rate;
            }
        }

    }

//   private:
    const double learning_rate;
    vector_of_vectors inputs_begin;
    vector_of_vectors outputs_begin;
    vector_of_vectors weight_input_to_layers;
    vector_of_vectors weight_layes_to_output;
    vector_of_vectors inputs_end;
    vector_of_vectors outputs_end;

    vector<vector_of_vectors> Inputs;
    vector<vector_of_vectors> Weights;
    vector<vector_of_vectors> Outputs;

};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    srand(time(NULL));

    const size_t EPOCH = 100;
    const double LERANING_RATE = 0.0005;

    vector<vector<vector<double>>> train = {
        {{0}, {0}},
        {{0}, {1}},
        {{1}, {0}},
        {{1}, {1}}
    };
    
    vector<double> correct_predict = {1, 0, 0, 1};

    Neural_network network(LERANING_RATE, train[0].size(), 8, 5);

    size_t j = 0;
    // for(size_t i = 0; i < EPOCH; ++i) {
        for(size_t j = 0; j < train.size(); ++j) {
            network.train(train[j], correct_predict[j]);
        }
    //     if(i % (EPOCH / 100) == 0 ) {
    //         std::system("cls");
    //         std::cout << "Progress: " << double(i) / EPOCH * 100 << "%\n";
    //         std::cout << "Traning loss: " << std::pow(network.predict(train[j])[0][0] - correct_predict[j], 2) << "\n\n";
    //     }
    // }
    
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