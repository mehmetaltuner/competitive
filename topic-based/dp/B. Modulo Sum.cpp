//https://codeforces.com/problemset/problem/445/A

#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define mid (l + r) / 2
#define fi first
#define sc second
#define N 1000000009
#define arr ar

using namespace std;

typedef long long int lli;

int main(){
	int n, m;
	ios::sync_with_stdio(0);
	cin >> n >> m;

	vector <int> ar(n+5);

	for(int i=0; i<n; i++){
		cin >> ar[i];
		ar[i] %= m;
	}

	if(n > m){
		cout << "YES";
		return 0;
	}

	vector <bool> knapsack(m, 0);
	vector <bool> temp(m, 0);

	knapsack[0] = true;
	bool flag =0;
	for(int i=0; i<n; i++){
		for(int j = m; j >= 0; j--)
		{
			if(knapsack[j])
			{
				temp[j] =1;
				temp[(j+arr[i])%m] = 1;
				if((j+arr[i])%m==0) 
				{
					cout<<"YES";
					return 0;
				}
			}
		}
		knapsack  = temp;
		temp = std::vector<bool> (m, 0);
	}
	cout<<"NO";

	return 0;
}