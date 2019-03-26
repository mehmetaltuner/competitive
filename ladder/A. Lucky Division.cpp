// https://codeforces.com/problemset/problem/122/A

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

bool lucky(int n){
	while(n > 0){
		int digit = n%10;
		if(digit != 4 and digit != 7)
			return false;
		n /= 10;
	}
	return true;
}

int main(){
	int n;
	cin >> n;

	for(int i=4; i<=n; i++){
		if(lucky(i)){
			if(n % i == 0){
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";

	return 0;
}