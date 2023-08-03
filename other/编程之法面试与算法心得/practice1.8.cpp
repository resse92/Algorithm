#include <iostream>
#include <deque>
using namespace std;

// KMP算法，pat长度由len_pat指定 
void get_next(const char pat[], int next[], int pat_len) {
  // int len = strlen(pat);
  int len = pat_len;
  int i,j; next[0] = -1;
  for(i=1; i<len; i++) {
    for(j=next[i-1]; j>=0 && pat[i-1]!=pat[j]; j=next[j])
      ;
    if(j<0 || pat[i-1]!=pat[j])
      next[i] = 0;
    else 
      next[i] = j+1; // if (pat[i]==pat[next[i]]) next[i]=next[next[i]];
  }
  for(int i=0; i<len; i++) {
    if(pat[i] == pat[next[i]])
      next[i] = next[next[i]];
  }
}

// KMP算法，str长度由'\0'判断，pat长度由len_pat指定 
int kmp_next(const char text[], const char pat[], int pat_len) {
  int t_length = strlen(text);
  // int p_length = strlen(pat);
  int p_length = pat_len;
  int t,p; int* next = new int[p_length];
  get_next(pat, next, p_length);
  for(t=0,p=0; t<t_length,p<p_length; ) {
    if(text[t] == pat[p]) 
      t++,p++;
    else
      if(next[p] == -1) // 说明此时p=0，而且pat[0]都匹配不了 
        t++;
      else 
        p = next[p];  
  }
  delete []next;
  return t<t_length ? (t-p_length):-1;  
}

// 切分pat的结构 
struct PAT_INFO {
  char* pat;
  int len;
};
// 可以匹配通配符的KMP，返回第一个匹配子串在str中的下标 
void KMP_WildCard(char* str, char* pat) {
  int len_str = strlen(str);
  int len_pat = strlen(pat);
  int i,j;
  deque<PAT_INFO> store;
  // 切分pat到store中 
  PAT_INFO info;
  bool new_info = true;
  for(i=0; i<len_pat; i++) {
    if(pat[i] == '*') {
      if(new_info == false) // 有info需要保存 
        store.push_back(info);
        new_info = true;
    }
    else {
      if(new_info) { // 需要新建一个info 
        info.pat = pat + i;
        info.len = 1;
        new_info = false;
      }
      else { // 不需要新建一个info 
        info.len++;
      }
    }
  } // for
  // 测试切分结果 
  /* 
  while(store.size() > 0) {
    info = store.front();
    for(i=0; i<info.len; i++)
      cout << info.pat[i];
    cout << endl;
    store.pop_front();
  }*/
  // 根据切分后的pat序列进行匹配
  int first_index = -1; // 起始的下标 
  int last_index = 0; // 最后的下标后面的一个位置 
  int next_index = 0; // 下一次开始匹配的下标 
  while(store.size()) {    
    info = store.front();    
    next_index = kmp_next(str+next_index, info.pat, info.len);
    if(next_index == -1) { // 这个片段没找到，查找任务失败 
      break;
    }    
    else { // 这个片段找到了，继续找
      if(first_index == -1) { // 找到的第一个片段 
        first_index = next_index;
      }
      last_index += next_index + info.len; 
      next_index = last_index;
    }
    store.pop_front();
//    cout << last_index << endl;
  }
  if(store.size())
    cout << "not found" << endl;
  else {
    for(i=first_index; i<last_index; i++)
      cout << str[i];
    cout << endl;
  }

}  

int main() {
  char * str = "Oh year.Totay is weekend!";
  char * pat =  "*ye*a*e*";
  cout << "str: " << str << endl;
  cout << "pat: " << pat << endl;
  cout << "res: ";
  KMP_WildCard(str, pat);
  system("PAUSE");
  return 0;
}