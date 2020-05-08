#include <stdio.h>
#include "Structure.c"

// 95: Unique Binary Search Trees II

struct TreeNode **generateNode(int start, int current, int end)
{

	struct TreeNode **res;
	for (int i = start; i < current; i++)
	{
		struct TreeNode **leftRes = generateNode(start, i, current);
	}
	for (int i = current + 1; i <= end; i++)
	{
		struct TreeNode **rightRes = generateNode(current + 1, i, end);
	}
}

struct TreeNode **generateTrees(int n, int *returnSize)
{
	for (int i = 0; i <= n; i++)
	{
		struct TreeNode **y = generateNode(0, i, n);
	}
}

int main(int argc, char *argv[])
{
	struct TreeNode *node;
	node->val = 1;
	return 1;
}