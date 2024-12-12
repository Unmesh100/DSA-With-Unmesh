// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
int size=1;
//Here we are defining a structure which 
//will store the data and next pointer
//to the next pointer points to the next element
struct Node{
  int data;
  struct Node* next;
  
  
};
//Here we are creating a node
struct Node* createNode(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
    
    return node;
    
}
//Here we are inserting a element at the front of the list
struct Node* insertFirst(struct Node* head,int data){
   
   struct Node* node=createNode(data);
   if(head==NULL)return node;
   node->next=head;
   
   size++;
   return node;
}
//Here we are inserting a element at the end of the list
struct Node* insertLast(struct Node* head,int data){
    struct Node* node=createNode(data);
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=node;
    node->next=NULL;
    size++;
    return head;
    
}
//Here we insert a value at a particular index
struct Node* insertAtkth(struct Node* head,int position,int data){
  if(position==0)return insertFirst(head,data);
  if(position==size)return insertLast(head,data);
  struct Node* node=createNode(data);
  struct Node* temp=head;
  while(position-1>0){
      temp=temp->next;
      position--;
  }
  struct Node* pre=temp;
  struct Node* next=temp->next;
  pre->next=node;
  node->next=next;
  size++;
  return head;
}
//The following function is used to print the list
void display(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
//The following function is used to delete a element at a particular index
struct Node* delete(struct Node* head,int position){
    if(position==0){
        size--;
        return head->next;
        }
  struct Node* temp=head;
  while(position-1>0){
      temp=temp->next;
      position--;
  }
  struct Node* pre=temp;
  struct Node* next=temp->next->next;
  pre->next=next;
  size--;
  return head;
  
}
//Does a linear search to find a specific value in the list
void search(struct Node* head,int value){
    struct Node* temp=head;
    int i=0;
    while(temp!=NULL){
        if(temp->data==value){
            printf("The %d is at index %d in the list",value,i);
            return;
        }
        temp=temp->next;
        i++;
    }
    printf("The %d do not exist in the list",value);
}
struct Node* reverse(struct Node* head){
    struct Node* pre=NULL;
    struct Node* current=head;
    struct Node* next=head->next;
    while(current!=NULL){
        current->next=pre;
        pre=current;
        current=next;
        if(next!=NULL)
        next=next->next;
    }
    return pre;
}
int main() {
   printf("Creating a double Linked List\n");
   printf("Press 0 to inset element at front\nPress 1 to insert at kth position\nPress 2 to delete at kth  postion\nPress 3 to find the index of an element in the list\nPress 4 to print the list\nPress 5 to insert at the last of the list\nPress 6 to reverse your list\nPress any other key to exit your program");
   struct Node* head;
   while(1){
      int a;
      scanf("%d",&a);
      if(a==0){
          printf("Please enter the data-->");
          int data;
          scanf("%d",&data);
         if(head==NULL)head=createNode(data);
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
          head=insertAtkth(head,k,data);
          
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
      else if(a==5){
           int data;
          scanf("%d",&data);
         if(head==NULL)head=createNode(data);
         else{
             head=insertLast(head,data);
         }
      }
      else if(a==6){
          head=reverse(head);
      }
      else if(a==4){
          display(head);
      }
      else{
          exit(0);
      }
   }
    
    
    
    
}