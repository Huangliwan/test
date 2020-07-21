#include <stdio.h>//自定义的输出函数
#include <stdlib.h>//因为会使用到rand()函数


//输出的函数 
void Prt(int a[], int n ,int i){
    	printf("%d:",i);
        for(int j=0; j<n; j++){
            printf("%d",a[j]);
        }
        printf("\n");
}
    
//直接插入排序函数
void InsertSort(int a[],int n)
{
	int i;
    for(i= 1; i<=n;i++){
    	 a[i]=rand()%10;
        if(a[i] < a[i-1]){//若第 i 个元素大于 i-1 元素则直接插入；反之，需要找到适当的插入位置后在插入。
            int j= i-1;
            int x = a[i];
            while(j>-1 && x < a[j]){  //采用顺序查找方式找到插入的位置，在查找的同时，将数组中的元素进行后移操作，给插入元素腾出空间
                a[j+1] = a[j];
                j--;
                }
                a[j+1] = x;      //插入到正确位置
            }
            Prt(a,n,i);//打印每次排序后的结果
        }
    }

int main(){
	int i,n;
	int a[]={0};
	printf("这些数n有:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
        InsertSort(a,n);
        return 0;
    }
