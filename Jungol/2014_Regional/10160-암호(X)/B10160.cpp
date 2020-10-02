#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

long long N, K;

long long cal_all()
{
	long long val = 1;
	
	for(int i = 1; i <= N; i++)
	{
		val *= K;
		val %= 1000000009;
	}
	
	return val;
}

long long cal_no()
{
	long long val = 1;
	for(int i = 1; i <= N-5; i++)
	{
		val *= K;
		val %= 1000000009;
	}
	
	long long same = 0;
	for(int i = 1; i <= N-10+1; i++)
	{
		same += i;
//		same %= 1000000009;
	}
	
//	cout << val << "  1  " << same << endl;
	
	if(same >= 1)
	{
		val -= same;	
//		if(val < 0)
//		{
//			val += 1000000009;
//		}
	}

	long long cnt = N-5+1;
	
//	cout << val << "  2  " << same << endl;
	
	return val * cnt % 1000000009;
}

int main(void)
{
//	freopen("B10159_input.txt", "r", stdin);

	cin >> N >> K;
	
	long long all = cal_all();
	long long no = cal_no() * 2;
	
	cout << no << endl;
	
	if(all - no < 0)
	{
		cout << all - no + 1000000009;
	}
	else
	{
		cout << all - no;
	}
	
	return 0;
}
