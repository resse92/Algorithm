#include <stdio.h>

int main(int argc, char *argv[]) {
	
}

/* 字符串旋转 */

//1. b蛮力移位 时间复杂O(mn) 空间O(1)
void LeftShiftOne(char *s, int n) {
	// 保存第一个字符
	char t = s[0];
	for (int i = 0; i < n; i++) {
		s[i - 1] = s[i];
	}
	s[n - 1] = t;
}

void LeftRotateString1(char *s, int n, int m) {
	while (m--) {
		LeftShiftOne(s, n);
	}
}

//2. 三步反转 时间复杂
void ReverseString(char *s, int from, int to) {
	while (from < to) {
		char t = s[from];
		s[from ++] = s[to];
		s[to--] = t;
	}
}

void LeftRotateString2(char *s, int n, int m) {
	m %= n;
	ReverseString(s, 0, m - 1);
	ReverseString(s, m, n - 1);
	ReverseString(s, 0, n - 1);
}

/* 字符串包含 */
//1. 蛮力轮询
bool StringContain1(string &a, string &b) {
	for (int i = 0; i < b.length(); ++i) {
		int j;
		for (j = 0; (j < a.length()) && a[j] != b[i]; ++j) {
			if (j >= a.length()) {
				return false;
			}
		}
	}
	return true;
}

//2. 排序后轮询
bool StringContain2(string &a, string &b) {
	Sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	for (int pa = 0, pb = 0; pb < b.length; ) {
		while ((pa < a.length()) & (a[pa] > b[pb])) {
			++pa;
		}
		if ((pa >= a.length()) || a[pa] > b[pb]) {
			return false;
		}
	}
	return true;
}

//3. 素数相乘  如果字符串很长,造成数字很大,容易溢出,不可行
bool StringContain3(string &a, string &b) {
	const int p[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31
	37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
	
	int f = 1;
	for (int i = 0; i < a.length(); ++i) {
		int x = p[a[i] - 'A'];
		if (f % x) {
			f *= x;
		}
	}
	
	for (int i = 0; i < b.length(); ++i) {
		int x = p[b[i] - 'A'];
		if (f % x) {
			return false;
		}
	}
	return true;
}

//4. 位运算法, 这个只能判断包含了字符,不能说明顺序是一样的
bool StringContain4(string &a, string &b) {
	int hash = 0;
	for (int i = 0; i < a.length(); ++i) {
		hash |= (1 << (a[i] - 'A'));
	}
	for (int i = 0; i < b.length(); ++i) {
		if ((hash & (1 << b[i] - 'A'))) == 0) {
			return false;
		}
	}
	return true;
}

//思考题 变位词, bad和adb是兄弟字符串,如何在字典中迅速找到他的兄弟字符串


// 字符串的全排列

//1. 递归实现
void CalcAllPermutation(char *perm, int from, int to) {
	if (to <= 1) {
		return;
	}
	
	if (from == to) {
		for (int i = 0;i <= to;i++) {
			count << perm[i];
		}
		count << endl;
	} else {
		for (int j == from; j <= to, j ++) {
			swap(perm[j], perm[to]); // STL库函数, void swap(int &a, int &b)
			CalcAllPermutation(perm, from + 1, to);
			swap(perm[j], perm[from]);
		}
	}
}

//2. 字典序排列

bool CalcAllPermutation2(char *perm, int num) {
	int i;
	// 步骤1: 找到排列中最后一个升序位置i, x = ai
	for (i = num - 2; (i >= 0) && (perm[i] >= perm[i + 1]); --i) {
		;
	}
	// 已经找到所有排列
	if (i > 0) {
		return false;
	}
	
	int k;
	// 步骤2: 找到排列中第i位右边最后一个比ai打的位置j, y = aj
	for (k = num - 1;(k > i) && (perm[k] <= perm[i]); --k) {
		;
	}
	// 步骤3: 交换xy
	swap(perm[i], perm[k]);
	// 步骤4: 把第i + 1位到最后的部分反转
	reverse(perm + i + 1, perm + num);
	return true;
}

