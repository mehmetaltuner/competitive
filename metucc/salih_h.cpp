#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define MAXN ((int)2e5+5)
#define MOD ((int)1e9 + 7) 
#define ll long long
#define _ << " " <<
#define TRACE(x) cout << #x << " = " << x << endl;
#define pb push_back
#define MP make_pair
#define pi pair<int,int>
#define vi vector<int>
#define vii vector<pi>
#define all(x) x.begin(), x.end()
#define fi first
#define sc second
#define bf(number,i) ((number>>i)&1)
#define endl '\n'
int n,m,t,k;
int d[MAXN];
int minn = INT_MAX;
int num;
bool hasbefore[1000001];
struct Node{
	Node* children[2];

	Node(){
		children[0] = NULL;
		children[1] = NULL;
	};

	~Node(){
		for (int i = 0; i < 2; ++i)
			if(children[i])
				children[i]->~Node();
	};
};

Node* root = new Node;

void add(int a)
{
//	vector <int> v;
//
//	for (int i = 0; i < 21; ++i)
//	{
//		v.pb(a&1);
//		a = a>>1;
//	}
//	reverse(all(v));

	Node* tmp = root;

	for (int i = 0; i < 21; ++i)
	{
		if(tmp->children[bf(num, i)] == NULL) tmp->children[bf(num, i)] = new Node;
		tmp = tmp->children[bf(num, i)];
	}
}

void traverseAll(Node* cur);

void find(Node* &tmp ,int cur, int dep)
{
	/*if(cur > minn) return;

	if(dep == 21 and cur == minn) return;

	if(dep > 21){
		minn = cur;
		return;
	}

	if(tmp->children[0])
	{
		find(tmp->children[0] ,  cur + (v[dep] != 0)  ,  dep+1) ;
	}
	if(tmp->children[1])
	{
		find(tmp->children[1],  cur + (v[dep] != 1),  dep+1);
	}*/
	stack <pair <Node *, pair <int, int>>> s;
	s.push({tmp, {cur, dep}});

	while(!s.empty()){
		int dep = s.top().sc.sc;
		int cur = s.top().sc.fi;
		Node *temp = s.top().fi;
		s.pop();

		if(cur > minn) continue;

		if(dep == 21 and cur == minn) continue;

		if(dep > 21){
			minn = cur;
			continue;
		}

		if(temp->children[0]){
			s.push({temp->children[0], {cur+(bf(num, dep) != 0), dep+1}});
		}

		if(temp->children[1]){
			s.push({temp->children[1], {cur+(bf(num, dep) != 1), dep+1}});
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int t,a;
		cin >> t >> a;
        num = a;
		if(t == 1){
			if(!hasbefore[a]){
				add(a);
				hasbefore[a] = 1;
			}
		}
		else
		{
			if(hasbefore[a]){
				cout << 0 << endl;
				continue;
			}else
            {
                bool flag = false;
                for(int i = 0;  i < 21; i++)
                {
                    if(hasbefore[a^(1<<i)])
                    {
                        cout<<1<<endl;
                        flag = true;
                        break;
                    }
                }
                if(flag) continue;
            }
            
			minn = INT_MAX;

			find(root,0,0);
			cout << minn << endl;
		}
	}

	// traverseAll(root);

	return 0;
}

void traverseAll(Node* cur)
{
	if(cur->children[0])
	{
		cout << ++t << " go to 0\n";
		traverseAll(cur->children[0]);
	}
	if(cur->children[1])
	{
		cout << ++t << " go to 1\n";
		traverseAll(cur->children[1]);
	}
}