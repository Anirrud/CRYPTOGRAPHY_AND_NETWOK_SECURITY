#include <stdio.h>

int main() {
    int keyMatrix[3][3];
    int messageVector[3];

    printf("Enter the 3x3 key matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &keyMatrix[i][j]);
        }
    }

    printf("Enter the message vector (3 numbers):\n");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &messageVector[i]);
    }

    int cipherVector[3] = {0}; 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cipherVector[i] += keyMatrix[i][j] * messageVector[j];
        }
    }

    for (int i = 0; i < 3; i++) {
        cipherVector[i] %= 26;
    }
    
    printf("Encrypted message: ");
    for (int i = 0; i < 3; i++) {
        printf("%c", cipherVector[i] + 'A');
    }
    printf("\n");

    return 0;
}
