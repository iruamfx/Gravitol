#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <cmath>

#ifdef REALISTIC
const float G = 6.67430e-11f; // Gravitational constant
#else
const float G = 1.0f;
#endif

struct Vec2 {
    float x, y;

    Vec2 operator+(const Vec2& other) const; // Vector non-mutable addition
    Vec2 operator+=(const Vec2& other); // Vector mutable addition
    Vec2 operator-(const Vec2& other) const; // Vector subtraction
    Vec2 operator*(float scalar) const; // Scalar multiplication
    Vec2 operator/(float scalar) const; // Scalar division

    float length() const {
        return std::sqrt(x * x + y * y);
    }

    Vec2 normalized() const {
        float len = length();
        if(len == 0.0f) { return {0.0f, 0.0f}; }
        return {x / len, y / len};
    }

    void print() const;
};

struct Particle {
    Vec2 pos;
    Vec2 velocity;
    Vec2 accel;
    float mass;

    Particle(Vec2 position, Vec2 velocity, float m, Vec2 initaccel = {0.0f, 0.0f}) : pos(position), velocity(velocity), accel(initaccel), mass(m) {}

    void update(float dt);
    void update(float dt, const Vec2& naccel);
    void applyForce(const Vec2& force);
};


#endif