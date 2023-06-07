#include <stdio.h>

int main() {
    float coords[9][2] = { 0 };
    float sum[2];

    while (i < 2) {
        scanf("%d%d", &coords[i][0], coords[i][1]);
        sum[0] += coords[i][0];
        sum[1] += coords[i][1];
    }

    printf("Average coordinate: (%.2d, %.2d)\n", sum[0], sum[1]);

    return 0;
}
