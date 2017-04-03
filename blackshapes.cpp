/// Problem link: https://www.interviewbit.com/problems/black-shapes/
/// Author: Suresh Iyengar

/*
The solution is to find the number of DFS traversals required to traverse the black shapes
*/

void dfs(vector<string> &arr, int i, int j, int n, int m)
{
	arr[i][j] = 'O';

	if (j > 0 && arr[i][j - 1] == 'X')
	{
		dfs(arr, i, j - 1, n, m);
	}

	if (j < (m - 1) && arr[i][j + 1] == 'X')
	{
		dfs(arr, i, j + 1, n, m);
	}

	if (i < (n - 1) && arr[i + 1][j] == 'X')
	{
		dfs(arr, i + 1, j, n, m);
	}

	if (i > 0 && arr[i - 1][j] == 'X')
	{
		dfs(arr, i - 1, j, n, m);
	}
}


int Solution::black(vector<string> &arr) {
  int res = 0;

	int n = arr.size();
	int m = arr[0].size();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'X')
			{
				dfs(arr, i, j, n, m);
				res += 1;
			}
		}
	}

	return res;
}
