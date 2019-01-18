#include<bits/stdc++.h>

using namespace std;

const int maxn = 100;
int main()
{
	int stack[maxn] = {0};
	int *ptr = stack, tmp, count = 0;
	string op;
	printf("Enter op: ");
	while(cin >> op)
	{
		if(op == "pop")
		{
			if(count == 0)
			{
				printf("IsEmpty!\n");
				printf("Enter op: ");
				continue;	
			}
			else
			{
				count--;
				printf("Pop %d.\n", *(ptr+count));
			}
		}
		else if(op == "push")
		{
			printf("Enter num: ");
			cin >> tmp;
			*(ptr+count) = tmp;
			printf("Push %d in stack[%d].\n", tmp, count);
			count++;
		}
		else
		{
			printf("Default!");
		}
		printf("STACK:");
		for(int i= 0;i < count; i++)
		{
			printf(" %d", *(ptr+i));
		}
		puts("");
		printf("Enter op: ");
	}	
	return 0;
} 
