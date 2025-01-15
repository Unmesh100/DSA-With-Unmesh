
#include <stdio.h>
#include<stdlib.h>
//Initializing the stack using structure
struct Stack{
    int data;
    struct Stack* next;
};
//Creating create function to create new nodes
struct Stack* create(int data){
    struct Stack* node=(struct Stack*)malloc(sizeof(struct Stack));
    node->data=data;
    node->next=NULL;
    return node;
}
//Check weather a stack is Empty or not
int isEmpty(struct Stack* node){
    if(node==NULL){
        return 1;
    } 
    return 0;
}
//Push the data into the stack
struct Stack* push(struct Stack* head,int data){
    
    
    struct Stack* node=create(data);
    node->next=head;
    return node;
}
//Display the data
void display(struct Stack* head){
    struct Stack* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
         temp=temp->next;
    }
}
//Pop the top element(Last element pushed into the stack)
    struct Stack* pop(struct Stack* head){
        if(isEmpty(head)==1){
            printf("Your stack is empty");
            return NULL;
        }
        printf("%d",head->data);
        return head->next;
    }
    

int main() {
 printf("Press 1 to insert data into the stack\nPress 2 to pop out the data from the stack\nPress 3 to view the data stored in the stack\nPress any other key to exit the program\n");
 struct Stack* stack;
 while(1){
    int a;
    scanf("%d",&a);
    if(a==1){
        printf("Please enter the value that you want to push into the stack->");
        int b;
        scanf("%d",&b);
        stack=push(stack,b);
    }
    else if(a==2){
        stack=pop(stack);
    }
    else if(a==3){
        display(stack);
    }
    else{
        exit(0);
    }
 }
    return 0;
}