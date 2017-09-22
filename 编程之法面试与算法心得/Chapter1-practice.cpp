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