// https://codeforces.com/problemset/problem/282/A
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
	int n;
	cin >> n;

	int x = 0;

	while(n--){
		string s;
		cin >> s;
		for(int i=0; i<s.length(); i++){
			if(s[i] == '+'){
				x++;
				break;
			}else if(s[i] == '-'){
				x--;
				break;
			}
		}
	}

	cout << x;

	return 0;
}