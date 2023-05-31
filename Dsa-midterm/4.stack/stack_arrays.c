#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st){
    printf("Enter the Size of array: ");
    scanf("%d",&st->size);
    // st->size=50;
    st->top = -1;
    st->S=(int*)malloc(st->size*sizeof(int));
}

void Display(struct Stack st){

    for(int i=st.top;i>=0;i--){
        printf("%d\n",st.S[i]);  
    }
}

void push(struct Stack *st){
    if(st->top==st->size-1){
        printf("Stack Overflow");
    }
    else{
        st->top++;
        int x;
         printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        st->S[st->top]=x;
    }
}
void pop(struct Stack *st){
    int x=-1;
    if(st->top==-1){
        printf("Stack underflow");
    }
    else{
        x=st->S[st->top--];
        printf("Element popped is %d\n",x);
    }   
}

int peek(struct Stack st){
    int x=-1;
    int index;
    printf("Enter the Index value:");
    scanf("%d",&index);
    if(st.top-index<0){
        printf("Invalid Index\n");
    }
    else{
        x=st.S[st.top-index+1];
        printf("Element at index %d is %d\n",index,x);
    }
}
int main()
{
    struct Stack st;
    create(&st);

    // push(&st);
    // push(&st);
    // push(&st);
    // push(&st);
    // pop(&st);
    // Display(st);
    while(1){
        int choice,x;
        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.Peek\n5.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        
        if(choice>=1&&choice<=5){

        switch(choice){
            case 1:
                push(&st);
                break;
            case 2:
                pop(&st);
                break;
            case 3:
                Display(st);
                break;
            case 5:
                exit(0);
            case 4:
                peek(st);
        }
        }
        else{
            printf("Enter valid choice\n");
            
        }
    }
    return 0;
}