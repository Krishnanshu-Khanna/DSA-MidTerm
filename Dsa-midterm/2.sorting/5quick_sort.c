#include<stdio.h>

void swap(int*x,int*y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}


int partition(int a[],int l,int h)
{
    int pivot=a[l];
    int i=l,j=h;

    do{
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);

        if(i<j)swap(&a[i],&a[j]);
    }while(i<j);
    swap(&a[l],&a[j]);
    return j;

}


void quickSort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(a,l,h);
        quickSort(a,l,j);
        quickSort(a,j+1,h);
    }
}


int main()
{   
    int INT32_MAX;
    int a[]={11,13,7,12,16,9,24,5,10,3,INT32_MAX};
    int n=11,i;

    quickSort(a,0,n-1);

    for(int i=0;i<n-1;i++){
        printf("%d ",a[i]);
    }
    printf("\n");



}