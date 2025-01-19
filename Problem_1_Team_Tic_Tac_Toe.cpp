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
    int ans1 = 0 , ans2 = 0;
    string s[3];
    cin >> s[0] >> s[1] >> s[2];
    rep(i, 3){
        if(s[i][0] == s[i][1] && s[i][1] == s[i][2]){
            ans1++;
        }
        if(s[0][i] == s[1][i] && s[1][i] == s[2][i]){
            ans1++;
        }
        if(s[i][0] == s[i][1] && s[i][1] != s[i][2] || s[i][1] ==  s[i][2] && s[i][1] != s[i][0] || s[i][0] == s[i][2] && s[i][0] != s[i][1]){
            ans2++;
        }
        if(s[0][i] == s[1][i] && s[1][i] != s[2][i] || s[1][i] ==  s[2][i] && s[1][i] != s[0][i] || s[0][i] == s[2][i] && s[0][i] != s[1][i]){
            ans2++;
        }
    }
    if(s[0][0] == s[1][1] && s[1][1] == s[2][2]){
        ans1++;
    }
    if(s[0][2] == s[1][1] && s[1][1] == s[2][0]){
        ans1++;
    }
    if(s[0][0] == s[1][1] && s[1][1] != s[2][2] || s[0][0] == s[2][2] && s[1][1] != s[2][2] || s[2][2] == s[1][1] && s[1][1] != s[0][0] ){
        ans2++;
    }
    if(s[0][2] == s[1][1] && s[1][1] != s[2][0] || s[2][0] == s[0][2] && s[1][1] != s[0][2] || s[2][0] == s[1][1] && s[1][1] != s[0][2] ){
        ans2++;
    }
    
    // cout << s[0];
    cout << ans1 << endl << ans2 << endl;
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