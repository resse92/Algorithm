#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
    int m_Value;
    ListNode * p_Next;
}ListNode;

//无环
bool isCross(ListNode * p1, ListNode * p2)
{
    ListNode * x = p1;
    ListNode * y = p2;
    while(x->p_Next != NULL)
    {
        x = x->p_Next;
    }
    while(y->p_Next != NULL)
    {
        y = y->p_Next;
    }
    return (x == y);
}

//判断是否有环 若有返回环的交叉结点 没有返回NULL
ListNode * isCircle(ListNode * pHead)
{
    if(pHead == NULL)
        return NULL;

    ListNode * p[100];
    int n = 0;
    p[n] = pHead;
    n++;
    while(p[n - 1]->p_Next != NULL)
    {
        p[n] = p[n - 1]->p_Next;
        n++;
        for(int i = 0; i < n - 1; i++)
        {
            if(p[i] == p[n - 1])
            {
                return p[i];
            }
        }
        if(n >= 100)
        {
            printf("input is too large");
            return NULL;
        }
    }
    return NULL;
}

ListNode * isCrossWithCircle(ListNode * p1, ListNode *p2)
{
    ListNode * c1 = isCircle(p1);
    ListNode * c2 = isCircle(p2);
    if(c1 == NULL && c2 == NULL) //都没有环
    {
        c1 = p1;
        c2 = p2;
        while(c1 != NULL)
        {
            while(c2 != NULL)
            {
                if(c1 == c2)
                    return c1;
                c2 = c2->p_Next;
            }
            c1->p_Next;
        }
    }
    else if(c1 != NULL && c2 != NULL) //都有环
    {
        ListNode * h1 = p1;
        ListNode * h2 = p2;
        while(h1 != c1) //判断非环部分是否相交
        {
            while(h2 != c2)
            {
                if(h1 == h2)
                {
                    return h1;
                }
                h2 = h2->p_Next;
            }
            h1 = h1->p_Next;
        }
        h1 = c1;
        h2 = c2;
        do //判断非环部分是否相交 第一个公共点是 两个交叉点中的任意一个
        {
            if(h1 == h2)
            {
                return h1;
            }
            h1 = h1->p_Next;
        }while(h1 != c1);    
    }

    return NULL;
}
int main()
{
    ListNode n1 , n2, n3, n4, n5, n6, n7, n8, n9;
    n1.m_Value = 1; n1.p_Next = &n2;
    n2.m_Value = 2; n2.p_Next = &n3;
    n3.m_Value = 3; n3.p_Next = &n7;
    n4.m_Value = 4; n4.p_Next = &n5;
    n5.m_Value = 5; n5.p_Next = &n6;
    n6.m_Value = 6; n6.p_Next = &n8;
    n7.m_Value = 7; n7.p_Next = &n8;
    n8.m_Value = 8; n8.p_Next = &n9;
    n9.m_Value = 9; n9.p_Next = &n7;

    //bool flag = isCross(&n1, &n4);
    ListNode * a = isCrossWithCircle(&n1, &n4);
    return 0;
}