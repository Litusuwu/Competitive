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
    int n, m, k, l,  r, ans = 0;
    char d;
    map<pii, int> mapa;
    cin >> n;
    int t = 0, x = 0, y = 0;
    ans = 1e9;
    rep(i, n){
        int sx = 0, sy = 0;
        cin >> d >> m;
        switch (d)
        {
            case 'N':
                sy = 1;
                break;
            case 'E':
                sx = 1;
                break;
            case 'S':
                sy = -1;
                break;
            case 'W':
                sx = -1;
                break;
            default:
                break;
        }
        rep(j, m){
            x += sx;
            y += sy;
            t++;
            if(mapa.count({x, y})){
                ans = min(ans, t - mapa[{x, y}]);
            }
            mapa[{x, y}] = t;
        } 
    }
    cout << (ans == 1e9? -1 : ans) << endl;
}


int main(){
    fastio;
    setIO("mowing");
    int time = 1 ;
    //cin >> time ;
    while(time--)Solve();
    return 0;
}

void setIO(string s){
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}