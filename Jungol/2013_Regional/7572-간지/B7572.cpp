#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N;
string num = "6789012345";
string alphabet = "IJKLABCDEFGH";
string ans;

int main(void)
{
//	freopen("B7572_input.txt", "r", stdin);

	cin >> N;
	
	ans += alphabet[N % 12];
	ans += num[N % 10];
	
	cout << ans;
	
	return 0;
}