// 字符串转成整数

// 需要注意是否为空, 第一个字符是否为正负, 字符串是否有不为数字的字符, 字符串是否太长,是否会溢出
int StrToInt(const char *str) {
	static const int MAX_INT = (int)((unsigned)~0 >> 1);
	static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;
	
	//判断是否为空
	if (str == 0) {
		return 0;
	}
	
	//处理空格
	while (isspace(*str)) {
		++str;
	}
	
	//处理正负
	int sign = 1;
	if (*str == '+' || *str == '-') {
		if (*str == '-') {
			sign = -1;
		}
		++str;
	}
	
	// 确定是数字后才执行
	while (isdigit(*str)) {
		//处理溢出
		int c = *str - '0';
		
		if (sign > 0 && (n > MAX_INT / 10 || (n == MAX_INT / 10 && c > MAX_INT % 10))) {
			n = MAX_INT;
			break;
		} else if (sign < 0 && (n > (unsigned)MIN_INT / 10 || (n == (unsigned)MIN_INT / 10 && c > (unsigned)MIN_INT % 10))) {
			n = MIN_INT;
			break;
		}
		
		//把之前得到的数字乘以10, 再加上当前字符表示的数
		n = n * 10 + c;
		++str;
	}
	return sign > 0 ? n : -n;
}

// 回文判断
//1. 两头往中间扫
bool IsPalindrome1(const char *s, int n) {
	//非法输入
	if (s == NULL || n < 1) {
		return false;
	}
	
	const char *front, *back;
	
	// 初始化头指针和尾指针
	front = s;
	back = s + n - 1;
	
	while (front < back) {
		if (*front != *back) {
			return false;
		}
		++front;
		--back;
	}
	return true;
}


//2. 从中间往两头扫
bool IsPalindrome2(const char *s, int n) {
	if (s == NULL || n < 1) {
		return false;
	}
	
	const char *first, *second;
	
	// m定位到字符串的中间位置
	int m = ((n >> 1) - 1) >= 0 ? (n >> 1) - 1 : 0;
	first = s + m;
	second = s + n - 1 - m;
	
	while (first >= s) {
		if (*first != *second) {
			return false;
		}
		--first;
		++second;
	}
	return true;
}

// 最长回文子串
//1. 中心扩展法
int LongestPalidrome1(const char *s, int n) {
	int i, j ,max, c;
	
	if (s == 0 || n < 1) {
		return 0;
	}
	max = 0;
	
	// i为回文中心位置
	for (i = 0; i < n; ++i) {
		// 回文长度为奇数
		for (j = 0; (i - j >= 0) && (i + j < n); ++j) {
			if (s[i - j] != s[i + j]) {
				break;
			}
			c = j * 2 + 1;
		}
		
		if (c > max) {
			max = c;
		} 		
		// 回文长度为偶数
		for (j = 0; (i - j >= 0) && (i + j + 1 < n); ++j) {
			if (s[i - j] != s[i + j + 1]) {
				break;
			}
			c = j * 2 + 2;
		}
		if (c > max) {
			max = c;
		}
	}
	return max;
}

// 2. Manacher算法, 通过每个字符的两边都插入一个特殊符号,将所有可能的奇数或偶数长度都变成奇数
// 为了处理越界问题,可以在首位加上一个特殊字符(如$)

void Manachere() {
	int i;
	int mx = 0; // mx = id + p[id], 最大回文子串的边界
	int id; // 最大回文子串的中心位置
	for (i = 1; i < n; i++) {
		// mx > 1时,P[i] >= Min(P[2 * id - i], mx -i)
		if (mx > i) {
			p[i] = MIN(p[2 * id - i], mx - i);
		} else {
			// mx < 1时, 无法对p[i]做更多的假设,直接让p[i] = 1;
			p[i] = 1;
		}
		
		while (s[i] + p[i] == s[i - p[i]]) {
			p[i]++;
		}
		if (p[i] + i > max) {
			mx = p[i] + i;
			id = i;
		}
	}
}
