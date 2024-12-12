// Online C compiler to run C program online
#include <stdio.h>
void bubbleSort(int arr[],int n){
    int switched=0;
    int swaps=0;
    int comparisons=0;
    
    for(int i=0;i<n-1 && switched==0 ;i++){
        switched=1;
        for(int j=0;j<n-i-1;j++){
            comparisons++;
            if(arr[j]>arr[j+1]){
                swaps++;
                switched=0;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    
    for(int i=0;i<n;i++){
     printf("%d ",arr[i]);
  }
  printf("\n");
  
  printf("The no of switches %d and the no of comparisons is %d",swaps,comparisons);
    
}
int main() {
  printf("Mention the length of the array\n");
  int n;
  scanf("%d",&n);
  int arr[n];
  
  for(int i=0;i<n;i++){
      int a;
      scanf("%d",&a);
      arr[i]=a;
  }
  bubbleSort(arr,n);
  printf("\n");

    return 0;
}