// https://codeforces.com/problemset/problem/96/A

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
	string s;
	cin >> s;

	int a = 0, b = 0;
	// 000000100
	for(int i=0; i<s.length(); i++){
		if(s[i] == '0'){
			a++;
			b = 0;
			if(a >= 7){
				cout << "YES";
				return 0;
			}
		}else{
			b++;
			a = 0;
			if(b >= 7){
				//cout << "b" << i << endl; 
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";

	return 0;
}