// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#define maxSize 5
int stack[maxSize];
int top=-1;
int isFull(){
    if(top==maxSize-1){
        return 0;
    }
    return 1;
}
int isEmpty(){
    if(top==-1)return 0;
    return 1;
}
void push(int val){
    if(isFull()==0){
        printf("Overflow condition");
        return;
    }
    top++;
    stack[top]=val;
    
}
int pop(){
    if(isEmpty()==0){
         printf("Underflow condition");
         return -1;
    }
    int removed=stack[top];
    
    top--;
    return removed;
}
int peek(){
     if(isEmpty()==0){
         printf("Underflow condition");
         return -1;
    }
  return stack[top];
}
void display(){
    for(int i=0;i<=top;i++)printf("%d",stack[i]);
}
int main() {
    printf("Press 1 to insert data into the stack\nPress 2 to pop out the data from the stack\nPress 3 to view the data stored in the stack\nPress 4 to view the top element\nPress any other key to exit the program\n");

 while(1){
    int a;
    scanf("%d",&a);
    if(a==1){
        printf("Please enter the value that you want to push into the stack->");
        int b;
        scanf("%d",&b);
        push(b);
    }
    else if(a==2){
        if(isEmpty()==1)
        printf("%d",pop());
        else {
            printf("Underflow condition");
        }
    }
    else if(a==3){
        display();
    }
     else if(a==4){
         if(isEmpty()==1)
        printf("The top element is %d",peek());
        else printf("The stack is empty");
    }
    else{
        exit(0);
    }
 }
    return 0;

   
}