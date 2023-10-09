// Copyright (C) 2023 - Italo Portinho
#include <cstdio>
#include <algorithm>
class NoArvore {
 public:
    int dado;
    NoArvore* esq;
    NoArvore* dir;
};

class Arvore {
 public:
    NoArvore* raiz;
};

//-------------------------------------------------------------------
//  a)      Computar a soma das folhas
//-------------------------------------------------------------------
int soma_folhas(NoArvore* no, int soma) {
    if (no->esq == 0 && no->dir == 0) {
        printf("Folha = %d \n", no->dado);
        printf("Soma era = %d \n", soma);
        soma = soma + no->dado;
        printf("Soma agora e = %d \n", soma);
    } else {
        soma = soma_folhas(no->esq, soma);
        soma = soma_folhas(no->dir, soma);
    }
    return soma;
}

void soma_folhas_alt(NoArvore* no, int &soma) {
    if (no->esq == 0 && no->dir == 0) {
        printf("Folha = %d \n", no->dado);
        printf("Soma era = %d \n", soma);
        soma = soma + no->dado;
        printf("Soma agora e = %d \n", soma);
    } else {
        if (no->esq != 0) {
            soma_folhas_alt(no->esq, soma);
        }
        if (no->dir != 0) {
            soma_folhas_alt(no->dir, soma);
        }
    }
}

//-------------------------------------------------------------------
//  b)      Percurso em pós-ordem (esq, dir, nó)
//-------------------------------------------------------------------
void pos_ordem(NoArvore* no) {
    if (no->esq) {
        pos_ordem(no->esq);
    }
    if (no->dir) {
        pos_ordem(no->dir);
    }
    printf("%d ", no->dado);
    return;
}

//-------------------------------------------------------------------
//  c)      Percurso em-ordem (esq, no, dir)
//-------------------------------------------------------------------
void em_ordem(NoArvore* no) {
    if (no->esq) {
        em_ordem(no->esq);
    }
    printf("%d ", no->dado);
    if (no->dir) {
        em_ordem(no->dir);
    }
    return;
}

//-------------------------------------------------------------------
//  d)      Percurso em pré-ordem (no, esq, dir)
//-------------------------------------------------------------------
void pre_ordem(NoArvore* no) {
    printf("%d ", no->dado);
    if (no->esq) {
        pre_ordem(no->esq);
    }
    if (no->dir) {
        pre_ordem(no->dir);
    }
    return;
}

//-------------------------------------------------------------------------------
//  e)      Calcular a altura de um nó (o maior caminho de um nó até uma folha)
//-------------------------------------------------------------------------------
int calculaAltura(NoArvore* no, int altura) {
    if (!no) {
        return 0;
    }
    int altura_esq = calculaAltura(no->esq, altura);
    int altura_dir = calculaAltura(no->dir, altura);
    int max_altura = std::max(altura_esq, altura_dir) + 1;

    return max_altura;
}

//-------------------------------------------------------------------
//  f)      Fator de balanceamento de um nó (O balanceamento de um NÓ é definido
//  como a altura de sua subárvore esquerda menos a altura de sua subárvore
//  direita - Fonte: USP)
//-------------------------------------------------------------------
int balanceamento_no(NoArvore* no) {
    int altura_sub_esquerda = calculaAltura(no->esq, 0);
    int altura_sub_direita = calculaAltura(no->dir, 0);
    return altura_sub_esquerda - altura_sub_direita;
}

//--------------------------------------------------------------------------
//  g)      Percorrer a árvore em níveis (representar a árvore em um vetor)
//--------------------------------------------------------------------------
void print_nivel(NoArvore* no, int nivel) {
    if (!no)
        return;
    if (nivel == 1) {
        printf(" %d ", no->dado);
    } else if (nivel > 1) {
        print_nivel(no->esq, nivel - 1);
        print_nivel(no->dir, nivel - 1);
    }
    return;
}
// Função auxiliar
void percorre_niveis(NoArvore* no) {
    int altura = calculaAltura(no, 0);
    for (int i = 1; i <= altura; i++) {
        print_nivel(no, i);
    }
}


//-------------------------------------------------------------------
//  h)      Produto de todos os nós
//-------------------------------------------------------------------
int produto_nos(NoArvore* no, int produto) {
    produto = produto * no->dado;
    if (no->esq) {
        produto = produto_nos(no->esq, produto);
    }
    if (no->dir) {
        produto = produto_nos(no->dir, produto);
    }
    return produto;
}
