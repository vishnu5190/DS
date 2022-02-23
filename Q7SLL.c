//Q7SLL
// WAP Implement Single Link List with following operations
// a) Sort the linked list.
// b) Reverse the linked list.
// c) Concatenation of two linked lists

//avoid writing insert2() function, program can be improved by redesigning insert()
//practice merge and sorting lists

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *head1=NULL;

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
void insert2(){
    int new_data;
    printf("\nEnter data : ");
    scanf("%d",&new_data);
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = new_data;
    if(head1==NULL)
        head1 = temp;
    else{
        struct node *ptr = head1;
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}
struct node* sort(){
    struct node *ptr1, *ptr2=NULL;
    int swap, i, c=0;
    if(head==NULL)
        return head;
    do{
        swap=0;
        ptr1 = head;
        while(ptr1->next!=ptr2){
            if(ptr1->data>ptr1->next->data){            //checks condition and swaps the data, sets swap=1
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swap = 1;
            }
            ptr1=ptr1->next;                            //next node
        }
        ptr2 = ptr1;  
    }while(swap);        //any non-zero int means infinite loop
    return head;
}

void reverse(){
    struct node *curr = head;
    struct node *prev, *next;
    prev = next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void concat(struct node *first, struct node *second){
    struct node *ptr;
    if(first!=NULL && second!=NULL){
        if(first->next==NULL)
            first->next = second;
        else
            concat(first->next,second);
    }
    else{
        printf("\neither node is null");
    }
}

void display(struct node *ptr2){
    struct node *ptr;
    ptr=ptr2;
    while(ptr!=NULL){
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main(){
    int ch=0;
    while(ch!=6){
        printf("\n1.Insert elements \n2.Reverse \n3.Sort \n4.Concatenate \n5.Display \n6.Exit \nEnter choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insert();
            break;

            case 2:
            reverse();
            display(head);
            break;

            case 3:
            sort();
            display(head);
            break;

            case 4:
            concat(head, head1);
            break;

            case 5:
            display(head);
            break;

            case 6:
            break;

            default : printf("\nWrong choice");
        }
    }
    printf("\nProgram terminated.\n");
}