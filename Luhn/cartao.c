#include <stdio.h>
#include <stdlib.h>

int main() {
  int entradas;

  scanf("%d", &entradas);

  for (int i = 0; i < entradas; i++) {
    long numero;

    scanf("%ld", &numero);

    long *vetor_numero = (long *)malloc(sizeof(long) * 16);

    for (int i = 15; i >= 0; i--) {
      vetor_numero[i] = numero % 10;
      numero /= 10;
    }

    int soma1 = 0;
    for (int i = 14; i >= 0; i -= 2) {
      long produto = vetor_numero[i] * 2;

      if (produto / 10 > 0) {
        int digito1 = produto % 10;
        int digito2 = produto / 10;

        soma1 += (digito1 + digito2);

        continue;
      }

      soma1 += produto;
    }

    int soma2 = 0;
    for (int i = 1; i <= 15; i += 2) {
      soma2 += vetor_numero[i];
    }

    int soma_final = soma1 + soma2;

    soma_final % 10 == 0 ? printf("Cartão válido\n") : printf("Cartão inválido\n");
  }

  return 0;
}
