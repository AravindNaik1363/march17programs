//Linked list insertion at specific position in C
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// required for insertAfter
int getCurrSize(struct Node* node){
    int size=0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}

//function to insert after nth node
void insertAfterNthNode(int n, int data, struct Node** head)
{
    int size = getCurrSize(*head);

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 
    newNode->data = data;
    newNode->next = NULL;
    
    // Can't insert if position to insert is greater than size of Linked List
    // can insert after negative pos
    if(n < 0 || n > size) 
        printf("Invalid position to insert\n"); 
        
    // inserting first node
    else if(n == 0){
        newNode->next = *head; 
        *head = newNode;
    }
    
    else 
    {
        // temp used to traverse the Linked List
        struct Node* temp = *head; 
        
        // traverse till the nth node
        while(--n)
            temp=temp->next;
        
        // assign newNode's next to nth node's next
        newNode->next= temp->next;
        // assign nth node's next to this new node
        temp->next = newNode;
        // newNode inserted b/w 3rd and 4th node
    }
}

void display(struct Node* node){
    
    printf("Linked List : ");
    
    // as linked list will end when Node is Null
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = NULL;

    //Inserts data: 10 as the first node
    insertAfterNthNode(0, 10, &head);
    
    //Inserts data: 20 after the first node
    insertAfterNthNode(1, 20, &head);
    
    //Inserts data: 30 after the 2nd node
    insertAfterNthNode(2, 30, &head);
    
    //Inserts data: 40 after the 3rd node
    insertAfterNthNode(3, 40, &head);
    
    display(head); 
   
    //Inserts data: 15 after the 1st node
    insertAfterNthNode(1, 15, &head);
    
    //Inserts data: 25 after the 3rd node
    insertAfterNthNode(3, 25, &head);

    display(head); 
    
    // Invalid: can't insert after -2 pos
    insertAfterNthNode(-2, 100, &head);
    
    // Invalid: Current size 8, trying to enter after 10th pos
    insertAfterNthNode(10, 200, &head);

    return 0; 
}
