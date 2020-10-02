#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
int num[10];

// 자릿수 계산 
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

// 사용 가능한 번호 확인 
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
		
		int cnt = cal(i); // 숫자 버튼 횟수 
		cnt += abs(N-i);  // + - 버튼 횟수 
		
		Min = min(Min, cnt);
	}
	
	cout << Min;
		
	return 0;
}
