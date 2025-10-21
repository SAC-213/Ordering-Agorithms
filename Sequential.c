#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
// el primer numero desordenado de 10,000,000 está en 856834115 y el último en 2045206161
// el primer numero desordenado de 5,000,000 está en 856834115 y el último en 876774664

void lineal(int A[], int *res, int *Comparaciones, int *n, int *valor);

int main(int argc, char const *argv[])
{
    int i;
    int Comparaciones = 0;
    int res = FALSE;
    int n = atoi(argv[1]);
    int valor = atoi(argv[2]);
    int *A=malloc(sizeof(int) * n);

    for ( i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }

    lineal(A,&res,&Comparaciones, &n, &valor);

    printf("\nEl valor ");
    (res==TRUE) ? printf("SI ") : printf("NO ");
    printf("fue encontrado.\nEn %d comparaciones\n",Comparaciones);

    return 0;
}

void lineal(int A[], int *res, int *Comparaciones, int *n, int *valor)
{
    for (int  i = 0; i < (*n); i++)
    {
        (*Comparaciones)++;
        if (A[i]==(*valor))
        {
            (*res) = TRUE;
            break;
        }
    }
    res = FALSE;
}
