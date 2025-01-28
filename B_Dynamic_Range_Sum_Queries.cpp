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

vector<ll>v;
vector<ll>segmentTree;
void build(ll nodo, ll left, ll right){
    if(left == right){
        segmentTree[nodo] = v[left];
    }
    else{
        ll mid = (left + right)/2;
        build(nodo*2, left, mid);
        build(nodo*2 + 1, mid + 1, right);
        segmentTree[nodo] = segmentTree[nodo*2] + segmentTree[nodo*2 + 1];
    }
}
ll suma(ll nodo, ll left, ll right, ll l, ll r){
    if ( l > r ) return 0;
    if ( l == left && r == right){
        return segmentTree[nodo];
    }
    ll mid = (left + right)/2;
    return suma(nodo*2, left, mid, l, min(r, mid)) +
            suma(nodo*2 + 1, mid + 1, right, max(l, mid+1), r);
}
void update(ll v, ll left, ll right, ll pos, ll new_val) {
    if (left == right) {
        segmentTree[v] = new_val;
    } else {
        ll tm = (left + right) / 2;
        if (pos <= tm){
            update(v*2, left, tm, pos, new_val);
        }
        else{
            update(v*2+1, tm+1, right, pos, new_val);
        }
        segmentTree[v] = segmentTree[v*2] + segmentTree[v*2+1];
    }
}
void Solve(){
    ll n, m, k, l, d, r, ans = 0;
    cin >> n >> m;
    v.resize(n);
    segmentTree.resize(4*n + 1);
    
    rep(i, n) cin >> v[i];
    build(1, 0, n-1);
    rep(i, m){
        cin >> k >> l >> r;
        if(k == 1){
            update(1, 0, n-1, l-1, r);
        }
        else{
            cout << suma(1, 0, n-1, l-1, r-1)<< endl;
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