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

vector<ll>chad;

ll getNext(ll num){
    return chad[num] == num ? num : chad[num] = getNext(chad[num]); 
}

void Solve(){
    ll n, m, k, l, d, r, ans = 0;
    cin >> n >> m;

    vector<ll>vec(n+1, 0);
    chad.resize(n+3);
    iota(all(chad), 0);
    rep(z, m){
        cin >> l >> r >> d;
        ll num = getNext(l);
        while(num <= r){
            if(num == d){
                num = getNext(num + 1);
                continue;
            }
            vec[num] = d;
            chad[num] = getNext(num + 1);
            num = chad[num];
        }
    }
    for(int i = 1 ; i < n + 1 ; i++)cout << vec[i] << " ";
    cout << endl;
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