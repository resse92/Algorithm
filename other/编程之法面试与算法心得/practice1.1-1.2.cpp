// 1 找到第一个只出现一次的字符

char FirstNotRepeatingChar(char* pString)
{
      // invalid input
      if(!pString)
            return 0;

      // get a hash table, and initialize it 
      const int tableSize = 256;
      unsigned int hashTable[tableSize];
      for(unsigned int i = 0; i < tableSize; ++ i)
            hashTable[i] = 0;

      // get the how many times each char appears in the string
      char* pHashKey = pString;
      while(*(pHashKey) != '\0')
            hashTable[*(pHashKey++)] ++;

      // find the first char which appears only once in a string
      pHashKey = pString;
      while(*pHashKey != '\0')
      {
            if(hashTable[*pHashKey] == 1)
                  return *pHashKey;

            pHashKey++;
      }

      // if the string is empty 
      // or every char in the string appears at least twice
      return 0;
}

// 2 对称子字符串的最大长度

// Whether a string between pBegin and pEnd is symmetrical?
bool IsSymmetrical(char* pBegin, char* pEnd)
{
       if(pBegin == NULL || pEnd == NULL || pBegin > pEnd)
              return false;
 
       while(pBegin < pEnd)
       {
              if(*pBegin != *pEnd)
                     return false;
 
              pBegin++;
              pEnd --;
       }
       return true;
}
// 使用manacher算法O(n) http://blog.csdn.net/asdfghjkl1993/article/details/28605513。
int Manacher(int n)  
{  
    int mx=0;  
    int id;  
    p[0]=0;  
    for(int i=1;i<n;i++)  
    {  
        p[i]=1;  
        if(mx>i)  
        {  
            p[i]=min(p[2*id-i],mx-i);  
        }  
        while(str[i-p[i]]==str[i+p[i]]) p[i]++;  
        if(i+p[i]>mx)  
        {  
            id=i;  
            mx=i+p[i];  
        }  
    }  
    return mx;
}  