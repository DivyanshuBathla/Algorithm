#include<stdio.h>
void heapify_top(int *arr,int i,int n)
{
    if(arr[i]>arr[2*i+1] && arr[i]>arr[2*i+2])
    return;
    else{
        
        if(i*2+1<=n-1 && i*2+2<=n-1)
        { 
          if(arr[i*2+1]>arr[i*2+2])
          {
            int x=arr[i];
            arr[i]=arr[i*2+1];
            arr[i*2+1]=x;
            i=i*2+1;
            heapify_top(arr,i,n);
          }
          else
          {
        
            int x=arr[i];
            arr[i]=arr[i*2+2];
            arr[i*2+2]=x;
            i=i*2+2;
            heapify_top(arr,i,n);
            
          }
        }
        else if(i*2+1<=n-1)
        {
            if(arr[i]<arr[i*2+1])
            { 
            int x=arr[i];
            arr[i]=arr[i*2+1];
            arr[i*2+1]=x;
            i=i*2+1;
            heapify_top(arr,i,n);
            }
        }
    }
}
void build_heap(int * arr,int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify_top(arr,i,n);
    }
}
void delete(int *arr,int n)
{
     int x=arr[0];
     arr[0]=arr[n-1];
     arr[n-1]=x;
     heapify_top(arr,0,n-1);
           
}
int main()
{
    int n;
    printf("Enter the number of elements you want in array=");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the elements in array=");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    build_heap(arr,n);
    for(int i=0;i<n-1;i++)
    {
        delete(arr,n-i);
    }
    printf("The elements are=");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}
