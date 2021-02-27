#include <iostream>
#include <algorithm>
using namespace std;

int P, N, H;
vector<int> customer[110];

int main(void)
{
	cin >> P >> N >> H;
	
	for(int i = 1; i <= N; i ++)
	{
		int num, hour;
		cin >> num >> hour;
		
		customer[num].push_back(hour);
	}
	
	for(int i = 1; i <= P; i++)
	{
		sort(customer[i].begin(), customer[i].end());
	}
	
	for(int i = 1; i <= P; i++)
	{
		
	}
	
	
	return 0;
}
