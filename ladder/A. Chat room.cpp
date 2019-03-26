//https://codeforces.com/problemset/problem/58/A
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
	ios::sync_with_stdio(0);
	string s;
	cin >> s;

	int so_far = 0;
	
	for(int i=0; i<s.length(); i++){
		if(s[i] == 'h'){
			if(so_far == 0)
				so_far = 1;
		}else if(s[i] == 'e'){
			if(so_far == 1)
				so_far = 2;
		}else if(s[i] == 'l'){
			if(so_far == 2){
				so_far = 3;
			}else if(so_far == 3){
				so_far = 4;
			}
		}else if(s[i] == 'o'){
			if(so_far == 4){
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";
	return 0;
}