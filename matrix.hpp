#ifndef PARALLEL_MATRIX_LIBRARY_H
#define PARALLEL_MATRIX_LIBRARY_H

#include <stddef.h>
#include <vector>
#include <sstream>

class matrix {

private:
    std::vector<std::vector<double> > data;
    size_t rows;
    size_t cols;

public:

    explicit matrix(size_t row_num, size_t col_num, double initial = 0.0) {
    rows = row_num;
    cols = col_num;
    data.resize(row_num, std::vector<double>(col_num, initial));

}

    size_t get_cols() const { return cols; }

    size_t get_rows() const { return rows; }

    double &operator()(size_t i, size_t j) {
        return data[i][j];
    }

    const double &operator()(size_t i, size_t j) const {
        return data[i][j];
    }

    std::string to_string() {
    std::string result;
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            result += std::to_string(data[i][j]);
            if (j < data[i].size() - 1) {
                result += "\t\t";
            }
        }
        result += "\n";
    }
    return result;
}


    matrix &operator=(const std::vector<std::vector<double> > &init_values);

    static matrix add(const matrix &m1, const matrix &m2);

    static matrix sub(const matrix &m1, const matrix &m2);

    static matrix mul(const matrix &m1, const matrix &m2);

    static matrix inverse(const matrix &m1);

    static matrix inverse_parallel(const matrix &m1);

    static matrix sub_parallel(const matrix &m1, const matrix &m2);

    static matrix add_parallel(const matrix &m1, const matrix &m2);

    static matrix mul_parallel(const matrix &m1, const matrix &m2);
};


#endif // PARALLEL_MATRIX_LIBRARY_H