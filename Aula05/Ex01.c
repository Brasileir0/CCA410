#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
	int valor;
	struct Vertice* esq;
	struct Vertice* dir;
	struct Vertice* pai;
} Vertice;

typedef struct Arvore{
	Vertice* raiz;
	int qtde;
} Arvore;

void in_ordem(Vertice *raiz) {
	if (raiz == NULL) {
		return;
	} else {
		in_ordem(raiz->esq);
		printf("%d ", raiz->valor);
		in_ordem(raiz->dir);
	}
}

void pre_ordem(Vertice *raiz) {
    if (raiz == NULL) {
		return;
	} else {
		printf("%d ", raiz->valor);
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);
	}
}

void pos_ordem(Vertice *raiz) {
    if (raiz == NULL) {
		return;
	} else {
		pos_ordem(raiz->esq);
		pos_ordem(raiz->dir);
		printf("%d ", raiz->valor);
	}
}

Vertice *cria_vertice(int valor){
	Vertice* novo = malloc(sizeof(Vertice));
	novo->dir = NULL;
	novo->esq = NULL;
	novo->pai = NULL;
	novo->valor = valor;
	
	return novo;
}

Arvore *cria_arvore(){
	Arvore* arvore = malloc(sizeof(Arvore));
	arvore->raiz = NULL;
	arvore->qtde = 0;

	return arvore;
}

void inserir(Arvore* arvore, int valor){
    Vertice* novo = cria_vertice(valor);
    if (arvore->raiz == NULL) {
        arvore->raiz = novo;
        arvore->qtde++;
        return;
    }

    Vertice* atual = arvore->raiz;
    Vertice* pai = NULL;

    while (atual != NULL) {
        pai = atual;
        if (valor < atual->valor) {
            atual = atual->esq;
        } else if (valor > atual->valor) {
            atual = atual->dir;
        } else {
            free(novo);
            return;
        }
    }

	novo->pai = pai;
    if (valor < pai->valor) {
        pai->esq = novo;
    } else {
        pai->dir = novo;
    }

    arvore->qtde++;
}

int remover_vertice(Arvore* arvore, Vertice* vertice) {
	if (vertice == NULL) {
		return 0;
	}

	int filhos = 0;
	if (vertice->esq != NULL) filhos ++;
	if (vertice->dir != NULL) filhos ++;

	if (filhos == 0) {
		if (vertice->pai != NULL) {
			if (vertice->pai->esq == vertice) {
				vertice->pai->esq = NULL;
			} else {
				vertice->pai->dir = NULL;
			}
		} else {
			arvore->raiz = NULL;
		}
		free(vertice);
	} else if (filhos == 1) {
        Vertice* filho = (vertice->esq != NULL) ? vertice->esq : vertice->dir;
        filho->pai = vertice->pai;

        if (vertice->pai != NULL) {
            if (vertice->pai->esq == vertice)
                vertice->pai->esq = filho;
            else
                vertice->pai->dir = filho;
        } else {
            arvore->raiz = filho;
        }
        free(vertice);
    } else {
        Vertice* pred = vertice->esq;
        while (pred->dir != NULL) {
            pred = pred->dir;
        }
        vertice->valor = pred->valor;
        remover_vertice(arvore, pred);
    }

    arvore->qtde--;
    return 1;
	

}

Vertice *buscar_valor(Arvore* arvore, int valor){
	Vertice* atual = arvore->raiz;
	while(atual != NULL){
		if(valor < atual->valor){
			atual = atual->esq;
		}else if(valor > atual->valor){
			atual = atual->dir;
		}else{
			return atual;
		}
	}
	return NULL;
}


int main(void) {
	int dados[] = {5, 3, 8, 2, 4, 7, 9, 1, 6, 10};
  	Arvore *arvore = cria_arvore();
  	
	for(int i = 0; i < 10; i++){
		inserir(arvore, dados[i]);
		printf("Inseriu %d mostra em ordem -> ", dados[i]);
		in_ordem(arvore->raiz);
		printf("\n");
		printf("Inseriu %d mostra em pré-ordem -> ", dados[i]);
		pre_ordem(arvore->raiz);
		printf("\n");
		printf("Inseriu %d mostra em pós-ordem -> ", dados[i]);
		pos_ordem(arvore->raiz);
		printf("\n");
	}

	for(int i = 0; i < 10; i++){
		Vertice *vertice = buscar_valor(arvore, dados[i]);
		if(vertice != NULL){
			remover_vertice(arvore, vertice);
		}
		printf("Removeu %d mostra em ordem -> ", dados[i]);
		in_ordem(arvore->raiz);
		printf("\n");
		printf("Removeu %d mostra em pré-ordem -> ", dados[i]);
		pre_ordem(arvore->raiz);
		printf("\n");
		printf("Removeu %d mostra em pós-ordem -> ", dados[i]);
		pos_ordem(arvore->raiz);
		printf("\n");
	}

	free(arvore);
		
    return 0;
}
