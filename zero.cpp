#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    int numero;
    std::vector<int> numeros;
    int soma = 0.;

    for (int i = 0; i < N; i++) {
        std::cin >> numero;
        if (numero != 0) {
            numeros.push_back(numero);
        } else {
            numeros.pop_back();
        }
    }

    for (unsigned int i = 0; i < numeros.size(); i++) {
        soma += numeros[i];
    }

    std::cout << soma << std::endl;

    return 0;
}
