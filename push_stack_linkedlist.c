#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}stack;
void push(stack **top,int data)
{
  stack *newnode=(stack *)malloc(sizeof(stack));
  if(newnode==NULL)
  {
    printf("memory is not allocated");
  }
  else
  {
    newnode->data=data;
    newnode->next=NULL;
    if(*top==NULL)
    {
      *top=newnode;
    }
    else
    {
      newnode->next=*top;
      *top=newnode;
    }
    printf("The pushed data=%d\n",(*top)->data);
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
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
  stack *top=NULL;
  printf("address of top is:%p",&top);
  push(&top,10);
  push(&top,20);
  push(&top,30);
  display(&top);
  return 0;
}
