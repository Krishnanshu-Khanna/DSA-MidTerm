#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;

void create(int a[],int n)
{
    struct node *t,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->prev=first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;

    }
}

void display(struct node*p)
{
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int length(struct node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }return l;
}


void insert (struct node *p,int index,int x)
{
    struct node *t=NULL;
    if(index==0)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->next=first;
        first->prev=t;
        t->prev=NULL;
        first=t;
    }
    else
    {
        for(int i=1;i<index-1;i++)
        {
            p=p->next;
        }
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next)p->next->prev=t;
        p->next=t;
    }
}

int delete(struct node *p,int index)
{
    int x=-1,i;
    if(index<1||index>length(p))
        return -1;
    if(index==1)
    {
        first=first->next;
        if(first)first->prev=NULL;
        x=p->data;
        free(p);
    }
    else
    {
        for(i=1;i<index-1;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        free(p);

    }return x;
}


void reverse(struct node *p)
{
    struct node* temp;
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL&& p->next==NULL)
            first=p;
    }
}

int main(){
    int a[]={2,5,3,7,9};
    
    
    create(a,5);
    insert(first,3,69);
    reverse(first);
    display(first);
    printf("length is %d",length(first));
}