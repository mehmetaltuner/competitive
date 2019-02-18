#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 10000007
#define min3(a, b, c) min(a, min(b, c))

using namespace std;

int main(int argc, char const *argv[])
{
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;

	vector <int> v1(n1);
	vector <int> v2(n2);
	vector <int> v3(n3);

	for(int i=0; i<n1; i++) cin >> v1[i];
	for(int i=0; i<n2; i++) cin >> v2[i];
	for(int i=0; i<n3; i++) cin >> v3[i];

	reverse(ALL(v1));
	reverse(ALL(v2));
	reverse(ALL(v3));

	vector <int> pre1(N, 0);
	vector <int> pre1v(n1);
	vector <int> pre2(N, 0);
	vector <int> pre3(N, 0);

	int sum=0;
	for(int i=0; i<n1; i++){
		sum += v1[i];
		pre1[sum]++;
		pre1v[i] = sum;
	}

	sum=0;
	for(int i=0; i<n2; i++){
		sum += v2[i];
		pre2[sum]++;
	}

	sum=0;
	for(int i=0; i<n3; i++){
		sum += v3[i];
		pre3[sum]++;
	}

	int res = 0;

	for(int i=0; i<n1; i++){
		if(pre2[pre1v[i]] && pre3[pre1v[i]])
			res = pre1v[i];
	}

	cout << res;

	return 0;
}