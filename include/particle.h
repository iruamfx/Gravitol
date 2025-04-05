#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <cmath>

struct Vec2 {
    float x, y;

    Vec2 operator+(const Vec2& other) const; // Vector non-mutable addition
    Vec2 operator-(const Vec2& other) const; // Vector mutable addition
    Vec2 operator*(float scalar) const; // Vector subtraction
    Vec2 operator/(float scalar) const; // Scalar multiplication
    Vec2 operator+=(const Vec2& other); // Scalar division

    void print() const;
};

struct Particle {
    Vec2 position;
    Vec2 previousPosition;
    Vec2 acceleration;
    Particle(Vec2 pos, Vec2 velocity, float initDt) { 
        position = pos;
        previousPosition = pos - velocity * initDt; // Based on the current position, the velocity, and the initial delta T, calculate prevPos
        acceleration = {0.0f, 0.0f};
    }

    void update(float dt);
    Vec2 getVelocity(float dt) const;
};


#endif