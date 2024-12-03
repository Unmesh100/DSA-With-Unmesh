
#include <stdio.h>
#include<stdlib.h>
//Defining the components of our linked list 
struct Node{
    int data;
    struct Node* next;
};
int size=1;
//tail is the last element in our circular linked list which is connected to the head
struct Node* tail=NULL;
//Creating our linked list
struct Node* create(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
     
    return node;
   
}
//Here we are inserting a element at the front of the list
struct Node* insertFirst(struct Node* head,int data){
    
    struct Node* node=create(data);
    if(tail!=NULL){
    
    
    node->next=head;
    tail->next=node;
    }
    else{
        tail=node;
        return node;
    }
    size++;
    return node;
}
//The following function is used to print the list
void display(struct Node* head){
    if(head==NULL){
        printf("NULL");
        return;
    }
    struct Node* temp=head;
    while(temp!=tail){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d->",temp->data);
}
//Here we are inserting a element at the end of the list
struct Node* insertLast(struct Node* head,int data){
    struct Node* node=create(data);
    if(tail==NULL)return insertFirst(head,data);
    else{
        tail->next=node;
        node->next=head;
        tail=node;
    }
    size++;
    return head;
}
//Here we insert a value at a particular index
struct Node* insert(struct Node* head,int k,int data){
    if(k==size)return insertLast(head,data);
    if(k==0)return insertFirst(head,data);
    struct Node* node=create(data);
    struct Node* temp=head;
    while(k-1!=0){
        temp=temp->next;
        k--;
    }
    struct Node* pre=temp;
    struct Node* current=temp->next;
    struct Node* next=current->next;
    
    pre->next=node;
    node->next=current;
    size++;
    return head;
    
}
//The following function is used to delete a element at a particular index
struct Node* delete(struct Node* head,int k){
    if(k==0){
        if(head==tail)return NULL;
        head=head->next;
        tail->next=head;
        size--;
        return head;
    }
    
    int length=k;
    struct Node* temp=head;
    while(k-1!=0){
        temp=temp->next;
        k--;
    }
   
    struct Node* pre=temp;
    
    struct Node* current=temp->next;
    struct Node* next=current->next;
    
    pre->next=next;
    if(length==size-1){
        tail=pre;
    }
    size--;
    return head;
}
//Does a linear search to find a specific value in the list
void search(struct Node* head,int value){
    struct Node* temp=head;
    int i=0;
    while(temp!=tail){
        if(temp->data==value){
            printf("The value %d is at index %d",value,i);
            
            return;
        }
        temp=temp->next;
        i++;
    }
    if(temp->data==value){
        printf("The value %d is at index %d",value,i);
            
            return;
    }
    printf("The value does not exist in  the linked list");
}
int main() {
    printf("Creating a double Linked List\n");
   printf("Press 0 to inset element at front\nPress 1 to insert at kth position\nPress 2 to delete at kth  postion\nPress 3 to find the index of an element in the list\nPress 4 to print the list\nPress 5 to end your program");
   struct Node* head;
   while(1){
      int a;
      scanf("%d",&a);
      if(a==0){
          printf("Please enter the data-->");
          int data;
          scanf("%d",&data);
         if(head==NULL){
             head=create(data);
             tail=head;
         }
         else{
             head=insertFirst(head,data);
         }
      }
      else if(a==1){
          printf("Please enter the data-->");
          int data;
          scanf("%d",&data);
          printf("\n Please enter the index where you want to insert at-->");
          int k;
          scanf("%d",&k);
          head=insert(head,k,data);
          
      }
      else if(a==2){
           
          printf("\n Please enter the index where you want to delete at-->");
          int k;
          scanf("%d",&k); 
          head=delete(head,k);
      }
      else if(a==3){
          printf("Please enter the element that you want to search-->");
          int data;
          scanf("%d",&data);
          search(head,data);
      }
      else if(a==4){
          display(head);
      }
      else{
          exit(0);
      }
   }
    return 0;
}