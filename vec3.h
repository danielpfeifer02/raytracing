//
// Created by Daniel Pfeifer on 3/5/23.
//

#ifndef RAYTRACING_VEC3_H
#define RAYTRACING_VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
public:
    vec3() : e{0,0,0} {}
    vec3(double e0, double e1, double e2) : e{e0,e1,e2} {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    vec3 operator-() { return vec3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) {return e[i]; }

    vec3& operator+=(const vec3 &other) {
        e[0] += other.e[0];
        e[1] += other.e[1];
        e[2] += other.e[2];
        return *this;
    }

    vec3& operator*=(const double scalar) {
        e[0] *= scalar;
        e[1] *= scalar;
        e[2] *= scalar;
        return *this;
    }

    vec3& operator/=(const double scalar) {
        return *this *= 1/scalar;
    }

    double length() {
        return sqrt(length_squared());
    }

    double length_squared() {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

private:
    double e[3];

};

// Type aliases for vec3
using point3 = vec3;
using color = vec3;


// vec3 utility functions

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

inline vec3 operator*(const double scalar, const vec3 &v) {
    return vec3(v.x() * scalar, v.y() * scalar, v.z() * scalar);
}

inline vec3 operator*(const vec3 &v, const double scalar) {
    return scalar * v;
}

inline vec3 operator/(const vec3 &v, const double scalar) {
    return (1/scalar) * v;
}

inline double dot(const vec3 &u, const vec3 &v) {
    return  u.x() * v.x() +
            u.y() * v.y() +
            u.z() * v.z();
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(
            u.y() * v.z() - u.z() * v.y(),
            u.z() * v.x() - u.x() * v.z(),
            u.x() * v.y() - u.y() * v.x()
            );
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

#endif //RAYTRACING_VEC3_H
