#include <stdio.h>
#include <stdlib.h>
 
 
int findMax(int A[],int n)
 
{
 
    int max=-1234;
 
    int i;
 
    for(i=0;i<n;i++)
 
    {
 
        if(A[i]>max) //changes remove ; 
 
        max=A[i];
 
    }
 
    return max;
 
}
 
void CountSort(int A[],int n)
 
{
 
    int i,j,max,*C;
 
 
 
    max=findMax(A,n);
    
 
 
 
    C=(int *)malloc(sizeof(int)*(max+1));
 
    for(i=0;i<max+1;i++)
 
    {
 
        C[i]=0;
 
    }
 
    for(i=0;i<n;i++)
 
    {
 
        C[A[i]]++;
 
    }
 
    i=0;j=0;
 
    while(j<max+1)
 
    {
 
        if(C[j]>0)
 
        {
 
            A[i++]=j;
 
            C[j]--;
 
        }
 
        else
 
            j++;
 
    }
    
    free(C);
 
}
 
int main()
 
{
 
    int A[]={10,9,8,7,1,8,4,3,2,1};
 
    int i;
 
    CountSort(A,10);
 
 
 
    for(i=0;i<10;i++)
 
    {
 
        printf("%d ",A[i]);
 
    }
 
    printf("\n");
 
    return 0;
 
}