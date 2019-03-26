// https://codeforces.com/problemset/problem/208/A

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

	s.append("WUB");

	string res;

	for(int i=0; i<s.length()-3;){
		if(st[i] == 'W'){
			if(st[i+1] == 'U' and st[i+2] == 'B'){
				res.append(&' ');
				i += 3;
			}else{
				res.append(s[i]);
				i++;
			}
		}else{
			res.append(s[i]);
			i++;
		}
	}

	cout << res << endl;

	return 0;
}