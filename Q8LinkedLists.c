//Program to implement stacks and queues using linked lists
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void push(struct node **head_ref, int new_data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void EnQ(struct node **head_ref, int new_data){     
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    struct node *temp; 
    if(*head_ref==NULL){
        new_node->next = NULL;
        *head_ref = new_node;
        printf("\nNode inserted.\n");
    }
    else{
        temp = *head_ref;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
}
}
void pop(struct node **head_ref){
    int d; 
    struct node *ptr;
    ptr = *head_ref;
    d = ptr->data;
    *head_ref = ptr->next;
    free(ptr);
    printf("\nPopped element : %d",d); 
}

void DeQ(struct node **head_ref){
    int d;
    struct node *ptr;
    struct node *ptr2;
    ptr = *head_ref;
    if(*head_ref==NULL){                    //if list is empty
        printf("\nUnderflow");
    }
    else if(ptr->next == NULL){             //for deleting only element, works
        d = ptr->data;
        *head_ref=NULL;
        free(*head_ref);
        printf("\nDeleted element : %d",d);
    }
    else{                                  //when list has more than one element
    ptr = *head_ref;
    while(ptr->next!=NULL){
        ptr2 = ptr;
        ptr=ptr->next;
    }
    d = ptr->data;
    ptr2->next = NULL;
    free(ptr);
    printf("\nDequeued element : %d",d);
    }
}
void display (struct node *n)
{
    if(n==NULL)
    printf("\nEmpty List");
    else{
        while(n != NULL){
            printf ("\n%d", n->data);
            n = n->next;
        }
        printf("\n");
    }
}

int main(){
    int ch;
    struct node *head = NULL;
    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Push\n4. Pop\n5. Display\n6. Exit\nEnter your choice : ");
        scanf("%d",&ch);
        int data;
        switch(ch){
            case 1 :
                printf("\nEnter a number : ");
                scanf("%d",&data);
                EnQ(&head, data);
            break;

            case 2 :
                DeQ(&head);
            break;

            case 3 :
                printf("\nEnter a number : ");
                scanf("%d",&data);
                push(&head, data);
            break;

            case 4:
                if(head==NULL)
                    printf("\nUnderflow");
                else
                    pop(&head);
            break;

            case 5:
                display(head);
            break;

            case 6:
                exit(1);
            default : printf("\nWrong Choice\n");
        }
    }
}