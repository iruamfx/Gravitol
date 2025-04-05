#include <iostream>
#include <cmath>
#include "particle.h"

int main(){
    const float dt = 0.016f; // 1 second / 60 frames = 0.016 seconds per frame
    const Vec2 gravity = {0.0f, -9.81f};

    Particle ptc = {{0.0f, 5.0f}, {0.0f, 5.0f}, dt};

    for (int i = 0; i < 100; ++i) { // 100 iterations of simulation
        // Output current position
        ptc.acceleration += gravity;

        std::cout << "t = " << i * dt << " s: "; // Position for any dt

        ptc.position.print();

        ptc.update(dt);
    }
}