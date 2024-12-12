
#include <stdio.h>

int comparisons=0;
void merge(int arr[],int n,int left,int right,int mid){
    int n1=mid-left+1;
    int n2=right-mid;
    int arr1[n1];
    int arr2[n2];
    for(int i=0;i<n1;i++){
        arr1[i]=arr[left+i];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[mid+i+1];
    }
    int i=0;
    int j=0;
    int k=left;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            
            arr[k]=arr1[i];
           i++;
           k++;
        }
        else{
            arr[k]=arr2[j];
            j++;
            k++;
        }
        comparisons++;
    }
    while(i<n1){
        arr[k++]=arr1[i];
        i++;
    }
    while(j<n2){
        arr[k++]=arr2[j];
        j++;
    }
}
void MergeSort(int arr[],int n,int left,int right){
    if(right<=left)return;
   int mid=left+(right-left)/2;
   MergeSort(arr,n,left,mid);
   MergeSort(arr,n,mid+1,right);
   merge(arr,n,left,right,mid);
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
  MergeSort(arr,n,0,n-1);
  for(int i=0;i<n;i++){
     printf("%d ",arr[i]);
  }
 printf("\n");
  
  printf("The no of comparisons is %d",comparisons);
    return 0;
}