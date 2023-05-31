# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define MAX 100
char str[MAX];
char stack[MAX];
int top=-1;
char prefix[MAX];
int c=0;
int  check(char c1)
{
    if (c1=='^')
    return 4;
    if (c1=='*'|| c1=='/')
    return 3;
    if (c1=='+'||c1=='-')
    return 2;
    else
    return -1;
}
void pop1()
{
    for(int i=top;i>=0;i--)
    {
        if(stack[i]==')')
        {
            
            top--;
            break;
        }
        else
        {
        prefix[c++]=stack[top--];
        
        }
    }
}
int main()
{
    scanf("%s",str);
    char chty[50];
    scanf("%s",chty);
    for(int i=strlen(str)-1;i>=0;i--)
    {
        if (str[i]==')')
        stack[++top]=str[i];
        else if(str[i]=='+'||str[i]=='-'|| str[i]=='*'||str[i]=='/'||str[i]=='^')
        {
            if(top==-1)
            {
                stack[++top]=str[i];
            }
            else
            {
                int prec=check(str[i]);
                while(prec<check(stack[top]) && top!=-1)
                {
                    prefix[c++]=stack[top--];
   
                }
                stack[++top]=str[i];
                
            }
        }
        else if(str[i]=='(')
        {
            pop1();
        }
        else
            prefix[c++]=str[i];
    }
    for(int i=top;i>=0;i--)
    prefix[c++]=stack[i];
    for(int i=c;i>=0;i--)
    {
        if (prefix[i]!='\0')
            printf("%c",prefix[i]);
    }
}
