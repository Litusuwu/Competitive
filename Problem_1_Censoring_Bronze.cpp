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
    string s, sub, rpta;
    cin >> s >> sub;
    rep(i, s.size()){
        rpta += s[i];
        if(rpta.size() >= sub.size() && rpta.substr(rpta.size() - sub.size()) == sub){
            rpta.erase(rpta.size() - sub.size());
        }
    }
    cout << rpta << endl;
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