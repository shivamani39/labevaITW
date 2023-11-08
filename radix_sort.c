#include<stdio.h>

int getmax(int arr[],int n){
    int max=0;
    for (int i = 0; i < n; i++)
    {
        if (max<arr[i])
        {
            max=arr[i];
        }
        
    }
    return max;
    
}

void countsort(int arr[],int n,int pos){
    // int count[10]=0;
    int b[n+1];
    int max=(arr[0]/pos)%10;

    for (int i = 0; i < n; i++)
    {
        if (((arr[i]/pos)%10)> max)
        {
            max=arr[i];
        }
    }
    int count[max + 1];

    for (int i = 0; i < max; i++)
    {
        count[i]=0;
    }
    
    
    for (int i = 0; i < n; i++)
    {
        count[(arr[i]/pos)%10]++;
    }
    for (int i = 1; i < 10 ; i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for (int i = n-1; i >=0; i--)
    {
        b[count[(arr[i]/pos)%10]-1]=arr[i]; 
        count[(arr[i]/pos)%10]--;  
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]=b[i];
    }
    
    
    
    
}

void radixsort(int arr[],int n){
    int max=getmax(arr,n);
    for (int pos = 1; max/pos>0; pos*=10)
    {
        countsort(arr,n,pos);
    }
    
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main(){
    int arr[]={1,92,132,435,5,6,57,8,89,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    radixsort(arr,n);
    printArray(arr,n);
    
}