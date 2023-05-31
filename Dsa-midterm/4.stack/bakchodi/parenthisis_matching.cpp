#include <stdio.h>
 #include <stdlib.h>
 
struct Node{
    char data;
    struct Node *next;
}*top=NULL;
 
void push(char x){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if (t==NULL)
    {
        printf("stack overflowed\n");
    }else{
        t->data=x;
        t->next=top;
        top=t;
    }
    
}
 
char pop(){
    struct Node *t;
    char x=-1;
    if (top==NULL)
    {
        printf("stack is empty\n");
    }else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
    
}
 
void Display(){
    struct Node *p;
    p=top;
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
 
// check no. of paranthesis is balanced or not ()
int isBalanced(char *exp){
    int i;
 
    for ( i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(exp[i]);
        }else if (exp[i]==')')
        {
            if (top==NULL)
            {
                // returns 0 if not balanced
               
                return 0;
            }
            char x=pop();
            printf("bal value is: %d \n",x);  //changes here dont pop multiple times
        }
    }
    if (top==NULL)
    {
        return 1;
    }else{
                // returns 0 if not balanced
     while(top)   //making stack empty changes
        {
                Node *t=top;
                top=top->next;
                free(t);
        }
        
        return 0;
    }   
}
 
// checks for other types of brackets if balanced or not
int isBalancedForAll(char *exp){
    int i;
    int x;
 
    for ( i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(exp[i]);
        }else if (exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(top==NULL){ //changes
                return 0;
            }
            x=pop();
            // ASCII code = (=40 )=41 [=91 ]=93 {=123 }=125
            if (x!=40 && exp[i]==')')
            {
                return 0;
            }
            if (x!=91 && exp[i]==']') //changes
            {
                return 0;
            }
            if (x!=123 && exp[i]=='}')
            {
                return 0;
            }
            printf("\nvalue = %d \n",x);
            
            
        }
    }
    if (top==NULL)
    {
        return 1;
    }else{
                // returns 0 if not balanced
        while(top)   //making stack empty changes
        {
                Node *t=top;
                top=top->next;
                free(t);
        }
        return 0;
    }
    
    
}
 
 int main(){
     //for paranthesis is balanced or not 1-true-balanced 0-false-notbalanced
     char *exp = "((a+b)*(c-d))";
    printf("balanced paranthesis: %d \n",isBalanced(exp));
    
    //checks for all type of brackets 
    char *exp1 = "(((((()))))){[]}[[]]{{}}[]";
    printf("balanced paranthesis for all: %d \n",isBalancedForAll(exp1));
 
    //----------------------------------------------------------------// 
     push(10);
     push(11);
     push(12);
 
 
     Display();
     pop();
     printf("%d ",pop());
    Display(); 
 
     return 0;
 }