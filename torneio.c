#include <stdio.h>

int main() {
    char resultado;
    int V = 0;
    int i = 0;

    while (i < 6) {
        scanf(" %c", &resultado);
        if (resultado == 'V') V++;
        i++;
    }

    if (V >= 5) {
        printf("1\n");
    } else if (V >= 3) {
        printf("2\n");
    } else if (V >= 1) {
        printf("3\n");
    } else {
        printf("-1\n");
    }

    return 0;
}
