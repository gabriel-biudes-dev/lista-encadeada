#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int data;
    struct no* next;
}Lista;

Lista* insert(Lista* l, int info){
    Lista* aux = (Lista*) malloc(sizeof(Lista));
    aux->data = info;
    aux->next = l;
    return aux;
}

void printList(Lista *l){
    /*
    if(l == NULL){
        printf("\n");
        return;
    }
    printf(" %d ", l->data);
    printList(l->next);
    */
   /*
   while(l != NULL){
    printf(" %d ", l->data);
    l = l->next;
   }
   */
    Lista *aux;
    for(aux = l; aux != NULL; aux = aux->next){
        printf(" %d ", aux->data);
    }
    printf("\n");
    free(aux);
}

void insertAfter(Lista *l, int info, int n){
    while(l != NULL){
        if(l->data == n) break;
        l = l->next;
    }
    if(l != NULL){
        Lista *aux = (Lista*) malloc(sizeof(Lista));
        aux->data = info;
        aux->next = l->next;
        l->next = aux;
    }
}

Lista* insertEnd(Lista *l, int n){
    Lista *aux = (Lista*) malloc(sizeof(Lista));
    aux->data = n;
    aux->next = NULL;
    if(l == NULL) return aux;
    Lista *temp = l;
    Lista *ant = l;
    while(l != NULL){
        ant = l;
        l = l->next;
    }
    ant->next = aux;
    return temp;
}

Lista* remover(Lista *l, int info){
    Lista *ant = l;
    Lista *p = l;
    
    while(p != NULL && p->data != info){
        ant = p;
        p = p->next;
    }
    if(p != NULL){
        if(p == l) l = l->next;
        else ant->next = p->next;
        free(p);
    }
    return l;
}

int somar_intervalo(Lista *l, int a, int b){
    if(l == NULL) return 0;
    if(l->data >= a && l->data <= b) return l->data + somar_intervalo(l->next, a, b);
    return somar_intervalo(l->next, a, b);
}

Lista* alternar(Lista *l, int n){
    int i;
    Lista *aux = NULL;
    while(l != NULL){
        for(i = 0; i < n && l != NULL; i++){
            aux = insert(aux, l->data);
            l = l->next;
        }
        for(i = 0; i < n && l != NULL; i++) l = l->next;
    }
    return aux;
}

int calcSize(Lista *l){
    int size = 0;
    while(l != NULL){
        size++;
        l = l->next;
    }
    return size;
}

Lista* append(Lista *l1, Lista *l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    Lista *aux = l1;
    Lista *ant = l1;
    while(l1 != NULL){
        ant = l1;
        l1 = l1->next;
    }
    ant->next = l2;
    return aux;
}

int conta_ocorrencias(Lista *l, int x){
    if(l == NULL) return 0;
    if(l->data == x) return 1 + conta_ocorrencias(l->next, x);
    return conta_ocorrencias(l->next, x);
}

Lista* elimina_repetidos(Lista *l){
    Lista *aux = NULL;
    while(l != NULL){
        if(conta_ocorrencias(aux, l->data) == 0) aux = insertEnd(aux, l->data);
        l = l->next;
    }
    return aux;
}

Lista* pares(Lista *l){
    Lista *aux = NULL;
    while(l != NULL){
        if(conta_ocorrencias(aux, l->data) == 0 && l->data % 2 == 0) aux = insertEnd(aux, l->data);
        l = l->next;
    }
    return aux;
}

int pertence(Lista *l, int x){
    while(l != NULL){
        if(l->data == x) return 1;
        l = l->next;
    }
    return 0;
}

int esta_contido(Lista *l1, Lista *l2){
    if(l2 == NULL) return 1;
    Lista *aux = l2;
    int contido = 0;
    while(l1 != NULL && l2 != NULL){
        if(l1->data == l2->data){
            contido = 1;
            l1 = l1->next;
            l2 = l2->next;
        }else{
            contido = 0;
            l1 = l1->next;
            l2 = aux;
        }
    }
    return contido;
}

Lista* remover_indice(Lista *l, int n){
    if(l == NULL) return l;
    if(n + 1 > calcSize(l)) return l;
    if(n == 0) return l->next;
    int i;
    Lista *ant = l;
    Lista *temp = l;
    for(i = 0; i < n; i++){
        ant = l;
        l = l->next;
    }
    ant->next = l->next;
    free(l);
    return temp;
}

Lista* insertRec(Lista *l, int info, int x){
    if(l == NULL) return NULL;
    if(l->data != info) return insertRec(l->next, info, x);
    Lista *aux = (Lista*) malloc(sizeof(Lista));
    Lista *temp = l;
    aux->data = x;
    aux->next = temp->next;
    l->next = aux;
    return l;
}

