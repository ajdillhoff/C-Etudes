#include <stdio.h>

int main() {
    float coords[10][2] = { 0 };
    float sum[2] = { 0 };
    int i = 0; // Must declare the index variable.

    while (i < 10) {  // Read 10 sets of coordinates.
        scanf("%f%f", &coords[i][0], &coords[i][1]); // Read `float` values
        sum[0] += coords[i][0];
        sum[1] += coords[i][1];
    }

    // Compute the average
    sum[0] /= 10;
    sum[1] /= 10;

    printf("Average coordinate: (%.2f, %.2f)\n", sum[0], sum[1]);  // Print `float` values

    return 0;
}
