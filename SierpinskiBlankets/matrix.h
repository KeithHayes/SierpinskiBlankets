#ifndef MATRIX_H
#define MATRIX_H

#include "point.h"
#include <array>
#include <vector>
#include <QtWidgets>

typedef std::array<std::array<float,3>,3>  matrixType;
typedef std::vector<float>  vectorType;

class Matrix
{

private:
    std::array<std::array<float,3>,3> mMatrix;


public:
    Matrix(void);

    std::array<float,3>& operator[](int row);
    void setMval(IntPoint p, float value) { mMatrix[p.getX()][p.getY()] = value; }
    float getCoeff(IntPoint p) { return mMatrix[p.getX()][p.getY()]; }

    int size(void){ return 3;};
    matrixType getMatrix(void) {return mMatrix;};

    void setMatrix(std::array<std::array<float,3>,3> m){ mMatrix = m; };
    void setMatrix(Matrix m){ mMatrix= m.mMatrix; };

    Matrix& setIdentity(void);
    float multiSize(void);
    Point multiply(Point point);
    Matrix multiply(const Matrix& m) const;
    void rotateCW(float);
    void rotateCCW(float);
    void place(float,float);
    void move(float,float);
    void scale(float);
    float getScaleFactor(Matrix& m);
    friend vectorType operator* (Matrix &, vectorType &);
    friend Matrix operator* (Matrix &, Matrix &);
    Matrix operator*=(const Matrix& m);
};



#endif
