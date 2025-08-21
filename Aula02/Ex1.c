#include <stdio.h>
#include <stdlib.h>

// Estrutura de uma célula da lista duplamente ligada
typedef struct Celula {
	int valor;					// Valor armazenado na célula
	struct Celula *proximo;		// Ponteiro para o próximo elemento
	struct Celula *anterior;	// Ponteiro para o elemento anterior
} Celula;

// Estrutura da fila com ponteiros para início e fim
typedef struct {
	Celula *head;	// Ponteiro para o primeiro elemento (início da fila)
	Celula *tail;	// Ponteiro para o último elemento (fim da fila)
	int qtde;		// Contador de elementos na fila
} Queue;

// Cria uma nova célula com o valor especificado
Celula *cria_celula(int valor){
	Celula *nova = malloc(sizeof(Celula));
    nova->proximo = NULL;
    nova->anterior = NULL;
    nova->valor = valor; 
    return nova;
}

// Cria uma nova fila vazia
Queue *cria_queue(){
	Queue *nova = malloc(sizeof(Queue));
    nova->head = NULL;
    nova->tail = NULL;
    nova->qtde = 0;
    return nova;
}

// Operação ENQUEUE: insere elemento no final da fila (FIFO)
void enqueue(Queue *queue, int valor){
    printf("Inserido %d: ", valor);
    Celula *nova = cria_celula(valor);
    if (queue->qtde == 0) {
        queue->head = nova;
        queue->tail = nova;
        queue->qtde++;
    } else {
        nova->anterior = queue->tail;
        queue->tail->proximo = nova;
        queue->tail = nova;
        queue->qtde++;
    }
   
}

// Operação DEQUEUE: remove elemento do início da fila (FIFO)
int dequeue(Queue *queue){
	if(queue->head != NULL) {
        Celula *aux = queue->head;
        int valor = aux->valor;
        printf("Valor removido: %d, ", valor);
        queue->head = queue->head->proximo;
        if(queue->head == NULL) {
            queue->tail = NULL;
        }
        queue->qtde--;
        free(aux);
        return valor;
    }
    return -1;
}

// Exibe todos os elementos da fila (do início ao fim)
void show(Queue *queue){
	Celula *atual = queue->head;
    while(atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main(void) {
	Queue *queue = cria_queue();
    int nums[] = {10, 2, 0, 4, 5, 5, 6, 2, 8, 1, 9};
    int len_nums = sizeof(nums) / sizeof(int);

    printf("=== INSERINDO ELEMENTOS ===\n");
    for(int i = 0; i < len_nums; i++) {
        enqueue(queue, nums[i]);
        show(queue);
    }
    printf("\n");

    printf("=== REMOVENDO ELEMENTOS ===\n");
    for (int i = 0; i < len_nums; i++) {
        dequeue(queue);
        printf("Fila restante: ");
        show(queue);
    }
	return 0;
}