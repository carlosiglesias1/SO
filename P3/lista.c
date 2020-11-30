#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "lista.h"


void createList (lista *l){
    l->fin=0;
    for (int i = 0; i < TAML; i++) {
      l->array[i]=NULL;
    }
}
/*********************************************************/
bool inserItem(lista *l, tItem *it) {
  int i=l->fin;
  l->array[i] = (tItem *) malloc(sizeof(tItem));
  l->array[i]->direccion= it->direccion;
  l->array[i]->size=it->size;
  l->array[i]->fecha=it->fecha;
  l->array[i]->key=it->key;
  strcpy(l->array[i]->fichero,it->fichero);
  l->array[i]->fd=it->fd;
  l->array[i]->tipo = it->tipo;
  l->fin+=1;
  return true;
}
/*********************************************************/
tItem *getItem(lista l, posicion pos){
  if((pos>=0)&&(pos < l.fin))
    return l.array[pos];
  else
      return NULL;
}
/*********************************************************/
posicion findMalloc (lista l, size_t tam){

  for (int i = 0; i < l.fin; i++) {
    if (l.array[i]->tipo==MALLOC) {
      if (l.array[i]->size==tam) {
        return i;
      }
    }
  }
  return -1;
}
/*********************************************************/
posicion findMmap(lista l,char trozos[]){
  for (int i = 0; i < l.fin; i++) {
    if (l.array[i]->tipo==MAP) {
      if (!strcmp(l.array[i]->fichero,trozos)) {
        return i;
      }
    }
  }
  return -1;
}
/*********************************************************/
posicion findShared(lista l, key_t clave ){
  for (int i = 0; i < l.fin; i++) {
    if (l.array[i]->tipo==SHARED) {
      if (l.array[i]->key==clave) {
        return i;
      }
    }
  }
  return -1;
}
/*********************************************************/
posicion findItem (lista l, void *it){
  int i=0;
  while ((l.array[i]!=NULL)&&(l.array[i]->direccion!=it)) {
    i++;
  }
  if(l.array[i]!=NULL){
    return i;
  }else{
    return -1;
  }
}
/*********************************************************/
void deleteItem(lista *l, posicion pos){
  posicion auxp=pos;
  void* aux;
  if(l->array[auxp]!=NULL){
    aux=l->array[auxp];
    while (l->array[auxp]!=NULL) {
      l->array[auxp]=l->array[auxp+1];
      auxp++;
    }
  //  l->array[pos]=NULL;
    free(aux);
    aux=NULL;
    l->fin--;
  }
}
/*********************************************************/
void emptyList(lista *l){
  while (l->fin!=0) {
    deleteItem(l,findItem(*l,l->array[l->fin-1]->direccion));
  }
}
/********************************************************/
bool isEmptyList(lista l){
  return l.fin==0;
}
/********************************************************/
bool isListEnd(lista l, posicion pos){
  return l.fin-1 == pos;
}
/*******************************************************/
void listarItem(tItem * it){
  printf("Direccion:%p\n",it->direccion);
  printf("size:%ld\n",it->size);
  printf("fecha:%ld\n",it->fecha);
  printf("key:%d\n",it->key);
  printf("fichero:%s\n",it->fichero);
  printf("tipo:%d\n",it->tipo);
  printf("file descriptor:%d\n", it->fd);

}
/*********************************************************/
/**************PRUEBAS DE LA LISTA************************/
/*******************************************************/
/*int main() {
  lista l;
  tItem item, item2;
  createList(&l);
  if(isEmptyList(l)) printf("VACIA\n");
  printf("AHORA INSERTAMOS\n");
  item.direccion= NULL;
  item.size=1234;
  item.fecha=time(NULL);
  item.key=21;
  printf("hola\n" );
  // item.extra=NULL;
  // item.tipo=NULL;
  strcpy(item.fichero, "estoEsExtra");
  item.fd= 7;
  item.tipo = 3;

  inserItem(&l,&item);
  printf("ELEMENTO 0\n");
  listarItem((&l)->array[0]);



  item.direccion=NULL;
  item.size=33333;
  item.fecha=time(NULL);
  item.key=11;
  printf("hola\n" );
  // item.extra=NULL;
  // item.tipo=NULL;
  strcpy(item.fichero, "estoEsExtra2");
  item.fd= 7;
  item.tipo = 1;
  inserItem(&l,&item);
  printf("ELEMENTO 1\n");
  listarItem((&l)->array[1]);
  printf("\n");


  item.direccion=NULL;
  item.size=44444;
  item.fecha=time(NULL);
  item.key=88;
  printf("hola\n" );
  // item.extra=NULL;
  // item.tipo=NULL;
  strcpy(item.fichero, "estoEsExtra4");
  item.fd= 7;
  item.tipo = 1;
  inserItem(&l,&item);
  printf("ELEMENTO 3\n");
  listarItem((&l)->array[2]);
  printf("\n");

  item2.direccion=NULL;
  item2.size=22222;
  item2.fecha=time(NULL);
  item2.key=33;
  printf("hola\n" );
  // item.extra=NULL;
  // item.tipo=NULL;
  strcpy(item2.fichero, "estoEsExtra3");
  item2.fd= 7;
  item2.tipo=3;

  inserItem(&l,&item2);
  printf("ELEMENTO 2\n");
  listarItem((&l)->array[3]);
  printf("\n");
  printf("EL TAMAÑO ES %d\n", l.fin );
  printf("\n");
  deleteItem(&l,findItem(l,l.array[l.fin-1]->direccion));

  printf("EL TAMAÑO ES %d\n", l.fin );
  printf("\n");
  listarItem((&l)->array[0]);
printf("\n");
  listarItem((&l)->array[1]);
printf("\n");
  listarItem((&l)->array[2]);

if(!isEmptyList(l)) printf("NO VACIA\n");
if (isListEnd(l,2)) printf("es ultimo\n");
emptyList(&l);
  if(isEmptyList(l)) printf("VACIA\n");
  return 0;
}*/
