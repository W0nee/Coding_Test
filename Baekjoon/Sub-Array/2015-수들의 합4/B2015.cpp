#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int psum[200010];
int num[200010];
map<int, long long> check;
long long ans;

int main(void)
{
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
		
		psum[i] = psum[i-1] + num[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(psum[i] == K)
		{
			ans++;
		}
		
		int val = psum[i] - K;
		
		ans += check[val];
		
		check[psum[i]]++;
	}
	
	cout << ans << endl;
	
	return 0;
}
