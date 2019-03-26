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
	bool started = false;
	bool last = false;
	cin >> s;

	s.append("WUB");

	string res;

	for(int i=0; i<s.length()-3;){
		if(s[i] == 'W'){
			if(s[i+1] == 'U' and s[i+2] == 'B'){
				if(started and !last)
					cout << ' ';
				i += 3;
				last = true;
			}else{
				cout << s[i];
				started = true;
				i++;
				last = false;
			}
		}else{
			cout << s[i];
			started = true;
			last = false;
			i++;
		}
	}

	cout << res << endl;

	return 0;
}