#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

void draw_torus(float R, float r, float angle) {
    int i, j;
    for (i = 0; i < 360; i += 10) {
        for (j = 0; j < 360; j += 10) {
            float theta = i * PI / 180;
            float phi = j * PI / 180;
            float x = (R + r * cos(phi)) * cos(theta);
            float y = (R + r * cos(phi)) * sin(theta);
            float z = r * sin(phi);

            // Rotate the torus around the y-axis
            float new_x = x * cos(angle) - z * sin(angle);
            float new_z = x * sin(angle) + z * cos(angle);

            printf("(%f, %f, %f)\n", new_x, y, new_z);
        }
    }
}

int main() {
    float R = 3.0; // major radius
    float r = 1.0; // minor radius
    float angle = 0.1; // rotation angle in radians

    draw_torus(R, r, angle);

    return 0;
}