Lista* insertOrder(Lista *l, int x){
    Lista *aux = (Lista*) malloc(sizeof(Lista));
    aux->data = x;
    aux->next = NULL;
    if(l == NULL) return aux;
    if(x < l->data){
        aux->next = l;
        return aux;
    }
    Lista *tmp = l;
    Lista *ant = l;
    while(l != NULL && l->data < x){
        ant = l;
        l = l->next;
    }
    ant->next = aux;
    aux->next = l;
    return tmp;
}

Lista* inverter(Lista *l){
    Lista *aux = NULL;
    while(l != NULL){
        aux = insert(aux, l->data);
        l = l->next;
    }
    return aux;
}

void swap(Lista *l, int x, int y){
    while(l != NULL){
        if(l->data == x){
            l->data = y;
            l = l->next;
            continue;
        }
        if(l->data == y){
            l->data = x;
            l = l->next;
            continue;
        }
        l = l->next;
    }
}

Lista* ordenar(Lista *l){
    Lista *aux = l;
    while(l != NULL && l->next != NULL){
        if(l->data > l->next->data){
            swap(l, l->data, l->next->data);
            return ordenar(aux);
        }
        l = l->next;
    }
    return aux;
}

int compare(Lista *l1, Lista *l2){
    if(l1 == NULL && l2 != NULL) return 1;
    if(l2 == NULL && l1 != NULL) return 1;
    if(l1 == NULL && l2 == NULL) return 0;
    if(l1->data == l2->data) return 0 + compare(l1->next, l2->next);
    return 1;
}

Lista* moveMenor(Lista *l){
    Lista *ant = l;
    Lista *menor = l;
    Lista *aux = l;
    while(l != NULL && l->next != NULL){
        if(l->next->data < menor->data){
            ant = l;
            menor = l->next;
        }
        l = l->next;
    }
    ant->next = menor->next;
    menor->next = aux;
    return menor;
}

int calcProfundidade(Lista *l, int x){
    int prof = 0;
    while(l != NULL && l->data != x){
        prof++;
        l = l->next;
    }
    if(l == NULL) return -1;
    return prof;
}

int calcAltura(Lista *l, int x){
    int altura = -1;
    while(l != NULL){
        if(altura >= 0) altura++;
        if(l->data == x) altura = 0;
        l = l->next;
    }
    return altura;
}

int isOrdened(Lista *l){
    int val = 1;
    while(l != NULL && l->next != NULL){
        if(l->data > l->next->data) val = 0;
        l = l->next;
    }
    return val;
}

Lista* invert(Lista *l){
    Lista *ant = NULL;
    Lista *aux = l;
    while(l != NULL && l->next != NULL){
        aux = l->next;
        l->next = ant;
        ant = l;
        l = aux;
    }
    l->next = ant;
    return l;
}

int main(){
    Lista *l = NULL;
    Lista *l2 = NULL;
    Lista *l3 = NULL;
    /*
    l = insertEnd(l, 23);
    l = insertEnd(l, 2);
    l = insertEnd(l, 3);
    l = insertEnd(l, 3);
    l = insertEnd(l, 15);
    l = insertEnd(l, 3);
    l = insertEnd(l, 2);
    l = insertEnd(l, 10);
    l = insertEnd(l, 10);
    l2 = insertEnd(l2, 2);
    l2 = insertEnd(l2, 10);
    l2 = insertEnd(l2, 10);
    insertRec(l, 15, 99);
    */
    //l = pares(l);
    //l = remover_indice(l, 1);
    l = insertEnd(l, 20);
    l = insertEnd(l, 25);
    l = insertEnd(l, 30);
    l = insertEnd(l, 40);
    //l = insertOrder(l, 27);

    l2 = insertOrder(l2, 27);
    l2 = insertOrder(l2, 15);
    l2 = insertOrder(l2, 33);
    l2 = insertOrder(l2, 0);
    l2 = insertOrder(l2, 30);
    //l2 = insertOrder(l2, 30);
    //printList(l);
    //l2 = inverter(l2);
    //l2 = ordenar(l2);
    //swap(l2, 33, 0);
    //l2 = ordenar(l2);
    l3 = insertEnd(l3, 98);
    l3 = insertEnd(l3, 2);
    l3 = insertEnd(l3, 30);
    l3 = insertEnd(l3, 1);
    l3 = insertEnd(l3, 33);
    //printList(l2);
    l3 = moveMenor(l3);
    l3 = invert(l3);
    printList(l3);
    //printf("%d", isOrdened(l));
    //printf("%d", calcProfundidade(l3, 222));
    //printf("%d", calcAltura(l3, 332));
    //printf("%d", compare(l2, l3));
    //printf("%d", esta_contido(l, l2));
    //printf("%d", calcSize(l));
    //printf("%d\n", somar_intervalo(l, 0, 10));
    //printf("%d", conta_ocorrencias(l, 3));
    return 0;
}
