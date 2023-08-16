#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char key[100];
    char plaintext[100];
    char ciphertext[100];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    int keyLength = strlen(key);
    int plaintextLength = strlen(plaintext);

    for (int i = 0, j = 0; i < plaintextLength; i++) {
        char currentChar = plaintext[i];
        if (isalpha(currentChar)) {
            int keyShift = toupper(key[j % keyLength]) - 'A';
            if (islower(currentChar)) {
                ciphertext[i] = (currentChar - 'a' + keyShift) % 26 + 'a';
            } else {
                ciphertext[i] = (currentChar - 'A' + keyShift) % 26 + 'A';
            }
            j++;
        } else {
            ciphertext[i] = currentChar;
        }
    }
    ciphertext[plaintextLength] = '\0';

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
