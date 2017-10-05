#include <stdio.h>  
void main()  
{  
    char *str = "AaBbCcbCc*&^%$#@!";  
    char num[256] = {0};  
    int i = 0;  
    while(*str)  
    {  
        num[int(*str)]++;  
        str++;        
    }  
      
    for (i = 0;i<=255;i++)  
    {  
        if(num[i]!=0)  
            printf("出现字符%c的次数%d/n",i,num[i]);  
    }  
}  