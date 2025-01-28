#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i < n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
#define endl "\n"
typedef long double ld;
typedef long long ll;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void setIO(string s);
vector<int>segmentTree;
vector<int>v;

void build(int nodo, int left, int right){
    if(left == right){
        segmentTree[nodo] = min(INT_MAX, v[left]);  
    }
    else{
        int med = (left+right)/2;
        build(2*nodo, left, med);
        build(2*nodo + 1, med+1, right);
        segmentTree[nodo] = min(segmentTree[2*nodo], segmentTree[2*nodo + 1]);
    }
}
int searchMin(int nodo, int left, int right, int l, int r){
    if(l>r)return INT_MAX;
    if(l == left && r == right){
        return segmentTree[nodo];
    }
    int med = (left + right) / 2;
    return min(searchMin(nodo*2, left, med, l, min(r, med))
            , searchMin(nodo*2 + 1, med + 1, right, max(med+1, l), r));
}
void Solve(){
    int n, m, k, l, d, r, ans = 0;
    cin >> n >> m;
    segmentTree.resize(4*n);
    v.resize(n);
    rep(i, n)cin >> v[i];
    build(1, 0, n-1);
    rep(i, m){
        cin >> l >> r;
        cout << searchMin(1, 0, n-1, l-1, r-1) << endl;
    }
}


int main(){
    fastio;
    //setIO();
    int time = 1 ;
    //cin >> time ;
    while(time--)Solve();
    return 0;
}

void setIO(string s){
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}