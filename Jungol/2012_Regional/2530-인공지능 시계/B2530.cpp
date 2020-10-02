#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int N;
int A, B, C, D;

int main(void)
{
//	freopen("B2530_input.txt", "r", stdin);

	cin >> A >> B >> C >> D;
	
	int time = A*3600 + B*60 + C + D;
	
	C = time % 60;
	B = time / 60;
	A = time / 3600;
	
	cout << A % 24 << " " << B % 60 << " " << C;
	
	return 0;
}
