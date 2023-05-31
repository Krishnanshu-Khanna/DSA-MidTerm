#include<stdio.h>

void merge(int a[],int l,int mid,int h)
{
int i, j, k;
i=l;j=mid+1;k=l;
int b[h+1];
while (i<=mid && j <= h) // here it should be j<=h
{
if(a[i] < a[j])
{
b[k++] = a[i++];
}
else
{
b[k++] = a[j++];
}
}
for (; i <=mid; i++)
{
b[k++] = a[i];
}
for (; j <=h; j++)
{
b[k++] =a[j];
}
for(int i=l;i<=h;i++)
{
a[i]=b[i];
}
}


void mergeSort(int a[],int l,int h)
    {   int mid;
        if(l<h)
        {
            mid=(l+h)/2;
            mergeSort(a,l,mid);
            mergeSort(a,mid+1,h);
            merge(a,l,mid,h);

        }
    }


int main(){

    int a[] = {8,2,9,6,5,3,7,4};
    int m = sizeof (a) / sizeof (int);
    mergeSort(a,0,7);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ",a[i]);
    }
}