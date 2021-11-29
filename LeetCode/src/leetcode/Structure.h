#include <stdio.h>
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *add(struct TreeNode *t1, int a)
{
	struct TreeNode *tmp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	tmp->val = t1->val + a;
	tmp->left = t1->left ? add(t1->left, a) : NULL;
	tmp->right = t1->right ? add(t1->right, a) : NULL;
	return tmp;
}

void generate(struct TreeNode ***tree, int n, int **rs)
{
	tree[n - 1] = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 10000);
	int index = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; (i == 1 && j == 0) || (i >= 2 && j < *rs[i - 2]); j++)
		{
			for (int k = 0; (i == n && k == 0) || (i < n && k < *rs[n - i - 1]); k++)
			{
				int nn = i == n ? j + k : j * (*rs[n - i - 1]) + k;
				tree[n - 1][index + nn] = (struct TreeNode *)malloc(sizeof(struct TreeNode));
				tree[n - 1][index + nn]->val = i;
				tree[n - 1][index + nn]->left = i == 1 ? NULL : tree[i - 2][j];
				tree[n - 1][index + nn]->right = i == n ? NULL : add(tree[n - i - 1][k], i);
			}
		}
		index += n == 1 ? 1 : (i == 1 || i == n) ? *rs[n - 2] : *rs[i - 2] * (*rs[n - i - 1]);
	}
	*rs[n - 1] = index;
}

struct TreeNode **generateTrees(int n, int *returnSize)
{
	*returnSize = 0;
	if (n == 0)
		return NULL;
	struct TreeNode ***trees = (struct TreeNode ***)malloc(sizeof(struct TreeNode **) * n);
	int **rs = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
		rs[i] = (int *)malloc(sizeof(int));
	for (int i = 1; i <= n; i++)
		generate(trees, i, rs);
	*returnSize = *rs[n - 1];
	return trees[n - 1];
}

int main(int argc, char *argv[])
{
}