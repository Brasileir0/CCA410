#include <stdio.h>
#include <stdlib.h>

#define tam_hash 11

typedef struct Celula{
  int valor;
  struct Celula* proximo;
}Celula;

typedef struct {
  Celula* inicio;
}Lista;

typedef struct {
  Lista* table[tam_hash];
}Hash;

Hash* start_hash(){
    Hash* hash = (Hash*)malloc(sizeof(Hash));
    if (hash == NULL) {
        return NULL;
    } else {
        for (int i = 0; i < tam_hash; i++) {
            Lista* list = (Lista*)malloc(sizeof(Lista));
            list->inicio = NULL;
            hash->table[i] = list;
        }
    }
    return hash;
}

void inserir_hash(Hash* hash, int valor){
    Celula* celula = (Celula*)malloc(sizeof(Celula));
    int idx = (valor % tam_hash + tam_hash) % tam_hash;
    celula->valor = valor;
    celula->proximo = hash->table[idx]->inicio;
    hash->table[idx]->inicio = celula;
}

void remover_hash(Hash* hash, int valor){
    int idx = (valor % tam_hash + tam_hash) % tam_hash;
    Celula* atual = hash->table[idx]->inicio;
    Celula* anterior = NULL;

    while(atual != NULL && atual->valor != valor){
        anterior = atual;
        atual = atual->proximo;
    }

    if(atual == NULL){
        return;
    }
    if(anterior == NULL){
        hash->table[idx]->inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
}


void imprimir(Hash* hash){
    Celula* atual;
    printf("---------------------");
    printf("\n");
    for (int i = 0; i < tam_hash; i++) {
        printf("%d -> ", i);
        atual = hash->table[i]->inicio;
        while (atual != NULL) {
            printf("%d ", atual->valor);
            atual = atual->proximo;
        }
        printf("\n");
    }
    printf("---------------------");
    printf("\n");
}


int main(void) {
  Hash* hash = start_hash();
  int valor;
  while(1){
    scanf("%d", &valor);
    if(valor == 0)
      break;
    inserir_hash(hash, valor);
  }
  imprimir(hash);
  while(1){
    scanf("%d", &valor);
    if(valor == 0)
      break;
    remover_hash(hash, valor);
  }
  imprimir(hash);
  return 0;
}