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
    int buckets[3], amount[3];
    rep(i, 3)cin >> buckets[i] >> amount[i];
    rep(i, 100){
        if(i % 3 == 0){
            if(amount[0] + amount[1] <= buckets[1]){
                amount[1] += amount[0];
                amount[0] = 0;
            }
            else{
                amount[0] -= buckets[1] - amount[1];
                amount[1] = buckets[1];
            }
        }
        else if(i % 3 == 1){
            if(amount[1] + amount[2] <= buckets[2]){
                amount[2] += amount[1];
                amount[1] = 0;
            }
            else{
                amount[1] -= buckets[2] - amount[2];
                amount[2] = buckets[2];
            }
        }
        else{
            if(amount[2] + amount[0] <= buckets[0]){
                amount[0] += amount[2];
                amount[2] = 0;
            }
            else{
                amount[2] -= buckets[0] - amount[0];
                amount[0] = buckets[0];
            }
        }
    }
    cout << amount[0] << endl << amount[1] << endl << amount[2] << endl;
    
}


int main(){
    fastio;
    setIO("mixmilk");
    int time = 1 ;
    //cin >> time ;
    while(time--)Solve();
    return 0;
}

void setIO(string s){
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}