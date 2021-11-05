#include "matrix.hh"

matrix::matrix(integer r, integer c) {
    row    = r;
    column = c;
    _matrix = new double* [row];

    for (integer i = 0; i < row; ++i) {
        _matrix[i] = new double[column];
    }
}

matrix::~matrix() {
    for (integer i = 0; i < row; ++i) {
        delete[] _matrix[i];
    }

    delete[] _matrix;
}