#include<bits/stdc++.h>

using namespace std;

void hanoi(int, char, char, char);

int main(void)
{
	int n;
	char x, y, z;

	cout << "Start : ";
	cin >> x;
	cout << "End : ";
	cin >> z;
	cout << "Rest : ";
	cin >> y;	
	cout << "Quantity : ";
	cin >> n;
	
	hanoi(n, x, y, z);

	return 0;
}

void hanoi(int n, char A, char B, char C) 		
{
    if (n == 1)
    {
        printf("%c(%d)->%c\n", A, n, C);
    }
    else
    {
        hanoi(n - 1, A, C, B);
        printf("%c(%d)->%c\n", A, n, C);
        hanoi(n - 1, B, A, C);
    }
}
