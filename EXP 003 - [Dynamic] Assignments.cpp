#include<bits/stdc++.h>

using namespace std;
int jb[100][100], dp[100];
int main()
{
	int n, maxn = 0;
	while(cin >> n && n)
	{
		int x, y, z;
		for(int i = 0; i < 100; i++)
		{
			dp[i] = 0;
			for(int j = 0; j < 100; j++)
			{
				jb[i][j] = 0;
			}
		}		
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d %d", &x, &y, &z);
			maxn = max(maxn, y);
			jb[x][y] = z;
		}

		for(int i = 0; i <= maxn; i++)
		{
			for(int j = 0; j <= i; j++)
			{
				for(int k = 0 ; k <= i ; k++)
				{
					if(dp[i] < jb[j][k] + dp[j])
					{
						dp[i] = jb[j][k] + dp[j];
					}
				}
			}
		}
		printf("%d\n", dp[maxn]);
	}
	return 0;	
} 
