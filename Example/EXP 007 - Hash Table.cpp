#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(void)
{
	ifstream fin;
	int n, sum;
	fin.open("1.txt");
	string str[30], str1[30], k;
	int pt[30] = {0};
	
	while(fin >> k)
	{
		int l;
		l = k[0] - 'A';	
		//由小放到大 
		if(pt[l] == 1)
		{
			str1[l] = k;
			pt[l]++;
			sum ++;
		}
			
		if(pt[l] == 0)
		{
			str[l] = k;
			pt[l]++;
		}
		if(pt[l] > 1) 
		{
			sum++;		//溢出 
			pt[l]++;	//總數 
		} 
	}
	int pe = 0, emb = 0, ems = 0, ov = 0;
	cout <<"1. show entire hash table"<< endl;
	for(int i = 0; i <= 25; i++)
	{
		cout <<"< "<< i+1 << " > : " <<str[i] <<" , " <<str1[i] << " "<<endl;
		if(pt[i] == 1) pe++;	//完美 
		if(pt[i] > 2) ov++;		//溢出 
		if(pt[i] == 0) emb++;	//空箱 
	}
	cout <<"2. number of overflows : " << ov << endl;
	cout <<"3. number of collisions (including overflows) : " << sum<< endl;
	cout <<"4. number of empty buckets : " << emb<< endl;
	cout <<"5. number of empty slots : "<< (emb * 2) + pe<< endl;
	cout <<"6. number of perfect hashing : "<< pe<< endl;
	return 0;
}
