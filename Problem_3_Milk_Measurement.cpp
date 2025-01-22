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
    map<string, int> mp;
    mp.insert({"Bessie", 7});
    mp.insert({"Elsie", 7});
    mp.insert({"Mildred", 7});
    vector<pair<int, pair<string, int>>> p;
    rep(i, n){
        string s;
        int x, num;
        char c;
        cin >> x >> s >> c >> num;
        if(c=='-'){
            num*=-1;
        }
        p.push_back({x, {s, num}});
    }
    sort(all(p));

    rep(i, n){
        int x, num;
        string nom;
        nom = p[i].S.F;
        num = p[i].S.S;

        int c1, c2, c3, cc1,cc2,cc3;
        c1 = mp["Bessie"];c2 = mp["Elsie"];c3 = mp["Mildred"];
        int max1 = max(c1, max(c2, c3));
        vector<bool> v(3);
        v[0] = c1 == max1;
        v[1] = c2 == max1;
        v[2] = c3 == max1;
        mp[nom]+=num;
        cc1 = mp["Bessie"]; cc2 = mp["Elsie"];cc3 = mp["Mildred"];
        int max2 = max(cc1, max(cc2, cc3));
        vector<bool> v2(3);
        v2[0] = cc1 == max2;
        v2[1] = cc2 == max2;
        v2[2] = cc3 == max2;
        if(v[0] != v2[0] || v[1] != v2[1] || v[2] != v2[2]){
            ans++;
        }
    }
    cout << ans << endl;
}


int main(){
    fastio;
    setIO("measurement");
    int time = 1 ;
    //cin >> time ;
    while(time--)Solve();
    return 0;
}

void setIO(string s){
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}