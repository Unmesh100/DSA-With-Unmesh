
#include <stdio.h>

int comparisons=0;
int partitions(int arr[],int n,int low,int high){
    int pivot=arr[high];
    
    int i=low-1;
    
    for(int j=low;j<=high-1;j++){
        
        if(arr[j]<pivot){
            comparisons++;
            
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    
    return i+1;
}
void QuickSort(int arr[],int n,int low,int high){
    if(high<=low)return;
    int partition=partitions(arr,n,low,high);
    QuickSort(arr,n,low,partition-1);
    QuickSort(arr,n,partition+1,high);
    
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
  QuickSort(arr,n,0,n-1);
  for(int i=0;i<n;i++){
     printf("%d ",arr[i]);
  }
 printf("\n");
  
  printf("The no of switches %d and the no of comparisons is %d",swaps,comparisons);
    return 0;
}