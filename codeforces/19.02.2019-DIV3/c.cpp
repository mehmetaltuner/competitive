#include <bits/stdc++.h>
#define ALL(e) (e.begin(), e.end())
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 1000000009

typedef long long int lli;

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	queue <pair <int, int>> q;
	map <int, int> m;

	for(int i=0; i<n*n; i++){
		int x;
		cin >> x;
		if(m.find(x) == m.end())
			m[x] = 1;
		else
			m[x]++;

		if(n == 1){
			cout << "YES" << endl;
			cout << x;
			return 0;
		}
	}

	for(auto it=m.begin(); it!=m.end(); it++){
		q.push({it->first, it->second});
	}

	if(n == 2){
		int first=0;
		int val1, val2;
		for(auto it=m.begin(); it!=m.end(); it++){
			if(!first){
				first = it->second;
				val1 = it->first;
				val2 = it->first;
			}
			else{
				if(first != it->second){
					cout << "NO";
					return 0;
				}
				val2 = it->first;
			}
		}

		cout << "YES" << endl;
		cout << val1 << " " << val2 << endl;
		cout << val2 << " " << val1 << endl;
		return 0;
	}

	vector <vector <int>> matrix(n, vector <int>(n));
	bool ok = true;

	for(int i=0; i<n/2; i++){
		for(int j=0; j<n/2; j++){
			
			int val = q.front().first, am = q.front().second;
			q.pop();
			
			if(am < 4){
				continue;
			}

			am -= 4;

			matrix[i][j] = val;
			matrix[i][n-j-1] = val;

			matrix[n-i-1][j] = val;

			matrix[n-i-1][n-j-1] = val;

			if(am > 0){
				q.push({val, am});
			}
		}
		
	}

	if(n % 2 == 0){
		while(!q.empty()){
			ok = false;	
			q.pop();
		}
		
	}else{
		if(q.empty()){
			ok = false;
		}else{
			int counter = 0;
			while(!q.empty()){
				int val = q.front().first, am = q.front().second;
				q.pop();
				
				if(am % 4 == 0){
					matrix[counter][n/2] = val;
					matrix[n-1-counter][n/2] = val;

					matrix[n/2][counter] = val;
					matrix[n/2][n-1-counter] = val;

					counter++;
					am -= 4;
					if(am > 0)
						q.push({val, am});
				}else if(am % 4 == 1){
					matrix[n/2][n/2] = val;
					am--;
					if(am > 0)
						q.push({val, am});
				}else{
					ok = false;
					break;
				}
			}
		}
	}

	if(ok){
		cout << "YES" << endl;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout << matrix[i][j] << " ";
			}cout << endl;
		}
	}else{
		cout << "NO";
	}

	return 0;
}