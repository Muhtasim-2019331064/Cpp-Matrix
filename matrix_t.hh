#ifndef _matrix_t_hh_by_muhtasim_
#define _matrix_t_hh_by_muhtasim_

#include <cstdlib>
#include <iostream>
#include <initializer_list>

#define integer          long long
#define stop             exit(1)

#define err              "   ERROR:    "

#define dimension_error  std::cerr << err << "Invalid dimension(s). Dimensions must be non-negative integers." << std::endl
#define indexing_error   std::cerr << err << "Tried accessing invalid position." << std::endl;
#define equality_error   std::cerr << err << "The dimensions of the matrices are not same." << std::endl;
#define row_size_error   std::cerr << err << "The rows of a matrix must have the same size." << std::endl;

class matrix_t {
private:
    double** matrix;
    integer row;
    integer column;

public:
    matrix_t(integer r = 0, integer c = 0);
    matrix_t(const std::initializer_list<std::initializer_list<double>>& mat);
    matrix_t(const matrix_t& mat);
    ~matrix_t();

    matrix_t operator=(const matrix_t& other);
    matrix_t operator+(const matrix_t& other);
    // matrix_t operator- (matrix_t mat);
    // matrix_t operator* (matrix_t mat);
    // matrix_t operator/ (matrix_t mat);
    bool operator==(const matrix_t& other) const;
    double* operator[](integer r);     // Not memory safe, mutable.....

    double at(integer i, integer j) const;   // Memory safe, immutable....
    integer row_count() const;
    integer column_count() const;
};

#endif
