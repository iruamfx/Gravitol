#ifndef PARTICLE
#define PARTICLE

#include "particle.h"

Vec2 Vec2::operator+(const Vec2& other) const { return { x + other.x, y + other.y }; } // Overloads the + operator for Vec2 objects. a.operator+(b)
Vec2 Vec2::operator+=(const Vec2& other) { x += other.x; y += other.y; return *this; } // Returns the dereferenced object(pointer): *this
Vec2 Vec2::operator-(const Vec2& other) const { return { x - other.x, y - other.y }; } 
Vec2 Vec2::operator*(float scalar) const { return { x * scalar, y * scalar }; } 
Vec2 Vec2::operator/(float scalar) const { return { x / scalar, y / scalar }; }
void Vec2::print() const {std::cout << "(" << x << ", " << y << ")\n";}

void Particle::update(float dt) {
    pos += velocity * dt + accel * (0.5 * pow(dt, 2));

    velocity += accel * dt;
    // Constant acceleration.

}

void Particle::update(float dt, const Vec2& naccel) {
    pos += velocity * dt + accel * (0.5 * pow(dt, 2));

    velocity += (accel + naccel) * dt * 0.5f;
    // Velocity is the average between the increment of both accelerations for a given t (dt)
    // Average smoothens the transition between accelerations for low-jerks. High jerks require another algorithm

    accel = naccel;
}

void Particle::applyForce(const Vec2& force) {
    accel += force * (1.0f / mass); // Newton's second law. F = M * A
}

#endif