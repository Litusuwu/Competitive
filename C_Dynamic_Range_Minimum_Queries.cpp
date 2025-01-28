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

vector<int>segmentTree;
vector<int>v;

void setIO(string s);
void build(int nodo, int left, int right){
    if(left == right){
        segmentTree[nodo] = v[left];
    }
    else{
        int mid = (left+right)/2;
        build(2*nodo, left, mid);
        build(2*nodo + 1, mid+1, right);
        segmentTree[nodo] = min(segmentTree[2*nodo], segmentTree[2*nodo +1]);
    }
}
void update(int nodo, int limIzq, int limDer, int pos, int newval){
    if ( limIzq == limDer ){
        segmentTree[nodo] = newval;
    }
    else{
        int mid = (limIzq + limDer) / 2;
        if( pos <= mid){
            update(nodo*2, limIzq, mid, pos, newval);
        }
        else{
            update(nodo*2 + 1, mid + 1, limDer, pos, newval);
        }
        segmentTree[nodo] = min(segmentTree[nodo*2], segmentTree[nodo*2 + 1]);
    }
}
int minimo(int nodo, int limIzq, int limDer, int l, int r){
    if ( l > r ){
        return INT_MAX;
    }
    if ( l == limIzq && limDer == r){
        return segmentTree[nodo];
    }
    int medio = (limIzq + limDer) / 2;
    return min(minimo(nodo*2, limIzq, medio, l, min(r, medio))
            ,minimo(nodo*2 + 1, medio + 1, limDer, max(l, medio+1), r) );
}
void Solve(){
    int n, m, k, l, d, r, ans = 0;
    cin >> n >> m;
    v.resize(n);
    segmentTree.resize(4*n + 1);
    
    rep(i, n) cin >> v[i];
    build(1, 0, n-1);
    for(int i = 0 ; i < m ; i ++){
        cin >> k >> l >> r;
        if(k == 1){
            update(1, 0, n-1, l-1, r);
        }
        else{
            cout << minimo(1, 0, n-1, l-1, r-1) << endl;
        }
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