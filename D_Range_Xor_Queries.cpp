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
        segmentTree[nodo] = v[right];
    }
    else{
        int mid = (right + left)/2;
        build(nodo * 2, left , mid);
        build(nodo * 2 + 1, mid + 1, right);
        segmentTree[nodo] = segmentTree[nodo*2] ^ segmentTree[nodo *2 + 1];
    }
}

int buscar(int nodo, int left, int right, int l, int r){
    if(l > r){
        return 0;
    }
    if(left == l && right == r){
        return segmentTree[nodo];
    }
    int mid = (right + left)/2;
    return buscar(nodo*2, left, mid, l, min(r, mid)) ^ buscar(nodo*2 + 1, mid + 1, right, max(l, mid+1),r);
    
}

void Solve(){
    int n, m, k, l, d, r, ans = 0;
    cin >> n >> m;segmentTree.resize(n*4 + 1);v.resize(n);
    rep(i, n) cin >> v[i];
    build(1, 0, n-1);
    rep(i, m){
        cin >> l >> r;
        cout << buscar(1, 0, n-1, l-1, r-1) << endl; 
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