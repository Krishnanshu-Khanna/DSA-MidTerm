#include<stdio.h>

void swap(int*x,int*y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void bubbleSort(int a[],int n)
    {
        int i,j,flag=0;

        for(int i=0;i<n-1;i++)
        {
            flag=0;
            for(int j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    swap(&a[j],&a[j+1]);
                    flag=1;
                }
            }
            if(flag==0)
            {
                 break;  //reduces the time if no swap it stops
            }
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


    bubbleSort(a,n);


    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

}