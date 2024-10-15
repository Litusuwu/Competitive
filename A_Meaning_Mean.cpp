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
    ll n, m, k, l, d, r,c = 0, ans = 0;

    cin >> n;
    vector<int>numbers(n);
    
    rep(i, n){
        cin >> numbers[i];
    }
    sort(all(numbers));
    ans += (numbers[0]+numbers[1])/2;
    for(int i = 2; i < n ; i++){
        ans = (ans+numbers[i])/2;
    }
    cout << ans << endl;
}


int main(){
    fastio;
    //setIO()
    int time = 1 ;
    cin >> time ;
    while(time--)Solve();
    return 0;
}

void setIO(string s){
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}