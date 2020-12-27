#include "matrix.h"
#include "misc.h"
#include <array>
#include <QtMath>

Matrix::Matrix(void) {
    setIdentity();
}

Matrix& Matrix::setIdentity(void) {
    for(int i=0;i<3;i++){ for(int j=0;j<3;j++) {
        mMatrix[i][j]=0;
        mMatrix[j][i]=0;
        mMatrix[i][i]=1;
    } } return *this;
}

float Matrix::multiSize(void) {
    float x = mMatrix[0][0];
    float y = mMatrix[1][0];
    return qSqrt(x*x+y*y)/SQRT_TWO;
}

Point Matrix::multiply(Point point) {
    float x = point.getX()*mMatrix[0][0]+point.getY()*mMatrix[0][1]+mMatrix[0][2];
    float y = point.getX()*mMatrix[1][0]+point.getY()*mMatrix[1][1]+mMatrix[1][2];
    return Point(x, y);
}

std::array<float,3>& Matrix::operator[](int row) {
    return mMatrix[row];
}

vectorType operator * (Matrix &m, vectorType &v) {
    vectorType vout;
    for(int i=0; i < 2; i++) {
        vout.push_back(m[i][0]*v[0]+m[i][1]*v[1]+m[i][2]);
    }
  return vout;
}

Matrix operator* (Matrix& mSrc1, Matrix& mSrc2) {
    Matrix dst;
    float x;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            x = 0.0;
            for (int k=0; k<3; k++){
                x += mSrc1[i][k] * mSrc2[k][j];
            }
            dst[i][j] = x;
        }
    }
    return dst;
}

Matrix Matrix::operator*=(const Matrix& m) {
    this->mMatrix = multiply(m).mMatrix;
    return *this;
}

Matrix Matrix::multiply(const Matrix& m) const {
    Matrix result;
    for(int i=0;i<3;i++){for(int j=0;j<3;j++){
        result.mMatrix[i][j]  = mMatrix[i][0] * m.mMatrix[0][j];
        result.mMatrix[i][j] += mMatrix[i][1] * m.mMatrix[1][j];
        result.mMatrix[i][j] += mMatrix[i][2] * m.mMatrix[2][j];
    } }  return result;
}

void Matrix::rotateCW(float angle) {
    Matrix result;
    result.mMatrix[0][0]=qCos(angle)*mMatrix[0][0]+qSin(angle)* mMatrix[1][0];
    result.mMatrix[0][1]=qCos(angle)*mMatrix[0][1]+qSin(angle)* mMatrix[1][1];
    result.mMatrix[1][0]=-qSin(angle)*mMatrix[0][0]+qCos(angle)* mMatrix[1][0];
    result.mMatrix[1][1]=-qSin(angle)*mMatrix[0][1]+qCos(angle)* mMatrix[1][1];
    mMatrix[0][0]=result.mMatrix[0][0];
    mMatrix[0][1]=result.mMatrix[0][1];
    mMatrix[1][0]=result.mMatrix[1][0];
    mMatrix[1][1]=result.mMatrix[1][1];
}
void Matrix::rotateCCW(float angle) {
    Matrix result;
    result.mMatrix[0][0]=qCos(angle)*mMatrix[0][0]-qSin(angle)* mMatrix[1][0];
    result.mMatrix[0][1]=qCos(angle)*mMatrix[0][1]-qSin(angle)* mMatrix[1][1];
    result.mMatrix[1][0]=qSin(angle)*mMatrix[0][0]+qCos(angle)* mMatrix[1][0];
    result.mMatrix[1][1]=qSin(angle)*mMatrix[0][1]+qCos(angle)* mMatrix[1][1];
    mMatrix[0][0]=result.mMatrix[0][0];
    mMatrix[0][1]=result.mMatrix[0][1];
    mMatrix[1][0]=result.mMatrix[1][0];
    mMatrix[1][1]=result.mMatrix[1][1];
}
void Matrix::place(float x,float y) {
    mMatrix[0][2]=x;
    mMatrix[1][2]=y;
}
void Matrix::move(float x,float y) {
    mMatrix[0][2]+=x;
    mMatrix[1][2]+=y;
}
void Matrix::scale(float k) {
    mMatrix[0][0]*=k;
    mMatrix[0][1]*=k;
    mMatrix[0][2]*=k;
    mMatrix[1][0]*=k;
    mMatrix[1][1]*=k;
    mMatrix[1][2]*=k;
}

float Matrix::getScaleFactor(Matrix& m) {
    float det = std::abs(m[0][0]*m[1][1]- m[1][0]*m[0][1]);
    return std::sqrt(det);
}
