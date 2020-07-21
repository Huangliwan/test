#include <iostream>
#include <string>
using namespace std;

void fun1(string & list,int n , int index)
{
    if (index >= n)
    {
        cout << list << endl;
    }
    else
    {
        for (int i = index; i < n; i++)
        {
            swap(list[i] , list[index]);
            fun1(list , n , index + 1);
            swap(list[i] , list[index]);
        }
    }
}


void fun2(string & list , int n)
{
    if (n == 1)
    {
        cout << list << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            fun2(list , n - 1);
            if (n % 2 == 1)
            {
                swap(list[0] , list[n - 1]);
            }
            else
            {
                swap(list[i - 1] , list[n - 1]);
            }
        }
    }
}


void fun3(string & str)
{   
    int left = 0;
    int right = 0;
    for (int i = str.length() - 1; i > 0; i--)
    {
        if(str[i - 1] < str[i]) 
        {
            left = i - 1;
            break;
        }
        if(i == 1)   
            return;
    }
    for (int i = str.length() - 1; i > left; i--)
    {
        if(str[i] > str[left])
        {
            swap(str[left] , str[i]);
            break;
        }
    }

    left++;
    right = str.length() - 1;

    while(left < right)
    {
        swap(str[left++] , str[right--]);
    }

}

int factorial(int n)
{
    return n == 1 ? n : n * factorial(n - 1);
}



int main()
{
    //string list("123456");
    //fun1(list.length() , 0);
    //fun2(list.length());


    string str("123");
    cout << str << endl;    
    for (int i = 1; i < factorial(str.length()); i++)
    {
        fun3(str); //按照字典序生成下一个排列
        cout << str << endl;
    }

    return 0;
}

