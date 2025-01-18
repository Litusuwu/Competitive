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

void Solve(){
    int n, m, k, l, d, r, ans = 0;
    cin >> n;
    vector<vector<int>>shell{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int v[3] = {0, 0, 0};
    rep(i, n){
        cin >> m >> k >> l;
        swap(shell[0][m - 1], shell[0][k - 1]);
        swap(shell[1][m - 1], shell[1][k - 1]);
        swap(shell[2][m - 1], shell[2][k - 1]);
        rep(d, 3)if(shell[d][l - 1] == 1) v[d]++;
    }
    cout << max(v[0], max(v[1], v[2])) << endl;
}


int main(){
    fastio;
    setIO("shell");
    int time = 1 ;
    // cin >> time ;
    while(time--)Solve();
    return 0;
}

void setIO(string s){
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}