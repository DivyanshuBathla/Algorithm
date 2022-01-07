#include<stdio.h>
int partition(int *arr,int s,int e)
{
    int pivot=arr[s];
    int j=s;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<pivot)
        {
           j++;
           int temp=arr[j];
           arr[j]=arr[i];
           arr[i]=temp;
        }
    }
          int temp=arr[s];
           arr[s]=arr[j];
           arr[j]=temp;
    return(j);
}
void quick_sort(int *arr,int s,int e)
{
    if(s==e||s>e)
    return;
    else
    {
        int t=partition(arr,s,e);
        quick_sort(arr,s,t-1);
        quick_sort(arr,t+1,e);
    }
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
    quick_sort(arr,0,n-1);
    printf("The elements are=");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}
