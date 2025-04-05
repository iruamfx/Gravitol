#include <iostream>
#include <cmath>

struct Vec2 {
    float x, y;

    // Vector addition
    Vec2 operator+(const Vec2& other) const { return {x + other.x, y + other.y}; } // Overloads the + operator for Vec2 objects. a.operator+(b)

    // Vector subtraction
    Vec2 operator-(const Vec2& other) const { return {x - other.x, y - other.y}; }

    // Scalar multiplication
    Vec2 operator*(float scalar) const { return {x * scalar, y * scalar}; }

    // Print
    void print() const { std::cout << "(" << x << ", " << y << ")\n"; } // func() const {} defines the current object as read-only inside the body. The body accesses a const Vec2& this;

    //const Vec2* ptr: prohibits modifications to the referenced object, not the reference. To prohibit changes to the reference explicity: Vec2* const ptr
};

int main(){
    const float tstep = 0.016f; // 1 second / 60 frames = 0.016 seconds per frame
    const float tstep2 = pow(tstep, 2); // Seconds squared

    Vec2 prevPos = {0.0f, 0.0f}; // n[n-1]
    Vec2 currPos = {0.0f, 5.0f}; // n[n]
    // Aggregate constructors ^ {}

    Vec2 accel = {0.0f, -9.81f}; // a[n]

    for (int i = 0; i < 100; ++i) { // 100 iterations of simulation

        // x[n+1] = 2 * x[n] - x[n-1] + a[n] * t^2
        Vec2 nextPos = currPos * 2.0f - prevPos + accel * tstep2;

        // Output current position
        std::cout << "t = " << i * tstep << " s: "; // Position for any tstep t
        currPos.print();

        // Update positions for next iteration
        prevPos = currPos;
        currPos = nextPos;
    }
}