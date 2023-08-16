#include <stdio.h>
#include <string.h>

void decryptSubstitution(const char *ciphertext, const char *key) {
    int ciphertextLength = strlen(ciphertext);

    printf("Decrypted message:\n");

    for (int i = 0; i < ciphertextLength; i++) {
        char decryptedChar = ciphertext[i];

        if (decryptedChar >= 'a' && decryptedChar <= 'z') {
            decryptedChar = key[decryptedChar - 'a'];
        } else if (decryptedChar >= 'A' && decryptedChar <= 'Z') {
            decryptedChar = key[decryptedChar - 'A'] - ('a' - 'A');
        }
        printf("%c", decryptedChar);
    }

    printf("\n");
}

int main() {
    const char *ciphertext = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†860))85;;]8*;:‡*8†83 (88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*-4)88* ;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    const char *key = "KLMNOPQRSTUVWXYZABCDEFGHIJlmnopqrstuvwxyzabcdefghijk";
    
    decryptSubstitution(ciphertext, key);

    return 0;
}

