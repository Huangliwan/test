#include<bits/stdc++.h>

using namespace std;
 
const int N=2e5+1;
 
inline int read(){
	char ch=getchar();
	int f=1; 
		while(!isdigit(ch)) {
			if(ch=='-')f=-f; 
			ch=getchar();
			}
    		int x=0;
			while(isdigit(ch)) 
			x=(x<<3)+(x<<1)+ch-'0',ch=getchar(); 
			return x*f;
			}
 
struct tree{
    int start,end; //端点
    int len; 
	int xuhao; //边权，原来的序号
};
	tree a[N];
	int n,m,s=0,p=0;
	bool h[N]; //哈希
	int ans[N]; //记录答案
	 
inline bool cmp(tree x,tree y){
    return x.len<y.len;
} //结构体排序方式

int main(){
    n=read(),m=read();
    for(int i=1;i<=m;i++) {
        a[i].start=read(); 
		a[i].end=read();
        a[i].len=read(); 
		a[i].xuhao=i;
    }
    sort(a+1,a+1+m,cmp); //存边排序
    /*s=a[1].len;*/ h[a[1].start]=h[a[1].end]=1;
    printf("%d\n",n-1); 
	ans[++ans[0]]=a[1].xuhao; //取出第一条边
    for(int p=2;p<n;p++) //做 n-2 次
    	for(int i=2;i<=m;i++)
        	if(h[a[i].start]+h[a[i].end]==1) {
				ans[++ans[0]]=a[i].xuhao; //记录答案
            	h[a[i].start]=h[a[i].end]=1;
            	break;  //找到最小的，结束
        } 
		sort(ans+1,ans+1+ans[0]); //排序，输出答案
    	for(int i=1;i<=ans[0];i++) 
			printf("%d\n",ans[i]); 
    		return 0;
}
