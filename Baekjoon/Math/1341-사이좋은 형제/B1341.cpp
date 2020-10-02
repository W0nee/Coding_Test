#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long a, b;
string result;
string answer;

void convert(long long num)
{
	while(num != 0)
	{
		long long temp = num % 2;
		num /= 2;
		
		result = to_string(temp) + result;	
	}
}

int main(void)
{
//	freopen("B1341_input.txt", "r", stdin);
	
	cin >> a >> b;
	
	bool check;
	long long tempB; 
	long long result_len;
	
	if(a == 0)
	{
		cout << "-";
		return 0;
	}
	else if(a == b)
	{
		cout << "*";
		return 0;
	}

	for(int i = 2; i <= 60; i++)
	{
		// 분모가 2의 제곱수-1 인지 확인 
		if(b == (long long)pow(2, i)-1)
		{
			check = true;
			result_len = i;
			break;
		}
		else if(((long long)pow(2, i)-1) % b == 0)
		{
			check = false;
			tempB = pow(2, i)-1;
			result_len = i;
			break;
		}
		
		if(i == 60)
		{
			cout << -1;
			return 0;
		}
	}
	
	if(check)
	{
		convert(a);
	}
	else
	{
		long long divide = tempB / b;
		a = a * divide;
		
		convert(a);
	}
	
//	cout << result << endl;
//	cout << tempB << endl;
//	cout << result_len << endl;
	
	int std = result.size();
	for(int i = 1; i <= result_len-std; i++)
	{
		result = "0" + result;
	}
	
	for(int i = 0; i < result.size(); i++)
	{
		if(result[i] == '1')	
		{
			answer += "*";
		}
		else
		{
			answer += "-";
		}
	}
	
	cout << answer;
	
	return 0;
}
