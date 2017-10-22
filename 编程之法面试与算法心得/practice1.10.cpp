/*
10、最小子串

给一篇文章，里面是由一个个单词组成，单词中间空格隔开，再给一个字符串指针数组，比如 char *str[]={"hello","world","good"};

求文章中包含这个字符串指针数组的最小子串。注意，只要包含即可，没有顺序要求。

提示：文章也可以理解为一个大的字符串数组，单词之前只有空格，没有标点符号。
*/

#include <stdio.h>  
#include <stdlib.h>  
  
typedef int Type; /* 字符型数据*/  
  
typedef struct LNode {  
    Type data;  
    struct LNode *next;  
} LNode;  
  
LNode* CreateListNode(int value) {  
    LNode* pNode = (LNode *) malloc(sizeof(LNode));  
    pNode->data = value;  
    pNode->next = NULL;  
  
    return pNode;  
}  
  
void ConnectListNodes(LNode* pCurrent, LNode* pNext) {  
    if (!pCurrent) {  
        printf("Error to connect two nodes.\n");  
        exit(1);  
    }  
  
    pCurrent->next = pNext;  
}  
  
LNode* getLastNode(LNode* pHead) {  
    LNode *p = pHead;  
    while (p && p->next) {  
        p = p->next;  
    }  
    return p;  
}  
  
void DestroyNode(LNode* pNode) {  
    free(pNode);  
}  
  
unsigned int GetListLength(LNode* pHead) {  
    unsigned int nLength = 0;  
    LNode* pNode = pHead;  
    while (pNode != NULL) {  
        ++nLength;  
        pNode = pNode->next;  
    }  
  
    return nLength;  
}  
void insertToRear(LNode** head, Type elem) {  
    if (!*head) {  
        *head = CreateListNode(elem);  
    } else {  
        ConnectListNodes(getLastNode(*head), CreateListNode(elem));  
    }  
}  
  
void traverse(LNode* head) {  
    LNode* node = head;  
    while (node) {  
        printf("%3d", node->data);  
        node = node->next;  
    }  
}  
  
/* 
 *截取字符串 
 */  
char* subString(char *src, int pos, int len) {  
    char *p = src;  
    char *substr = (char*) calloc(sizeof(char), len + 1);  
    int i = 0;  
    p += pos;  
    while (len--) {  
        substr[i++] = *(p++);  
    }  
    substr[i] = '\0';  
    return substr;  
}  
  
int getHash(char *p) {  
    int hash = 0;  
    int length = strlen(p);  
    int i = 0;  
    for (; i < length; i++) {  
        hash |= (1 << (p[i] - 'A'));  
    }  
    return hash;  
}  
  
int getHashByRange(char* str, int start, int length) {  
    int hash = 0;  
    int i = 0;  
    for (; i < length; i++) {  
        hash |= (1 << (*(str + i + start) - 'A'));  
    }  
    return hash;  
}  
  
void getIndexs(char *content, char* search[], int searchSize, LNode* indexArr[]) {  
    int i = 0;  
    int rear = 0, front = 0;  
  
    int contentSize = strlen(content);  
    int myLen = strlen(search[i++]);  
    int maxLen = myLen, minLen = myLen;  
  
    while (i < searchSize) {  
        myLen = strlen(search[i++]);  
        minLen = minLen > myLen ? myLen : minLen;  
        maxLen = maxLen < myLen ? myLen : maxLen;  
    }  
  
    while (rear <= contentSize) {  
        if (*(content + rear) == ' ' || *(content + rear) == '\0') {  
            int difLen = rear - front;  
            //单词长度在区间内  
            if (difLen <= maxLen && difLen >= minLen) {  
                for (i = 0; i < searchSize; i++) {  
                    if (!strcmp(search[i], subString(content, front, difLen))) {  
                        insertToRear(&indexArr[i], front);  
                    }  
                }  
            }  
            rear += 1;  
            front = rear;  
        } else {  
            rear++;  
        }  
        /*for (i = 0; i < searchSize; i++) { 
 
         printf("%3d", strcmp(search[i], "hello")); 
         puts(search[i]); 
         }*/  
    }  
  
}  
  
int sumIndexCount(LNode* indexArr[], int rows) {  
    int i = 0, sum = 0;  
    for (; i < rows; i++) {  
        sum += GetListLength(indexArr[i]);  
    }  
    return sum;  
}  
  
int findMax(int a, int b, int c) {  
    int max;  
    if (a > b) {  
        max = a;  
    } else {  
        max = b;  
    }  
    if (max < c) {  
        max = c;  
    }  
    return max;  
}  
  
int findMin(int a, int b, int c) {  
    int min;  
    if (a > b) {  
        min = b;  
    } else {  
        min = a;  
    }  
    if (min > c) {  
        min = c;  
    }  
    return min;  
}  
  
//找出最大公差  
int findMaxDiff(int a, int b, int c, int* max, int* min) {  
    *max = findMax(a, b, c);  
    *min = findMin(a, b, c);  
    return *max - *min;  
}  
  
//LNode转数组  
int* getData(LNode *node) {  
    int len = GetListLength(node);  
    int *arr = calloc(sizeof(int), len);  
    int i = 0;  
    while (i < len) {  
        arr[i] = node->data;  
        node = node->next;  
        i++;  
    }  
  
    return arr;  
}  
  
void printfStrByArrage(char* content, int begin, int end) {  
    char* p = content + end;  
    int rear = end;  
    while (*(p++) != ' ') {  
        rear++;  
    }  
    puts(subString(content, begin, rear - begin));  
}  
  
void findMinStr(LNode* n[], int rows, int* mx, int* mn) {  
    int max = 0, min = 2100000000;  
    int* p1 = getData(n[0]);  
    int* p2 = getData(n[1]);  
    int* p3 = getData(n[2]);  
  
    int len1 = GetListLength(n[0]);  
    int len2 = GetListLength(n[1]);  
    int len3 = GetListLength(n[2]);  
    int result = findMaxDiff(p1[0], p2[0], p3[0], &max, &min);  
    int i, j, k;  
    for (i = 0; i < len1; i++) {  
        for (j = 0; j < len2; j++) {  
            for (k = 0; k < len3; k++) {  
                int pmax, pmin;  
                if (result > findMaxDiff(p1[i], p2[j], p3[k], &pmax, &pmin)) {  
                    max = pmax;  
                    min = pmin;  
                }  
            }  
        }  
    }  
    *mx = max;  
    *mn = min;  
}  
  
int main(void) {  
//文章内容  
    char* content =  
            "hello good kitty world my world is a hello good a world hello space";  
    char *str[] = { "hello", "world", "good" };  
  
    int rows = sizeof(str) / sizeof(char*);  
  
    LNode* indexArr[rows];  
    int i = 0;  
    for (; i < rows; i++) {  
        indexArr[i] = NULL;  
    }  
  
    getIndexs(content, str, rows, indexArr);  
  
    int max = 0, min = 2100000000;  
    findMinStr(indexArr, rows, &max, &min);  
    printf("max:%3d,min:%3d\n", max, min);  
    printfStrByArrage(content, min, max);  
  
    return EXIT_SUCCESS;  
}  
