#include <stdio.h>
#include <math.h>

double factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int matrix_size = 5;
    double unique_keys = factorial(matrix_size * matrix_size) / pow(matrix_size, matrix_size);
    
    printf("Approximate effective key space considering row/column swapping: %.0f\n", unique_keys);

    return 0;
}

