#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x << endl)
#define mid (l + r) / 2
#define fi first
#define sc second
#define N 1000000009

using namespace std;

typedef long long int lli;

int main(){
    ios::sync_with_stdio(0);

    int n, h, i;
    cin >> n >> h >> i;

    vector <vector <lli>> people(2000, vector <lli>(2000, 0));
    vector <lli> mx_people(2000, 0);

    for(int k=1; k<=n; k++){
        int p;
        cin >> p;
        while(p--){
            int f;
            cin >> f;
            people[k][f]++;
        }
    }

    for(int k=1; k<=h; k++){
        for(int b=1; b<=n; b++){
            mx_people[k] = max(mx_people[k], people[b][k]);
        }
    }


    vector <vector <lli>> dp(n+1, vector <lli>(h+1, 0));

    for(int k=1; k<=n; k++){
        dp[k][1] = people[k][1];
        mx_people[1] = max(dp[k][1], mx_people[1]);
    }
    
    for(int b=2; b<=h; b++){
        for(int k=1; k<=n; k++){
            if(b > i)
                dp[k][b] = max(mx_people[b-i], dp[k][b]);

            dp[k][b] = max(dp[k][b-1], dp[k][b]);
            
            dp[k][b] += people[k][b];
            mx_people[b] = max(dp[k][b], mx_people[b]);
        }
    }
    
    lli res = LLONG_MIN;
    for(int k=1; k<=n; k++){
        res = max(res, dp[k][h]);
    }
    
    cout << res << endl; 
    return 0;
}