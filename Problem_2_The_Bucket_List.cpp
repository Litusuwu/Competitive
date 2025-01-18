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
    vector<pair<pii, int>>vacas;
    rep(i, n){
        cin >> m >> l >> d;
        vacas.push_back({{m,l}, d});
    }
    sort(all(vacas));
    rep(i, 1000){
        int prevAns=0;
        rep(j, n){
            if(vacas[j].F.S > i && vacas[j].F.F <= i)prevAns+=vacas[j].S;
        }
        ans = max(prevAns, ans);
    }
    cout << ans << endl;
}


int main(){
    fastio;
    setIO("blist");
    int time = 1 ;
    //cin >> time ;
    while(time--)Solve();
    return 0;
}

void setIO(string s){
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}