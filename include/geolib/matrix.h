#ifndef GEOLIB_MATRIX_H_
#define GEOLIB_MATRIX_H_

#include <ostream>

namespace geo {

class Vector3 {

    friend class Matrix3x3;

public:

    Vector3() {}

    Vector3(float x, float y, float z) {
        v_[0] = x;
        v_[1] = y;
        v_[2] = z;
    }

    friend std::ostream& operator<< (std::ostream& out, const Vector3& v) {
        out << "[ " << v.v_[0] << " " << v.v_[1] << " " << v.v_[2] << " ]";
        return out;
    }

protected:

    float v_[3];
};

class Matrix3x3 {

public:

    Matrix3x3() {}

    Matrix3x3(float m11, float m12, float m13,
              float m21, float m22, float m23,
              float m31, float m32, float m33) //:
//        m_{m11, m12, m13, m21, m22, m23, m31, m32, m33}
    {
        m_[0]= m11;
        m_[1]= m12;
        m_[2]= m13;
        m_[3]= m21;
        m_[4]= m22;
        m_[5]= m23;
        m_[6]= m31;
        m_[7]= m32;
        m_[8]= m33;
    }

    Matrix3x3 operator*(const Matrix3x3& n) {
        return Matrix3x3(m_[0]*n.m_[0]+m_[1]*n.m_[3]+m_[2]*n.m_[6], m_[0]*n.m_[1]+m_[1]*n.m_[4]+m_[2]*n.m_[7], m_[0]*n.m_[2]+m_[1]*n.m_[5]+m_[2]*n.m_[8],
                         m_[3]*n.m_[0]+m_[4]*n.m_[3]+m_[5]*n.m_[6], m_[3]*n.m_[1]+m_[4]*n.m_[4]+m_[5]*n.m_[7], m_[3]*n.m_[2]+m_[4]*n.m_[5]+m_[5]*n.m_[8],
                         m_[6]*n.m_[0]+m_[7]*n.m_[3]+m_[8]*n.m_[6], m_[6]*n.m_[1]+m_[7]*n.m_[4]+m_[8]*n.m_[7], m_[6]*n.m_[2]+m_[7]*n.m_[5]+m_[8]*n.m_[8]);
    }

    Vector3 operator*(const Vector3& v) {
        return Vector3(m_[0]*v.v_[0]+m_[1]*v.v_[1]+m_[2]*v.v_[2],
                       m_[3]*v.v_[0]+m_[4]*v.v_[1]+m_[5]*v.v_[2],
                       m_[6]*v.v_[0]+m_[7]*v.v_[1]+m_[8]*v.v_[2]);
    }

    friend std::ostream& operator<< (std::ostream& out, const Matrix3x3& m) {
        out << "[ " << m.m_[0] << " " << m.m_[1] << " " << m.m_[2] << std::endl
                    << m.m_[3] << " " << m.m_[4] << " " << m.m_[5] << std::endl
                    << m.m_[6] << " " << m.m_[7] << " " << m.m_[8] << " ]";
        return out;
    }

protected:

    float m_[9];

};

}

#endif