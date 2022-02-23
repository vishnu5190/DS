//DLL
/* WAP Implement doubly link list with primitive operations
 a) Create a doubly linked list.
 b) Insert a new node to the left of the node.
 c) Delete the node based on a specific value
 d) Display the contents of the list */
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;

void insert(){              //    inserts nodes at the end
    int data;
    printf("\nEnter data : ");
    scanf("%d",&data);
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    ptr = head;
    new_node->data = data;
    new_node->next = NULL;
    if(head==NULL){
        new_node->prev = NULL;
        head = new_node;
    }
    else{
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->prev = ptr;
    }
}

void insert_left(){
    if(head==NULL){
        printf("\nEmpty List");
        return;
    }
    int i,data, pos;
    struct node *ptr1, *ptr2, *new_node;   //ptr1 to store prev node and ptr2 to store next node    
    new_node = (struct node*)malloc(sizeof(struct node));
    ptr1 = head;
    ptr2 = NULL;
    printf("\nEnter data : ");
    scanf("%d",&data);
    new_node->data = data;
    printf("\nEnter pos  : ");
    scanf("%d",&pos);
    if(pos==0){    //ptr1 is head;
        new_node->next = ptr1;
        new_node->prev = NULL;
        ptr1->prev = new_node;
        head = new_node;

    }
    else{
    for(i=0;i<pos-1;i++){
        printf("\nptr1->data = %d",ptr1->data);
        printf("\nINSIDE loop");
        ptr1 = ptr1->next;
    }
    ptr2 = ptr1->next;
    ptr1->next = new_node;
    new_node->prev = ptr1;
    new_node->next = ptr2;
    ptr2->prev = new_node;
    }
}

void del_val(){
    int val, i=0;
    printf("\nEnter value : ");
    scanf("%d",&val);
    struct node *ptr1, *ptr2, *ptr3; 
    ptr1 = head;                    
    while(ptr1!=NULL){
        if(ptr1->next==NULL){
            printf("\n%d not found",val);
            return;
        }
        ptr1 = ptr1->next;
    }
    ptr2 = ptr1->prev;
    if(ptr1->next==NULL){           //if last node
        ptr2->next = NULL;
    }                
    else{
    ptr3 = ptr1->next;
    ptr2->next = ptr3;
    ptr3->prev = ptr2;
    }
    free(ptr1);
    // }
}
void display(){
    struct node *temp;
    temp = head;
    if(temp==NULL)
        printf("\nEmpty List\n");
    else{
    printf("\nContents : ");
    while(temp!=NULL){
        printf("\n%d",temp->data);
        temp = temp->next;
        }
    }
}
int main(){
    int ch;
    while(1){
        printf("\n1. Create a DLL \n2. Insert a node to the left of a node \n3. Delete a given value \n4. Display \n5. Exit \nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : 
            insert();
            break;

            case 2 : 
            insert_left();
            break;

            case 3 : 
            del_val();
            break;

            case 4 : 
            display();
            break;

            case 5 : 
            printf("\nProgram terminated");

            default : printf("\nWrong choice, Enter again : ");
        }
    }
}