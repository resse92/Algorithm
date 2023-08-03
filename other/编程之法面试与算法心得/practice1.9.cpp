#include <stdio.h>

/* 
ASCII表上的数字0–31分配给了控制字符，用于控制像打印机等一些外围设备。 
数字32是空格字符 
数字 32–126 分配给了能在键盘上找到的字符，当您查看或打印文档时就会出现。数字127代表 DELETE 命令。 
*/

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