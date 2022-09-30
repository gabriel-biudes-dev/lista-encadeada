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
    if(l == NULL){
        printf("\n");
        return;
    }
    printf(" %d ", l->data);
    printList(l->next);
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

int main(){
    Lista *l = NULL;
    Lista *l2 = NULL;
    l = insertEnd(l, 2);
    l = insertEnd(l, 3);
    l = insertEnd(l, 3);
    l = insertEnd(l, 3);
    l = insertEnd(l, 2);
    l = insertEnd(l, 10);
    l = insertEnd(l, 10);
    l2 = insertEnd(l2, 2);
    l2 = insertEnd(l2, 10);
    l2 = insertEnd(l2, 10);

    //l = pares(l);
    //l = remover_indice(l, 1);
    printList(l);
    //printf("%d", esta_contido(l, l2));
    //printf("%d", calcSize(l));
    //printf("%d\n", somar_intervalo(l, 0, 10));
    //printf("%d", conta_ocorrencias(l, 3));
    return 0;
}