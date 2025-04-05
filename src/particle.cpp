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
    Vec2 nextPrevPosTemp = position; // Is not freed since it will be continuously used
    position = position * 2.0f - previousPosition + acceleration * (0.5 * dt * dt);
    // ^ Equals pos = pos + (pos - prevPos) + accel * pow(dt, 2). 
    // The middle term is numerically equal to velocity * dt - which is defined in the classical formula -, since velocity = pos - prevPos / dt.
    // It is common practice to omit the denominator 2 in accel * dt^2 for performance. Performance mode TBD
    previousPosition = nextPrevPosTemp;
    acceleration = {0.0f, 0.0f}; // reset acceleration
}

Vec2 Particle::getVelocity(float dt) const {
    return (position - previousPosition) / dt;
}

#endif