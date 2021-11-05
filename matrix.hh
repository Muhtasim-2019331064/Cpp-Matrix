#ifndef _matrix_hh_by_muhtasim_
#define _matrix_hh_by_muhtasim_

#define integer long long

class matrix {
private:
    double** _matrix;
    integer row;
    integer column;

public:
    explicit matrix(integer r, integer c);
    ~matrix();

    // Matrix& operator= (Matrix mat);
    // Matrix  operator+ (Matrix mat);
    // Matrix  operator- (Matrix mat);
    // Matrix  operator* (Matrix mat);
    // Matrix  operator/ (Matrix mat);
    // double& operator[](Matrix mat);
};

#endif