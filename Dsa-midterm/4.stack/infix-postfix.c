#include <stdio.h>
#include <ctype.h>

int top = -1;
const int max = 50;
char stack[50];

void push(char a)
{
    if((top+1)!=max)  {
        stack[++top] = a;
    }
    else{
        printf("\nStack filled\n");
    }
}

char pop()
{
    if(top==-1) {
        printf("\nNothing to display\n");
    }
    else{
        return (stack[top--]);
    }
    
}
 
void display()
{
    printf("\n\t%c\n", stack[top]);
}

int priority(char op)
{
    if(op == '+' || op=='-')    {
        return 1;   
    }
    else if (op=='*'|| op=='/') {
        return 2;
    }
    else if (op=='^')   {
        return 3;
    }
    return 0;
}

int main()
{
    //int hch = 9;
    int u=0;
    char exp[50];
    //printf("Enter expression\t");
    scanf("%s",exp);
    char ch = ' ', temp = ' ';
    int i= 0, stlen = 0;
    do  {
        temp = exp[i++];
        if (temp!= '\0')
            stlen++;
        else    
            break;
    }while(1);        //Calculated actual length of given string
    //stlen=50;
    for(i=0;i<stlen;i++)    {
        ch = exp[i];
        switch(ch)
        {
            case '(':
                    push(ch);
                    break;
            case ')':
                    do  {
                        //hch = 9
                        temp = pop();
                        //printf("%c", temp);
                        //temp=stack[top--];
                        if (temp=='(' || temp==')')
                            u--;
                        else
                            printf("%c",temp);
                    } while(temp!='(');
                    break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^': 
                    while (priority(stack[top]) >= priority(ch))    {
                        temp=pop();
                        //printf("%c",temp);
                        if (temp=='(' || temp==')')
                            u--;
                        else
                            printf("%c",temp);
                    }
                    push(ch);
                    break;
            default:
                    printf("%c",ch);
                    break;
        }
    }
    while(top>-1){
        temp=stack[top--];
        if (temp=='(' || temp==')')
            u--;
        else
            printf("%c",temp);
    }return 0;
}