// LINEAR SEARCH

#include<stdio.h>
int main(){
    int key,n,b=1;
    printf("Enter the size of array");
    scanf("%d",&n);
    int a[n];
    printf("enter the numbers in array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the element to be found");
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(a[i]==key){
            printf("Elemt %d is present at %d",key ,i+1);
            b=0;
            break;
        }
        
    }
    if(b!=0){
        printf("element is not present");
    }
}

// BINARY SEARCH

#include <stdio.h>
int main()
{
    int i, low, high, mid, n, key, array[100];
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter %d integers\n", n);
    for(i = 0; i < n; i++)
        scanf("%d",&array[i]);
    printf("Enter value to find\n");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    mid = (low+high)/2;
    while (low <= high) {
        if(array[mid] < key)
            low = mid + 1;
        else if (array[mid] == key) {
            printf("%d found at location %d", key, mid+1);
            break;
            }
        else
            high = mid - 1;
            mid = (low + high)/2;
            }
        if(low > high)
            printf("Not found! %d isn't present in the list", key);
    return 0;
}