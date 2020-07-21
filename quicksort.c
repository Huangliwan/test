#include<stdio.h>

void Quicksort(int *arr,int left,int right)
{
    int i,j,temp,k;
    if(left>right)
        return;
    temp = arr[left];
    i = left;
    j = right;
    while(i!=j)
	{
        while(arr[j]>=temp && i<j)
		{
            j--;
        }
        while(arr[i]<=temp && i<j)
		{
            i++;
        }
        if(i!=j)
		{
            k = arr[i];
            arr[i] = arr[j];
            arr[j] = k;
        }
    }
    arr[left] = arr[i];
    arr[i] = temp;
    Quicksort(arr,left,i-1);
    Quicksort(arr,i+1,right);  
}

int main()
{
    printf("--快速排序--\n");
    int i,n,arr[100];
    printf("一共有多少个数：");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    	scanf("%d",&arr[i]);
    printf("排序后:\n");
    Quicksort(arr,0,n);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
