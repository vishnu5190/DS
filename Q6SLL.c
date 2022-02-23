//Q6. SLL 
// WAP to Implement Singly Linked List with following operations
// a) Create a linked list.
// b) Deletion of first element, specified element and last element in the list.
// c) Display the contents of the linked list.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;

void insert(){
    int new_data;
    printf("\nEnter data : ");
    scanf("%d",&new_data);
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = new_data;
    if(head==NULL)
        head = temp;
    else{
        struct node *ptr = head;
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void del_beg(){
    struct node *ptr = head;
    head = ptr->next;
    free(ptr);
}

void del_pos(pos){
    struct node *ptr1, *ptr2;
    ptr1=head;
    int i;
    // int pos;
    // printf("\nEnter pos : ");
    // scanf("%d",&pos);
    if(pos==0)
        del_beg();
    else{
        for(i=0;i<pos;i++){
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        ptr2->next = ptr1->next;
        free(ptr1);
    }
}

void del_end(){
    struct node *ptr2, *ptr = head;
    if(ptr->next==NULL){
        del_beg();
    }
    else{
    while(ptr->next!=NULL){
        ptr2 = ptr;
        ptr = ptr->next;
    }
    ptr2->next=NULL;
    free(ptr);
    }
}
void del_elt(){
    struct node *ptr1, *ptr2;
    int i, flag=0, elt, c=0;
    ptr1 = head;
    printf("\nEnter element to be deleted : ");
    scanf("%d",&elt);
    while(ptr1!=NULL){
        if(ptr1->data==elt){
            del_pos(c);
            flag=1;
        }
        ptr1=ptr1->next;
        c++;
    }
    if(flag==0)
        printf("\nElement not found");
}
void display(){
    struct node *temp;
    temp = head;
    if(temp==NULL)
        printf("\nEmpty List");
    else{
        printf("\nContents :");
        while(temp!=NULL){
            printf("\n%d",temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    int ch=0;
    printf("\n1.Insert elements \n2.Delete first element \n3.Delete specified element \n4.Delete last element \n5.Display \n6.Exit ");
    while(ch!=6){
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insert();
            break;

            case 2:
            del_beg();
            break;

            case 3:
            del_elt();
            break;

            case 4:
            del_end();
            break;

            case 5:
            display();
            break;

            case 6:
            break;

            default : printf("\nWrong choice");
        }
    }
    printf("\nProgram terminated.\n");
}