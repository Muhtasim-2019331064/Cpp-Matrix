#ifndef _matrix_t_hh_by_muhtasim_
#define _matrix_t_hh_by_muhtasim_

#include <cstdlib>
#include <iostream>
#include <initializer_list>

#define integer          long long
#define stop             exit(1)

#define err              "   ERROR:    "

#define dimension_error  std::cerr << err << "Invalid dimension(s). Dimensions must be positive integers." << std::endl
#define indexing_error   std::cerr << err << "Tried accessing invalid position." << std::endl;
#define equality_error   std::cerr << err << "The dimensions of the matrices are not same." << std::endl;
#define row_size_error   std::cerr << err << "The rows are not of same size." << std::endl;

class matrix_t {
private:
    double** matrix;
    integer row;
    integer column;

public:
    explicit matrix_t(integer r, integer c);
    matrix_t(std::initializer_list<std::initializer_list<double>> mat);
    matrix_t(matrix_t& mat);
    ~matrix_t();

    integer row_count();
    integer column_count();
    double& at(integer i, integer j);

    double*  operator[](integer r);
    matrix_t operator+ (matrix_t mat);
    // matrix_t  operator- (matrix_t mat);
    // matrix_t  operator* (matrix_t mat);
    // matrix_t  operator/ (matrix_t mat);

    friend std::ostream& operator<<(std::ostream& output, matrix_t& mat);
};

#endif
