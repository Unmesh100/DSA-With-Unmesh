// Online C compiler to run C program online
#include <stdio.h>
void InsertionSort(int arr[],int n){
    int comparisons=0;
    int swaps=0;
    for(int i=1;i<n;i++){
        int k=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>k){
            arr[j+1]=arr[j];
            j--;
            comparisons++;
        }
        swaps++;
        arr[j+1]=k;
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
  InsertionSort(arr,n);
  printf("\n");

    return 0;
}