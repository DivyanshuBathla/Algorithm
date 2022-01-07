#include<stdio.h>
void merging(int *arr,int s1,int e1,int s2,int e2)
{
    int size1=e1-s1+1;
    int size2=e2-s2+1;
    int t=s1;
    int temp[size1+size2];
    int i=0;
    for(i=0;s1<=e1&&s2<=e2;i++)
    {
        if(arr[s1]<arr[s2])
        {
            temp[i]=arr[s1];
            s1++;
        }
        else{
             temp[i]=arr[s2];
            s2++;
        }

    }
    while(s1<=e1)
    {
        temp[i]=arr[s1];
        s1++;
        i++;
    }
    while(s2<=e2)
    {
        temp[i++]=arr[s2++];
    }
   int j=0;
    for(int i=t;i<=e2;i++)
    {
        arr[i]=temp[j++];
        //printf("\n%d=%d",i,arr[i]);
    }
}
void merge(int *arr,int s,int e)
{
    if(s==e||s>e)
    {
        return;
    }
    else
    {
        int mid=(s+e)/2;
        merge(arr,s,mid);
        merge(arr,mid+1,e);
        merging(arr,s,mid,mid+1,e);
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
    merge(arr,0,n-1);
    printf("The elements are=");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}
