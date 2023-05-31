#include<iostream>
using namespace std;
class node
{  public :
    int data;
    node *next;
};
class stack
{
    private:
    node *top;
    public:
    stack(){top = NULL;}
    void push(int x);
    int pop();
    void display();
};
 void stack::push(int x)
{
    node *t =new node;
    if(t == NULL) 
    {
        cout<<"stack is full \n";
    }
    else
    { t->data =x;
    t->next =top;
    top =t;
    }
}
 int stack::pop()
{   
    int x =-1;
    if(top == NULL)
    {
      cout<<"stack is empty\n";
    }else{
        x =top->data;
        node*p =top;
        top =top->next;
        delete p;
    }
    return x;
}
void stack::display()
{  node *p=top; 
   while(p!=NULL)
    {    
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{  
    stack st;
    st.push(4);
    st.push(7);
    st.push(9);
    st.display();
    cout<<st.pop()<<endl;
    st.display();
 
}