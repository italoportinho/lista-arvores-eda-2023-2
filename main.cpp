// Copyright (C) 2023 - Italo Portinho
// Para compilar(windows): g++ main.cpp -o main
#include <cstdio>
#include "./arvore.hpp"

int main() {
    int const MAX_N = 9;
    int vetor[MAX_N] = { 10, 20, 15, 12, 8, 5, 7, 1, 2 };

    Arvore minha_arvore = {};
    NoArvore* level_4_2 = new NoArvore { .dado = vetor[8], .esq = 0, .dir = 0 };
    NoArvore* level_4_1 = new NoArvore { .dado = vetor[7], .esq = 0, .dir = 0 };
    NoArvore* level_3_4 = new NoArvore { .dado = vetor[6], .esq = 0, .dir = 0 };
    NoArvore* level_3_3 = new NoArvore { .dado = vetor[5], .esq = 0, .dir = 0 };
    NoArvore* level_3_2 = new NoArvore { .dado = vetor[4], .esq = 0, .dir = 0 };
    NoArvore* level_3_1 = new NoArvore { .dado = vetor[3], .esq = level_4_1, .dir = level_4_2 };
    NoArvore* level_2_2 = new NoArvore { .dado = vetor[2], .esq = level_3_3, .dir = level_3_4 };
    NoArvore* level_2_1 = new NoArvore { .dado = vetor[1], .esq = level_3_1, .dir = level_3_2 };
    NoArvore* level_1_1 = new NoArvore { .dado = vetor[0], .esq = level_2_1, .dir = level_2_2 };
    minha_arvore.raiz = level_1_1;

    printf("Soma folhas = %d \n", soma_folhas(minha_arvore.raiz, 0));
    printf("\nPos-ordem = \n");
    pos_ordem(minha_arvore.raiz);
    printf("\nEm-ordem = \n");
    em_ordem(minha_arvore.raiz);
    printf("\nPre-ordem = \n");
    pre_ordem(minha_arvore.raiz);
    printf("altura no raiz: %d\n", calculaAltura(minha_arvore.raiz, 0));
    percorre_niveis(minha_arvore.raiz);
    printf("Produto == %d ", produto_nos(minha_arvore.raiz, 1));
    printf("Balanceamento(raiz) == %d ", balanceamento_no(minha_arvore.raiz));
}
