//Note:peek() and display operation is optional 
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
int evaluation(char string[],int n){
    for(int i=0;i<n;i++){
        if(string[i]=='0'||string[i]=='1'||string[i]=='2'||string[i]=='3'||string[i]=='4'||string[i]=='5'||string[i]=='6'||string[i]=='7'||string[i]=='8'||string[i]=='9'){
            push(string[i]-'0');
        }
        else{
            int a=pop();
            int b=pop();
            char ch=string[i];
            if(ch=='+'){
                push(a+b);
            }
            else if(ch=='-')push(b-a);
            else if(ch=='*')push(b*a);
            else push(b/a);
        }
    }
    return peek();
}
int main() {
  while(1){
      printf("Please write the length of the expression");
      int a;
      scanf("%d",&a);
      printf("Write your expression");
      char str[a];
      scanf("%s",&str);
      printf("The value of the expression is %d\n",evaluation(str,a));
      
  }

    return 0;
}