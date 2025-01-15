//Note:peek() and display operation is optional 
#include <stdio.h>
#include <stdlib.h>
#define maxSize 1000
char stack[maxSize];
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
char pop(){
    if(isEmpty()==0){
      
         return '0';
    }
    char removed=stack[top];
    
    top--;
    return removed;
}
int peek(){
     if(isEmpty()==0){
         printf("Underflow condition");
         return '0';
    }
  return stack[top];
}
int prec(char c) {
    
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
void infixToPostfix(char arr[],int n){
    for(int i=0;i<n;i++){
        if((int)arr[i]>='a' &&(int)arr[i]<='z'){
            printf("%c",arr[i]);
        }
        else if(arr[i]=='(')push('(');
        else if(arr[i]==')'){
            while(isEmpty()==1 && peek()!='(')printf("%c",pop());
           pop();
        }
        else{
            while(isEmpty()==1 && prec(peek())>=prec(arr[i]))printf("%c",pop());
            push(arr[i]);
        }
        
    }
    while(isEmpty()==1){
            printf("%c",pop());
        }
}
int main() {
  while(1){
      printf("Please write the length of the expression");
      int a;
      scanf("%d",&a);
      printf("Write your expression");
      char str[a];
      scanf("%s",&str);
      printf("The value of the expression is ");
      infixToPostfix(str,a);
      printf("\n");
      
  }

    return 0;
}