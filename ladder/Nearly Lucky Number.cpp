#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define mid (l + r) / 2
#define fi first
#define sc second
#define N 1000000009

using namespace std;

typedef long long int lli;

int main(){
	lli number;
	cin >> number;

	lli r = 0;

	while (number > 0)
	{
    	int digit = number%10;
    	if(digit == 4 or digit == 7)
    		r++;
    	number /= 10;
	}
	
	if(r == 4 or r == 7)
		cout << "YES";
	else cout << "NO";

	return 0;
}