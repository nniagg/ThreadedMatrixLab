#include <iostream>
#include "matrix.hpp"
// #include <thread>



int main() {

    matrix M_1(2, 3);
    std::vector<std::vector<double> > values_1 = {{1, 2, 3},
                                                 {4, 5, 6}};
    M_1 = values_1;

    matrix M_2(3, 3);
    std::vector<std::vector<double> > values_2 = {{1, 2, 3},
                                                 {4, 5, 6},
                                                 {7, 8, 9}};
    M_2 = values_2;

    matrix M_mul_parallel(3, 3);
    M_mul_parallel = matrix::mul_parallel(M_1, M_2);
    std::cout << M_mul_parallel.to_string();


    // // Get the number of available threads (CPU cores)
    // unsigned int num_threads = std::thread::hardware_concurrency();

    // // Print the number of available threads
    // std::cout << "Number of available threads: " << num_threads << std::endl;




    return 0;

}