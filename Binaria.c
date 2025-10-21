#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


//la mitad de 10,000,000 se encuentra en 1073782848
//la mitad de 5,000,000 se encuentra en 1073807161

void QuickSort(int A[], int p, int r);
int Pivot(int A[], int p, int r);
void Intercambio(int A[], int i, int j);
int Binaria(int A[], int valor, int inicio, int final, int *Comparaciones);

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]);
    int valor = atoi(argv[2]);
    int *A;
    int Comparaciones=0;
    int res;

    //Apartar memoria para n números enteros
    A=malloc(n*sizeof(int));
    if(A==NULL)
    {
        printf("\nError al intentar reservar memoria para %d elementos\n",n);      
        exit(1);
    }   


    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);

    //ordenar
    QuickSort(A,0,n-1);
    
    res=Binaria(A,valor,0,n-1,&Comparaciones);
    printf("\nEl valor ");
    (res==TRUE) ? printf("SI ") : printf("NO ");
    printf("fue encontrado.\nEn %d comparaciones\n",Comparaciones);


    free(A);
    return 0;
}

void QuickSort(int A[], int p, int r){
    int j;
    if (p<r)
    {
        j = Pivot(A,p,r);
        QuickSort(A, p, j-1);
        QuickSort(A, j+1, r);
    }
}

int Pivot(int A[], int p, int r){
    int piv=A[p];
    int i=p+1;
    int j=r;

    while (i<j)
    {
        while (A[i]<=piv && i<=r){
            i++;
        }
        
        while (A[j]>piv && j>=p){
            j--;
        }

        if (i<j)
        {
            Intercambio(A,i,j);
        }  
    }
    Intercambio(A,p,j);
    return j;
}

void Intercambio(int A[], int i, int j){
    int temp=A[j];
    A[j]=A[i];
    A[i]=temp;
}

int Binaria(int A[], int valor, int inicio, int final, int *Comparaciones){
    int res;
    int mitad;
    res=FALSE;
    while (inicio<=final)
    {
        mitad = (inicio+final)/2;

        (*Comparaciones)++;
        if (valor==A[mitad])
        {
            res = TRUE;
            break;
        }

        if (valor>A[mitad])
        {
            inicio = mitad+1;
        }
        else
        {
            final = mitad-1;
        }
    }
    return res;
}
