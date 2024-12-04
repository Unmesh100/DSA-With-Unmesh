
#include <stdio.h>
#include<stdlib.h>
//Initializing the queue using structure
struct Queue{
    int data;
    struct Queue* next;
    struct Queue* pre;
};
struct Queue* tail=NULL;
struct Queue* create(int data){
    struct Queue* node=(struct Queue*)malloc(sizeof(struct Queue));
    node->data=data;
    node->next=NULL;
    return node;
}
//Check weather a queue is Empty or not
int isEmpty(struct Queue* node){
    if(node==NULL){
        return 1;
    } 
    return 0;
}
//Push the data into the queue
struct Queue* push(struct Queue* head,int data){
    
    
    struct Queue* node=create(data);
   if(tail==NULL){
       tail=node;
       return node;
   }
   else{
       tail->next=node;
       node->pre=tail;
       tail=node;
   }
   return head;
}
//Display the data
void display(struct Queue* head){
    struct Queue* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
         temp=temp->next;
    }
}
//Pop the top element (First element int the queue)
    struct Queue* pop(struct Queue* head){
       
      if(isEmpty(head)==1){
            printf("Your queue is empty");
            return NULL;
        }
         if(head==tail){
            printf("%d",head->data);
            tail=NULL;
            return NULL;
        }
        printf("%d",head->data);
        return head->next;
    }
    

int main() {
 printf("Press 1 to insert data into the queue\nPress 2 to pop out the data from the queue\nPress 3 to view the data stored in the queue\nPress any other key to exit the program\n");
 struct Queue* queue;
 while(1){
    int a;
    scanf("%d",&a);
    if(a==1){
        printf("Please enter the value that you want to push into the Queue->");
        int b;
        scanf("%d",&b);
        queue=push(queue,b);
    }
    else if(a==2){
        queue=pop(queue);
    }
    else if(a==3){
        display(queue);
    }
    else{
        exit(0);
    }
 }
    return 0;
}
