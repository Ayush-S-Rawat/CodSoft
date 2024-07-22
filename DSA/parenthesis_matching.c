#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *next;
}*top=NULL;

void push(char x)
{
     struct node *t=(struct node*)malloc(sizeof(struct node));
     t->data=x;
     t->next=top;
     top=t;
}

char pop()
{
    char x=-1;
    if(top==NULL)
    printf("stack is empty \n");
    else
    {struct node *p=top;
    top=top->next;
    x=p->data;
    free(p);}
    return x;
}

// void display(char *exp[])
void display(char exp[])
{
    struct node *p=top;int i=0,q=0;
    while(p!=NULL)
    {
        printf("%c",p->data);
        exp[i++]=p->data;
        // q=i;
        // exp[q]='\0';
        p=p->next;
    }
        exp[i++]='\0';
}

int main()
{
    push(')');
    push('b');
    push('+');
    push('a');
    push('(');
    // char *exp[5];
    char exp[6];
    display(exp);
    printf("\n");
    for(int i=0;exp[i]!='/0';i++)
    // for(int i=0;i<5;i++)
    printf("%c",exp[i]);
    return 0;
}