//https://www.hackerrank.com/contests/inzva-09-data-structures-3-online-2019/challenges/balanced-brackets

#include <bits/stdc++.h>
#define ALL(e) (e.begin(), e.end())
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define fi first
#define sc second
#define N 1000000009

typedef long long int lli;

using namespace std;

bool opens(char a){
    return a == '(' or a == '[' or a == '{';
}

int main(int argc, char const *argv[])
{
    map <char, char> closes;

    closes[')'] = '(';
    closes[']'] = '[';
    closes['}'] = '{'; 

    int n;
    cin >> n;
    while(n--){
        bool ok = true;
        string s;
        stack <char> stc;
        
        cin >> s;
        int sn = s.length();

        for(int i=0; i<sn; i++){
            if(opens(s[i])){
                stc.push(s[i]);
            }else{
            	
            	if(stc.empty()){
            		ok = false;
            		break;
            	}

                if(stc.top() != closes[s[i]]){
                    ok = false;
                    break;
                }

                stc.pop();
            }
        }

        if(ok){
            ok = stc.empty();
        }

        if(!ok){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }

    }

    return 0;
}
