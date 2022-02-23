//5. WAP to Implement Singly Linked List with following operations
// a) Create a linked list.
// b) Insertion of a node at first position, at any position and at end of list.
// c) Display the contents of the linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    struct list *next;
}node;
node *head = NULL;

node *create(int data){
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    return temp;
}
void insert_beg(){
    int new_data;
    printf("\nEnter data : ");
    scanf("%d",&new_data);
    node *key = create(new_data);
    key->next = head;
    head = key;
}
void insert_pos(){
    int i,new_data, pos;
    printf("\nEnter data : ");
    scanf("%d",&new_data);
    node *key = create(new_data);
    printf("\nEnter pos : ");
    scanf("%d",&pos);
    node *temp = head;
    if(pos==0){
        key->next = head;
        head = key;
    }
    else{
        for(i=0;i<pos-1;i++){
            temp = temp->next;
            pos--;
        }
        key->next = temp->next;
        temp->next = key;
    }
}
void insert_end(){
    int i,new_data;
    printf("\nEnter data : ");
    scanf("%d",&new_data);
    node *key = create(new_data);
    if(head==NULL){
        head = key;
        key->next = NULL;
    }
    else{
    node *temp = head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next= key;
    key->next =NULL;
    }
}
void display(node *n){
    // printf("in");
    node *temp;
    temp = n;
    if(temp==NULL)
        printf("\nEmpty List");
    else{
        while(temp!=NULL){
            printf("\n%d",temp->data);
            temp=temp->next;
        }
    printf("\n");
    }
}
int main(){
    int ch=0;
    while(ch!=5){
        printf("\n1.Insert in the beginning \n2.Insert at any position \n3.Insert at the end \n4.Display \n5.Exit\nEnter choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insert_beg();
            break;

            case 2:
            insert_pos();
            break;

            case 3:
            insert_end();
            break;

            case 4:
            display(head);
            break;

            case 5:
            break;

            default : printf("\nWrong choice");
        }
    }
    printf("\nProgram terminated.\n");
}