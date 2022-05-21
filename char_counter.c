#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char** text_array = (char**) malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        text_array[i] = (char*) malloc(sizeof(char) * 256);
        scanf("%s", text_array[i]);
    }
    
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        int j = 0;
        
        while (text_array[i][j] != '\0') {
            j++;
        }
        
        printf("Tamanho da string[%d] = %d\n", i, j);
    }

    return 0;
}
