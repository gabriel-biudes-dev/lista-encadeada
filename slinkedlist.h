typedef struct no Lista;

//Insere um valor no início da lista
Lista* insert(Lista* l, int info);

//Mostra os valores da lista
void printList(Lista *l);

//Insere um valor na posição após o valor informado
void insertAfter(Lista *l, int info, int n);

//Insere um valor no final da lista
Lista* insertEnd(Lista *l, int n);

//Remove um valor da lista
Lista* remover(Lista *l, int info);

//Soma os valores na lista dentro do intervalo fechado entre a e b
int somar_intervalo(Lista *l, int a, int b);

//Retorna a lista com os valores alternados de n em n vezes
Lista* alternar(Lista *l, int n);

//Calcula o tamanho da lista
int calcSize(Lista *l);

//Adiciona l2 ao final de l1
Lista* append(Lista *l1, Lista *l2);

//Conta quantas vezes um valor x aparece na lista
int conta_ocorrencias(Lista *l, int x);

//Elimina todos os valores repetidos da lista
Lista* elimina_repetidos(Lista *l);

//Retorna apenas os valores pares da lista
Lista* pares(Lista *l);

//Verifica se x pertence a lista
int pertence(Lista *l, int x);

//Verifica se a lista l2 está contida na lista l1
int esta_contido(Lista *l1, Lista *l2);

//Remove um valor na lista em determinado índice
Lista* remover_indice(Lista *l, int n);