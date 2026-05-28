#include <stdio.h>

struct NoDuplo {
    struct NoDuplo *anterior;
    int dado;
    struct NoDuplo *proximo;
};

int verificarIntegridade(struct NoDuplo *head) {
    struct NoDuplo *atual = head;
    
    while (atual != NULL && atual->proximo != NULL) {
        if (atual->proximo->anterior != atual) {
            return 0;
        }
        atual = atual->proximo;
    }
    
    return 1;
}

int main() {
    struct NoDuplo n1, n2, n3;

    n1.dado = 10;
    n1.anterior = NULL;
    n1.proximo = &n2;

    n2.dado = 20;
    n2.anterior = &n1;
    n2.proximo = &n3;

    n3.dado = 30;
    n3.anterior = &n2;
    n3.proximo = NULL;

    printf("Resultado: %d\n", verificarIntegridade(&n1));

    n2.anterior = NULL; 

    printf("Resultado apos quebra: %d\n", verificarIntegridade(&n1));

    return 0;
}
