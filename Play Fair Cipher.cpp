#include <stdio.h>
#include <string.h>

int main() {
    char key[26], matrix[5][5];
    char message[100];
    int len, k = 0;
    
    printf("Enter the key: ");
    scanf("%s", key);
    
    len = strlen(key);
    
    for (int i = 0; i < len; ++i) {
        int isDuplicate = 0;
        if (key[i] == 'j') key[i] = 'i';
        for (int j = 0; j < i; ++j) {
            if (key[i] == key[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            matrix[k / 5][k % 5] = key[i];
            ++k;
        }
    }
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (ch != 'j') {
            int isDuplicate = 0;
            for (int i = 0; i < len; ++i) {
                if (ch == key[i]) {
                    isDuplicate = 1;
                    break;
                }
            }
            if (!isDuplicate) {
                matrix[k / 5][k % 5] = ch;
                ++k;
            }
        }
    }
    
    printf("Enter the message: ");
    scanf("%s", message);
    
    len = strlen(message);
    for (int i = 0; i < len; i += 2) {
        char a = message[i], b = message[i + 1];
        int row1, col1, row2, col2;
        
        for (int r = 0; r < 5; ++r) {
            for (int c = 0; c < 5; ++c) {
                if (matrix[r][c] == a) {
                    row1 = r;
                    col1 = c;
                }
                if (matrix[r][c] == b) {
                    row2 = r;
                    col2 = c;
                }
            }
        }
        
        if (row1 == row2) {
            ++col1;
            ++col2;
            col1 %= 5;
            col2 %= 5;
        } else if (col1 == col2) {
            ++row1;
            ++row2;
            row1 %= 5;
            row2 %= 5;
        } else {
            int temp = col1;
            col1 = col2;
            col2 = temp;
        }
        
        printf("%c%c", matrix[row1][col1], matrix[row2][col2]);
    }
    
    return 0;
}
