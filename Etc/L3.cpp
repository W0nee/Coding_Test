#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int in[1010];
int out[1010];
int inRoom[1010];
vector<int> room;
int inIdx;
int meet[1010];

void meetCal()
{
	for(int i = 1; i <= N; i++)
	{
		if(inRoom[i] == 1)
		{
			meet[i] += (int)room.size()-1;
		}
	}
}

int main(void)
{
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> in[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		cin >> out[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		int cur_out = out[i];
		
		// 방에 있어야 나감 
		while(inRoom[cur_out] == 0)
		{
			room.push_back(in[++inIdx]);
			inRoom[in[inIdx]] = 1;
		}
		
		// 만난사람 계산
		meetCal();
		
		// 방에서 나가기 
		inRoom[cur_out] = 0;
		room.clear();
	}
	
	for(int i = 1; i <= N; i++)
	{
		cout << meet[i] << " ";
	} 
 	
	return 0;
}

