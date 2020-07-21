#include<stdio.h>
#include<malloc.h>
//定义二叉树结构
typedef struct Node
{
int data;
struct Node * LChild;
struct Node * RChild;
}BiTNode, *BiTree;
//定义栈结构，此处的栈用来储存二叉树节点
typedef struct{
    BiTree elem[30];
    int top;
}stack;
//操作栈的方法
void initStack(stack *s)
{
    s->top=-1;
}
void Push(stack *s,BiTree a)
{
    s->top++;
    s->elem[s->top]=a;
}
BiTree Pop(stack *s)
{
    s->top--;
    return s->elem[s->top+1];
}
//把数变成节点并入栈，便于后续操作
stack forest(int *arr,int length)//入栈跟数组顺序是反的
{
    stack s;
    initStack(&s);
    for(int i=0;i<=length-1;i++)
    {
        //写sizeof(*BiTNode))或者sizeof(BiTree)会卡死，猜想申请的内存不够，*BiTNode比BiTNode小
        //C语言这种访问底层内存的程序太不好把握了
        BiTree tree=(BiTree)malloc(sizeof(BiTNode));
        tree->data=arr[i];
        tree->LChild=tree->RChild=NULL;
        Push(&s,tree);
    }
    return s;
}
void sortStack(stack *s)//让栈中顶部元素小底部元素大
{
    BiTree temp;
    for(int i=0;i<=s->top-1;i++)
    {
        for(int j=0;j<=s->top-1;j++)
        {
            if(s->elem[j]->data<s->elem[j+1]->data)
            {
                temp=s->elem[j];
                s->elem[j]=s->elem[j+1];
                s->elem[j+1]=temp;
            }
        }
    }
}
BiTree buildTree(stack *s)
{
    while(s->top>0)//栈只有一个元素时结束
    {
        //栈顶两个出栈
        BiTree m1=Pop(s);
        BiTree m2=Pop(s);//不知道为什么不能加&了，难道是传进来的本身是指针的缘故？
        BiTree m=(BiTree)malloc(sizeof(BiTNode));
        m->data=m1->data+m2->data;
        m->LChild=m1;
        m->RChild=m2;
        //将新节点入栈
        Push(s,m);
        //让栈排序
        sortStack(s);
    }
    return s->elem[s->top];
}
//先序遍历，用于测试生成树的结果
void inOrder(BiTree tree)
{
    if(tree!=NULL)
    {
        printf("%d ",tree->data);
        inOrder(tree->LChild);
        inOrder(tree->RChild);
    }
}
//用来记录最后的和，不得已的全局变量，实在不知道如果传进去该怎么搞
int sum=0;
//先序遍历的一个变形
void caculation(BiTree tree,int step)
{
    if(tree!=NULL)
    {
        if(tree->RChild==NULL&&tree->LChild==NULL)//判断是否是叶子节点
        {
            sum+=tree->data*step;
            //printf("%d += %d * %d\n",sum,tree->data,step);
        }
        //每走一步带权路径应该加一
        caculation(tree->LChild,step+1);
        caculation(tree->RChild,step+1);
    }
}
int dealString(char *s,int *arr)
{
    int count=0;//统计字母个数
    int num[27]={0};//存放每个字母的个数，a对应0,多出来的一个放空格
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]==' ')//遇到空格也算一个
        {
            if(num[26]==0)
            {
                count++;
            }
            num[26]++;
            continue;//后面的不应该执行了
        }
        if(num[s[i]-97]==0)//如果这个字母从未出现过
        {
            count++;
        }
        //a的ASCII码是97
        num[s[i]-97]++;
    }
    for(int i=0,j=0;i<=26;i++)//把数组转移到arr里去
    {
        if(num[i]!=0)
        {
            arr[j]=num[i];
            j++;
        }
    }
    int temp;
    for(int i=0;i<=count-2;i++)//给arr冒泡排序，使其降序
    {
        for(int j=0;j<=count-2;j++)
        {
            if(arr[j]<arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return count;
}
int main()
{
    //请确保数组降序
    int arr[30];
    //测试用的字符串
    char str[]="shaonianyi cchyi";
    //length是有效数组长度，也就是除了0以外的
    int length=dealString(str,arr);
    //把数组变成森林存到栈里
    stack s=forest(arr,length);
    //构造哈夫曼树
    BiTree root=buildTree(&s);
    //计算带权路径，也就是哈夫曼编码的最短位数
    caculation(root,0);
    printf("WPL=%d",sum);
    inOrder(root);
}
