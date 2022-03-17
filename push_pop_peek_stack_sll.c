/*Implementation of stack using single linked list*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}stack;


void push(stack **top,int data)
{
    stack *newnode=(stack *)malloc(sizeof(stack));
    if(newnode==NULL)
    {
        printf("memory not allocated\n");
    }
    else
    {
        newnode->data=data;
        newnode->link=NULL;
        
        if(*top==NULL)
        {
            *top = newnode;
        }
        else
        {
            newnode->link = *top;
            *top = newnode;
        }
        printf("The pushed data=%d\n",(*top)->data);
    }
    
}

void pop(stack **top)
{
    if(*top == NULL)
    {
        printf("Stackis empty\n");
    }
    else
    {
        stack *temp = *top;
        *top = temp->link;
        printf("The poped element is:%d\n",temp->data);
        free(temp);
    }
}

void peek(stack **top)
{
    if(*top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The Top most element is: %d\n",(*top)->data);
    }
}


void display(stack **top)
{
    stack *temp = *top;
    if(*top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack contains:\n");
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
int main()
{
    stack *top=NULL;
    push(&top,10);
    push(&top,20);
    push(&top,30);
    display(&top);
    peek(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    display(&top);
    return 0;
}
