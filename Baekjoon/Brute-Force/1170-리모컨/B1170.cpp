#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
int num[10];

// �ڸ��� ��� 
int cal(int val)
{
	int digit = 1;
	
	while(val / 10 != 0)
	{
		val /= 10;
		digit++;
	}
	
	return digit;
}

// ��� ������ ��ȣ Ȯ�� 
int check(int val)
{
	while(val / 10 != 0)
	{
		if(num[val % 10] == 1)
		{
			return 0;
		}	
		
		val /= 10;
	}
	
	if(num[val % 10] == 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main(void)
{
//	freopen("B1107_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= M; i++)
	{
		int input;
		cin >> input;
		
		num[input] = 1;
	}
	
	int Min = abs(N-100);
	for(int i = 0; i <= 1000000; i++)
	{
		if(check(i) == 0)
		{
			continue;
		}
		
		int cnt = cal(i); // ���� ��ư Ƚ�� 
		cnt += abs(N-i);  // + - ��ư Ƚ�� 
		
		Min = min(Min, cnt);
	}
	
	cout << Min;
		
	return 0;
}
