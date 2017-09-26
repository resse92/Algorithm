//三种方式实现--从尾到头输出链表
/*
四种方式实现--从尾到头输出链表
　　方法一：借用栈倒序输出链表
  　　　　　 因为栈是先进后出，把链表中的元素存进栈中，链表前面的元素在栈底，后面的元素在栈顶，链表后面的元素先出栈
　　方法二：先翻转链表，再按顺序打印（主要是想自己实现单链表的翻转，这种实现方式破坏了链表的结构，当然再翻转一下就还原了）
                 翻转链表的步骤：
                      1:将当前节点的next节点指向他以前的前一个节点
                      2:当前节点下移一位
                      3:如果是最后一个节点，就把它的next节点指向它以前的前一个节点，并推出循环
　　方法三：用递归实现
                 很诚实的说盗用了别人的思想，真的太妙了，完全能看出你是否真的体会了递归的原理
                 正如那位哥们所说，递归就是一个进栈出栈的过程，链表前面的元素先进栈，在栈底，后面的元素后进栈，在栈顶，先出栈，哈哈。。。
　　方法四：借用数组实现，跟用栈实现的方式差不多， LoveJenny说的实现方式跟这种方式是一样的，空间复杂度都是O(n)
*/
#include <stack>
#include <string>
#include <iostream>
using namespace std;

class OutFromEnd
{
  public:
    typedef struct node1
    {
        int data;
        node1 *next;
        node1(int d) : data(d), next(NULL) {}
    } node;

    OutFromEnd()
    {
        head = cur = new node(-1);
    }

    void add(int data)
    {
        node *tmp = new node(data);
        cur->next = tmp;
        cur = tmp;
    }

    //借用栈倒序输出链表
    //因为栈是先进后出，把链表中的元素存进栈中，链表前面的元素在栈底，后面的元素在栈顶，链表后面的元素先出栈
    void stackMethod()
    {
        if (NULL == head || NULL == head->next)
        {
            return;
        }

        node *tmp = head->next;
        stack<int> s;

        while (tmp != NULL)
        {
            s.push(tmp->data);
            tmp = tmp->next;
        }

        while (!s.empty())
        {
            cout << s.top() << "\t";
            s.pop();
        }
    }

    void reverse()
    {
        if (NULL == head || NULL == head->next)
        {
            return;
        }
        cur = head->next;

        node *prev = NULL;
        node *pcur = head->next;
        node *next;
        while (pcur != NULL)
        {
            if (pcur->next == NULL)
            {
                pcur->next = prev;
                break;
            }
            next = pcur->next;
            pcur->next = prev;
            prev = pcur;
            pcur = next;
        }

        head->next = pcur;

        node *tmp = head->next;
        while (tmp != NULL)
        {
            cout << tmp->data << "\t";
            tmp = tmp->next;
        }
    }

    void print3()
    {
        recursion(head->next);
    }

    //用递归实现
    //很诚实的说盗用了别人的思想，真的太妙了，完全能看出你是否真的体会了递归的原理
    //正如那位哥们所说，递归就是一个进栈出栈的过程，链表前面的元素先进栈，在栈底，后面的元素后进栈，在栈顶，先出栈，哈哈。。。
    void recursion(node *head)
    {
        if (NULL == head)
        {
            return;
        }

        if (head->next != NULL)
        {
            recursion(head->next);
        }

        //如果把这句放在第二个if前面，那就是从头到尾输出链表，曾经的你或许是用while或者用for循环输出链表，现在你又多了一种方式
        cout << head->data << "\t";
    }

    //借用数组实现
    void print4()
    {
        node *tmp = head->next;
        int len = 0;
        while (tmp != NULL)
        {
            ++len;
            tmp = tmp->next;
        }
        tmp = head->next;
        int *A = new int[len];
        for (int i = len - 1; i >= 0; i--)
        {
            A[i] = tmp->data;
            tmp = tmp->next;
        }

        for (int i = 0; i < len; i++)
        {
            cout << A[i] << "\t";
        }
        delete[] A;
    }

  private:
    node *head, *cur;
};