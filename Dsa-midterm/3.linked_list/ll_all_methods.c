#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL;                                    //global pointer

void create(int a[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
        }
}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int count(struct Node *p){
    int i=0;
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}

int sum(struct Node *p)
{
    int sum=0;
    while(p)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int max(struct Node *p)
{
    int max=0;
    while(p)
    {   
        if(p->data>max){
            max=p->data;
        }
        p=p->next;
    }
    return max;
}

int search(struct Node *p,int x)
{
    int flag=0,count=0;
    while (p)
    {
        count++;
        if(x==p->data){
            flag=1;
            
            break;
        }
        p=p->next;
    }
    if(flag==1){
        printf("\nelement %d is present at %d",x,count);
    }
    else{
        printf("\nelemnt not present in linked list");
    }
}

void insert(struct Node *p,int index ,int value)
{   
    struct Node *t;

    if(index<0||index>count(p)){
        return;
    }
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=value;

    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

void sortedInsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL){
        first=t;
    }
    else{
        while(p&&p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;  
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}

int delete(struct Node *p,int index)
{
    struct Node *q;
    int x=-1;

    if(index<0 || index>count(p))
        return -1;
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}


/*void Reverse1(struct Node *p)
{
 int *A,i=0;
 struct Node *q=p;

 A=(int *)malloc(sizeof(int)*count(p));

 while(q!=NULL)
 {
 A[i]=q->data;
 q=q->next;
 i++;
 }
 q=p;
 i--;
 while(q!=NULL)
 {
 q->data=A[i];
 q=q->next;
 i--;
 }
}*/

void Reverse(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

/*void Reverse3(struct Node *q,struct Node *p)
{
 if(p)
 {
 Reverse3(p,p->next);
 p->next=q;
 }
 else
 first=q;
}
*/

int isSorted(struct Node *p)
{
    int x=-65536;

    while(p!=NULL)
    {
        if(p->data < x)
        return 0;
        x=p->data;
        p=p->next;
    }
    return 1;

}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q=p->next;

    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
        p=q;
        q=q->next;
        }
        else
        {
        p->next=q->next;
        free(q);
        q=p->next;
        }
    }

}

int main(){
    // int a[]={1,2,34,4,7,654,3};
    // int n=sizeof(a)/4;
    
    // create(a,n);
    // Display(first);
    insert(first,0,10);
    Display(first);
    /*search(first,4);
    printf("\nthe no of nodes is %d in the given linked list",count(first));
    printf("\nthe sum of nodes is %d in the given linked list",sum(first));
    printf("\nthe max of nodes is %d in the given linked list",max(first));*/
    return 0;
}