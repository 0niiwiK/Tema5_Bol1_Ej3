#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 10

//Prototipos
int preguntaVector();
void rellenaManual(int v[]);
void rellenaAuto(int v[]);
void imprimeVector(int v[]);
void maxVector(int v[], int *estaRepetido);

int main() {
    int v[TAM];
    int estaRepetido;
    if (preguntaVector()==0)
        rellenaManual(v);
    else
        rellenaAuto(v);
    imprimeVector(v);
    maxVector(v,&estaRepetido);
}

int preguntaVector(){
    // Devuelve 0 si manual o 1 para aleatorio

    char opcion;
    int opcionNum;
    printf("Desea rellenar el vector a mano (m) o aleatoriamente (a)?: ");
    scanf("%c",&opcion);
    fflush(stdin);
    while (opcion!='m' && opcion!='a'){
        printf("Opcion invalida\nDesea rellenar el vector a mano (m) o aleatoriamente (a)?: ");
        scanf("%c",&opcion);
        fflush(stdin);
    }
    if (opcion=='m')
        opcionNum=0;
    else
        opcionNum=1;
    return opcionNum;
}

void rellenaManual(int v[]){
    printf("\n");
        for (int i = 0; i < TAM; i++) {
            printf("Introduce el valor %d: ",i+1);
            scanf("%d",&v[i]);
    }
}

void rellenaAuto(int v[]){
    srand(time(NULL));
    for (int i = 0; i < TAM; ++i)
        v[i]=(rand()%99);
    printf("Vector relleno con numeros aleatorios entre 0 y 99.");
}

void imprimeVector(int v[]){
    printf("\n\nCONTENIDO DEL VECTOR: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ",v[i]);
    }
}

void maxVector(int v[], int *estaRepetido){
    int max=v[0];
    int posMax=0;
    for (int i = 1; i < TAM; i++) {
        if (v[i]>max){
            max=v[i];
            *estaRepetido=0;
            posMax=i;
        }
        else if (v[i]==max)
            *estaRepetido=1;
    }
    printf("\n\nEl valor maximo es %d (posicion %d).\n",max,posMax+1);
    if (*estaRepetido==1)
        printf("El valor maximo se encuentra repetido\n");
}