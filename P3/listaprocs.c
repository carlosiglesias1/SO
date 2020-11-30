/*    AUTORES:
*   Ignacio Borregan Naya :ignacio.borregan  DNI: 47436297Q
*   Carlos Iglesias Gomez :carlos.iglesias1  DNI:35631582M
*   GRUPO: 32
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "listaprocs.h"
#define MAXP 4096

/*struct proc {
  pid_t pid;
  int priority;
  char cmd[MAXP];
  time_t fecha;
  int estado;
  int returned;
};

typedef struct proc tItem ;
typedef struct node {
   tItem data;
   struct node *next;
}  *lista;*/
/****************************************************************/
void createListP(listaP *l){
  *l = NULL;
}
/****************************************************************/
bool isEmptyListP(listaP l){
  return l==NULL;
}
 /****************************************************************/
listaP firstP(listaP l){
  return l;
}
/****************************************************************/
listaP nextP(listaP l){
   return l->next;
 }
 /****************************************************************/
listaP previousP(listaP l, struct node *nodo){
  listaP q;
  if(nodo==firstP(l)){
    return NULL;
  }else {
    q=firstP(l);
    while (q->next!=nodo) {
      q=q->next;
    }
    return q;
  }
}
/*******************************************************************/
tItemP getItemP(struct node * pos){
  return pos->data;
}
/*****************************************************************/
struct node *  findItemP(listaP l, pid_t pid){
    listaP pos = firstP(l);
    while ((pos!=NULL)&&(pos->data.pid!=pid)) {
      pos= nextP(pos);
    }
    return pos;
}
/****************************************************************/
bool insertItemP(listaP *l, tItemP dato){
  listaP nodo, auxp = *l;

  nodo= NULL;
  nodo = malloc (sizeof(struct node));
  nodo ->data.pid = dato.pid;
  nodo ->data.priority = dato.priority;
  strcpy(nodo ->data.cmd,dato.cmd);
  nodo ->data.fecha = dato.fecha;
  nodo-> data.estado = dato.estado;
  nodo-> data.returned= dato.returned;
  nodo -> next = NULL;

  if (isEmptyListP(*l)){
    *l = nodo;
  }else{
    while (auxp->next!=NULL) {
      auxp = auxp->next;
    }
    auxp-> next = nodo;
  }

  return true;
}
/***************************************************************/
bool updateItemP(listaP l, tItemP item) {
  l=findItemP(l,item.pid);
  if(l!=NULL){
    l->data.priority= item.priority;
    strcpy(l ->data.cmd,item.cmd);
    l ->data.fecha = item.fecha;
    l-> data.estado = item.estado;
    l-> data.returned= item.returned;

    return true;
  }else{
    return false;
  }
}
/****************************************************************/
void deleteItemP(listaP *l, struct node * nodo){
  listaP auxpos=nodo;

  if(nodo==firstP(*l)){
    *l=(*l)->next;
  }else if (nodo->next==NULL){
    auxpos = previousP(*l,nodo);
    auxpos->next=nodo->next;
  }else{
    auxpos=nodo->next;
    nodo->next=auxpos->next;
    nodo->data.pid=auxpos->data.pid;
    nodo->data.priority=auxpos->data.priority;
    strcpy(nodo->data.cmd,auxpos->data.cmd); //REVISAR
    nodo->data.fecha=auxpos->data.fecha;
    nodo->data.estado=auxpos->data.estado;
    nodo->data.returned=auxpos->data.returned;
    nodo=auxpos;
  }
  free(nodo);
  nodo=NULL;
}
/*****************************************************************/
void deleteListP(listaP *l) {
    if(!isEmptyListP(*l)){
    listaP pos = firstP(*l);
    while(pos!=NULL){
      deleteItemP(l,pos);
      pos=firstP(*l);
    }
    l=NULL;
  }
}
/***************************************************************/
void listarPosP(listaP l) {

  listaP pos = l;

    printf("%d", pos->data.pid );
    printf(" %d",pos->data.priority);
    printf("%7s",pos->data.cmd );
    printf(" %10ld", pos->data.fecha );
    printf("%7d",pos->data.estado );
    printf("%7d\n",pos->data.returned  );

}
/***************************************************************/
/*int main(int argc, char const *argv[]) {
  lista l, p;//,q, f;
  tItem pipo;//, lulu;
  createList(&l);

  pipo.pid= 22222;
  pipo.priority= 2;
  strcpy(pipo.cmd , "caca");
  pipo.fecha=time(NULL);
  pipo.estado = 0;
  pipo.returned=9;

  insertItem(&l,pipo);

  pipo.pid= 33333;
  pipo.returned =34;
  insertItem(&l,pipo);
  p=first(l);
  listarPos(p);
  p=next(p);
  listarPos(p);


  printf("AHORA VAMOS A ACTUALIZAR EL PRIMERO\n");
  pipo.pid= 22222;
  pipo.priority= 1;
  updateItem(l,pipo);
  p=first(l);
  listarPos(p);
  p=next(p);
  listarPos(p);
  printf("Borrando...\n");
  deleteList(&l);
  printf("terminado\n" );
  printf("No hay nada: %p\n", l);

   j=4;
   insertItem(&l,j);
   j=5;
   insertItem(&l,j);
   j=6;
   insertItem(&l,j);
//3,4,5,6
   q=next(first(l));
   p=first(l);

   f=findItem(l,5);
   pipo=getItem(f);
   if(f!=NULL)
      printf("ITEM ENCONTRADO %d\n", pipo.estado );
    else
      printf("ITEM NOOO ENCONTRADO \n");


   printf("valor de p: %d\n", p->data.estado);
//LISTAMOS TODO
   p=next(p);//4
   printf("valor de p: %d\n", p->data.estado);
   p=next(p);//5
   printf("valor de p: %d\n", p->data.estado);
   p=next(p);//6
   printf("valor de p: %d\n", p->data.estado);
printf("VAMOS A LISTAR CON EL METODO LISTAR: \n");
listarP(l);
   printf("valor para borrar: %d\n", q->data.estado);
   deleteList(&l);
   printf("terminado\n" );
   printf("No hay nada: %p\n", l);
*/
   /*deleteItem(&l,q);
//BORRAMOS POR EL MEDIO
   p=first(l);

   printf("valor de p: %d\n", p->data);
   //3
   p=next(p);//5
   printf("valor de p: %d\n", p->data);
   p=next(p);//6
   printf("valor de p: %d\n", p->data);

//BORRAMOS POR EL PRINCIPIO
   q=first(l);
   printf("valor para borrar: %d\n", q->data);
   deleteItem(&l,q);//3

   p=first(l);

   printf("valor de p: %d\n", p->data);
   //5
   p=next(p);//6
   printf("valor de p: %d\n", p->data);

   //BORRAMOS POR EL FINAL
   printf("valor para borrar: %d\n", p->data);
   deleteItem(&l,p);//3

   p=first(l);

   printf("valor de p: %d\n", p->data);

   deleteItem(&l,p);

   printf("No hay nada: %p\n", l);*/

   /*return 0;
 }*/
