#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

typedef struct _nodo{
int valor;
struct _nodo *siguiente;

}tiponodo;

typedef tiponodo *pnodo;
typedef tiponodo *Lista;

int can=0;
int ve[50];
void insertar(Lista *l, int v);
void borrar(Lista *l,int v);
void borrar_lista(Lista *);
void mostrarlista(Lista l);
void menu();
void agregar();
void buscar_elemento(Lista *,int );
void impri();
void ordenar_asendente();
 Lista lista=NULL;
    pnodo p;

int main (){




menu();




return 0;
}

void insertar(Lista *lista,int v){
pnodo nodo;
//creamos un nodo para el nuevo valor a insertar

nodo=(pnodo)malloc(sizeof(tiponodo));
nodo->valor=v;
//si la lista esta vacia la lista sera el nuevo
//si no esta, insertamos el nuevo nodo a cont
//por lista
if(*lista==NULL ){
    *lista=nodo;
}else{
    nodo->siguiente=(*lista)->siguiente;

    }

(*lista)->siguiente=nodo;
}

void borrar(Lista *lista, int v){
pnodo nodo;
nodo=*lista;
//hacer que la lista apunte al nodo anterior al de valor v

do{
    if((*lista)->siguiente->valor != v) *lista=(*lista)->siguiente;

    }while((*lista)->siguiente->valor != v && *lista != nodo);
    //si existe un nodo con el valor v
    if((*lista)->siguiente->valor==v){
        // y si la lista solo tiene un nodo
        if(*lista == (*lista)->siguiente){
            //borrar toda la lista
            free(*lista);
            *lista=NULL;

        }else{
        //si la lista tiene mas de un nodo, borrar el nodo del valor v
        nodo=(*lista)->siguiente;
        (*lista)->siguiente=nodo->siguiente;
        free(nodo);

        }
        printf("\n\t\telemento borrado con exito\n\n");

    }else{
        printf("\n\t\tel elemento no existe\n\n");

    }
system("pause");
}

void borrar_lista(Lista *lista){

        pnodo nodo;
    //mientras la lista tenga mas de un nodo
    while((*lista)->siguiente != *lista){
        //borrar el nodo siguiente al apuntado por lista
        nodo=(*lista)->siguiente;
        (*lista)->siguiente=nodo->siguiente;
        free(nodo);
    }
    //y borrar el ultimo nodo

    free(*lista);
    *lista=NULL;

    printf("\n\t\tlista borrada con exito\n\n");
    system("pause");

        can=0;
}

void mostrarlista(Lista lista){


pnodo nodo=lista;
printf("\n\t\t   ");
if(lista!=NULL){
 for(int i=0;i<can;i++){
    printf("%d->",nodo->valor);
    nodo=nodo->siguiente;
}
}else{
    printf("lista vacia..!\n\n");
}
printf("\n");
system("pause");
}



void menu(){
  int opc;

int n;

do{         system("cls");
        printf("\t\tMENU PRINCIPAL\n\n");
        printf("\t\t 1. insertar\n\n");
        printf("\t\t 2. mostrar elementos de la lista\n\n");
        printf("\t\t 3. buscar elemento de la lista\n\n");
        printf("\t\t 4. eliminar elemento de la lista\n\n");
        printf("\t\t 5. eliminar lista\n\n");
        printf("\t\t 6. ordenar lista\n\n");
        printf("\t\tingrese una opcion: ");
        scanf("%d",&opc);
        switch(opc){
            case 1:agregar();
                break;
            case 2:mostrarlista(lista);
                break;
            case 3:printf("\n\t\tingrese el elemento a buscar: "); scanf("%d",&n);
                buscar_elemento(&lista,n);
                break;
            case 4:printf("\n\t\tingrese el elemento que desea borrar: "); scanf("%d",&n);
                borrar(&lista,n);
                break;
            case 5:borrar_lista(&lista);
                break;
            case 6:ordenar_asendente();
                break;
            case 7:impri();
                break;

        }


    }while(opc!=8);

}

void agregar(){

           int j=0;
for(int i=0;i<can;i++){
    ve[i]=0;
}
 int e,n;
   printf("\n\n\t\tingrese el numero de elementos a ingresar: ");
    scanf("%d",&n);
    printf("\n");
    for(int i=0;i<n;i++){
        printf("\t\tingrese el elemento #%d: ",i+1);
        scanf("%d",&e);
        ve[i]=e;
        can++;
        insertar(&lista,e);


    }

printf("\n\n\t\t elementos agregados con exito\n\n");

system("pause");

}
void buscar_elemento(Lista *lista,int v){
pnodo nodo;
nodo=*lista;
do{
    if((*lista)->siguiente->valor != v) *lista=(*lista)->siguiente;

    }while((*lista)->siguiente->valor != v && *lista != nodo);
    //si existe un nodo con el valor v
    if((*lista)->siguiente->valor==v){

            printf("\n\t\tel valor %d SI esta en la lista\n\n",v);
            system("pause");


    }else{
        printf("\n\t\tel valor %d NO esta en la lista\n\n",v);
        system("pause");
    }

}

void impri(){
    printf("\n\t\t   ");
for(int i=0;i<can;i++){
      printf("%d->",ve[i]);
    }
    printf("\n");
system("pause");
}

void ordenar_asendente(){
 int cambio=0;
    //metodo de ordenamiento burbuja
for(int i=0;i<can;i++){
   for(int j=0;j<can;j++){
        if(ve[j]>ve[j+1]){
            cambio=ve[j];
            ve[j]=ve[j+1];
            ve[j+1]=cambio;
        }
   }
}
//imprimir en orden
printf("\n\t\torden acendente:\n" );
 printf("\n\t\t   ");
for(int i=0;i<can;i++){
    printf("%d->",ve[i+1]);
}
printf("\n");
system("pause");
}

