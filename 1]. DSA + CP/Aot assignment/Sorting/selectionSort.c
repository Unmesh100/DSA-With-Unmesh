
#include <stdio.h>
void SelectionSort(int arr[],int n){
    int switched=0;
    int swaps=0;
    int comparisons=0;
  for(int i=0;i<n-1;i++){
      int min=i;
      for(int j=i+1;j<n;j++){
          comparisons++;
          if(arr[j]<arr[min]){
              
              min=j;
          }
      }
      int temp=arr[i];
      arr[i]=arr[min];
      arr[min]=temp;
      swaps++;
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
  SelectionSort(arr,n);
  printf("\n");

    return 0;
}