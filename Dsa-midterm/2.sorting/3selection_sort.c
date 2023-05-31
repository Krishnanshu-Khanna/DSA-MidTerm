#include<stdio.h>

void swap(int*x,int*y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void selectionSort(int a[],int n)
    {   
        int i,j,k;
        for(int i=0;i<n-1;i++)
        {
            for(j=k=i;j<n;j++)
            {
                if(a[j]<a[k])
                {
                    k=j;
                }
            }
            swap(&a[i],&a[k]);
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


    selectionSort(a,n);


    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

}