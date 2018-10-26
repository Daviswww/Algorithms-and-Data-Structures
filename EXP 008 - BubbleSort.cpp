#include<bits/stdc++.h>
#define swap(x, y) {int tmp; tmp = x, x = y, y = tmp;}
using namespace std;

int main()
{
	int ary[1000], n;
	cin >> n;
	srand (time(NULL));
	
	for(int i = 0; i < n; i++)
	{
		int k = rand() % 100 + 1;
		ary[i] = k;
	}
	printf("Before: ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", ary[i]);
	}
	puts("");
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			if(ary[i] > ary[j])
			{
				swap(ary[i], ary[j]);
			}
		}
	}
	printf("After: ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", ary[i]);
	}
	return 0;
}
