#include<stdio.h>


void insertionSort(int a[],int n)
    {
       int i,j,x;

       for(int i=0;i<n;i++)
       {
            j=i-1;
            x=a[i];
            while(j>-1 && a[j]>x)
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=x;
       }
    }

int main(){
    
    // ARRAY INPUT
    int n;
    printf("enetrt the number of elemenst");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("enter the element no %d\n",i+1);
        scanf("%d",&a[i]);
    }


    insertionSort(a,n);


    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

}