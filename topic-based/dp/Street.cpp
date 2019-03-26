#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define mid (l + r) / 2
#define fi first
#define sc second
#define N 509

using namespace std;

typedef long long int lli;

int n,k,t;
int d[N];
int seg[4*N];

void build(int index, int l, int r)
{
	if(l == r){
		seg[index] = d[l];
		return;
	}
	build(index*2,l,mid);
	build(index*2+1,mid+1,r);

	seg[index] = min(seg[index*2] , seg[index*2+1]);
}

void update(int index, int l , int r , int x , int val)
{
	if(l==r){
		seg[index] = val;
		return; 
	}
	if(l > x or r < x) return;


	update(index*2,l,mid,x,val);	
	update(index*2+1,mid+1,r,x,val);	
	seg[index] = min(seg[index*2] , seg[index*2+1]);
} 

int query(int index, int l , int r , int bgn, int end)
{
	if(bgn > r or l > end)
		return INT_MAX;
	if(bgn <= l and end >= r) return seg[index];

	return min(
			query(index*2,l,mid,bgn,end),
			query(index*2+1,mid+1,r,bgn,end)
		);
}

int main(){

	cin >> n >> k >> t;
 
	for (int i = 1; i <= n; ++i)
	{
		cin >> d[i];
	}

	for (int i2 = 0; i2 < k; ++i2)
	{
		int maxx = 0,ind,ll,rr;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i; j <= i+t-1; ++j)
			{
				int q = query(1,1,n,i,j);
				if(maxx < q * (j-i+1))
				{
					maxx = q * (j-i+1);
					ll = i;
					rr = j;
				}
			}
		}
	}


	return 0;
}