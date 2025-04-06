#include <iostream>
#include <cmath>
#include <vector>
#include "particle.h"


Vec2 computeGravitationalForce(const Particle& ptc1, const Particle& ptc2) { // Must be allocated to a World class in the future
    Vec2 dir = ptc2.pos - ptc1.pos;
    float dist = std::max(dir.length(), 1.0f); // Distance will be at least 1.0f
    float forceMagnitude = (G * ptc1.mass * ptc2.mass) / pow(dist, 2);
    return dir.normalized() * forceMagnitude;
}

//const float dt = 0.016f; // 1 second / 60 frames = 0.016 seconds per frame
//const Vec2 gravity = {0.0f, -9.81f};
const float dt = 0.01f;

std::vector<Particle> particles = { // Must be allocated to a World class in the future
    // Particle({0.0f, 0.0f}, {0.0f, 0.0f}, 5e10f), // Heavy stationary object
    // Particle({100.0f, 0.0f}, {0.0f, 300.0f}, 1e3f) // Light object in motion
    #ifdef REALISTIC
    Particle({0.0f, 0.0f}, {0.0f, 0.0f}, 5.972e24f), // Terra
    Particle({6.771e6f, 0.0f}, {0.0f, 7670.0f}, 1000.0f) // Satélite na órbita baixa
    #else 
    Particle({0.0f, 0.0f}, {0.0f, 0.0f}, 1000.0f),
    Particle({10.0f, 0.0f}, {0.0f, 7.0f}, 1.0f)
    #endif
};

int main(){
    for (int frame = 0; frame < 2000; ++frame) { // 100 iterations of simulation
        // Output current position
        std::vector<Vec2> netAccelerations(particles.size(), {0.0f, 0.0f}); // Creates a vector the size of particles, and initializes all components to {0.0f, 0.0f}

        for(size_t i = 0; i < particles.size(); ++i)
        {
            for (size_t j = 0; j < particles.size(); ++j) {
                if (i == j) continue; // Does not calculate forces with itself
                Vec2 force = computeGravitationalForce(particles[i], particles[j]);
                netAccelerations[i] += force * (1.0f / particles[i].mass); // F = M * A -> A = F / M
            }
        }

        for (size_t i = 0; i < particles.size(); ++i) { // Applies the obtained accelerations to the simulation of each particle
            particles[i].update(dt, netAccelerations[i]);
            std::cout << "Particle N: " << i << " t = " << frame * dt << " s: ";
            particles[i].pos.print();
        }
    }
}