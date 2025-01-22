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
    char c;
    int x, y;
    vector<pair<pii, int>>North, East;
    rep(i, n){
        cin >> c >> x >> y;
        if(c=='N'){
            North.push_back({{x, y}, 0});
        }
        else{
            East.push_back({{x, y}, 0});
        }
    }
    rep(i, East.size()){
        int x1 = East[i].F.F, y1 = East[i].F.S;
        rep(i, North.size()){
            int x2 = North[i].F.F, y2 = North[i].F.S;
            if(North[i].S == -1 || x1 > x2 || y2 > y1)continue;
            int dHorizontal = abs(x2 - x1);
            int dVertical = abs(y1 - y2);
            if(dVertical < dHorizontal){
                
            }
            else if( dVertical > dHorizontal){

            }
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