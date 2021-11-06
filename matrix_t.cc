#include "matrix_t.hh"

matrix_t::matrix_t(integer r, integer c) {
    if (r < 1 || c < 1) {
        dimension_error;
        stop;
    }

    row    = r;
    column = c;
    matrix = new double* [row];

    for (integer i = 0; i < row; ++i) {
        matrix[i] = new double[column];
    }

    for (integer i = 0; i < row; ++i) {
        for (integer j = 0; j < column; ++j) {
            matrix[i][j] = 0;
        }
    }
}

// matrix_t::matrix_t(std::initializer_list<std::initializer_list<double>> mat) {
//     integer prev = -1;

//     /*
//     - Checking for the validity of the matrix dimensions by comparing the size of each row with the previous one.
//     */

//     for (std::initializer_list<double> mat_row: mat) {
//         if (prev != -1 && prev != mat_row.size()) {
//             row_size_error;
//             stop;
//         }

//         prev = mat_row.size();
//     }

//     row    = mat.size();
//     column = mat.begin()->size();

//     matrix = new double* [row];

//     for (integer i = 0; i < row; ++i) {
//         matrix[i] = new double[column];
//     }

//     integer i = 0, j = 0;

//     for (std::initializer_list<double> mat_row: mat) {
//         for (double el: mat_row) {
//             matrix[i][j] = el;
//             ++j;
//         }

//         ++i;
//     }
// }

matrix_t::matrix_t(matrix_t& mat) {
    for (integer i = 0; i < row; ++i) {
        for (integer j = 0; j < column; ++j) {
            this->at(i, j) = mat.at(i, j);
        }
    }
}

matrix_t::~matrix_t() {
    for (integer i = 0; i < row; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

integer matrix_t::row_count() {
    return row;
}

integer matrix_t::column_count() {
    return column;
}

double& matrix_t::at(integer i, integer j) {
    if (i < 0 || j < 0 || i >= row || j >= column) {
        indexing_error;
        stop;
    }
    
    return matrix[i][j];
}

double* matrix_t::operator[](integer r) {
    return matrix[r];
}

std::ostream& operator<<(std::ostream& output, matrix_t& mat) {
    for (integer i = 0; i < mat.row_count(); ++i) {
        for (integer j = 0; j < mat.column_count(); ++j) {
            output << mat.at(i, j) << " ";
        }

        if (i < mat.row_count()-1) {
            output << "\n";
        }
    }

    return output;
}