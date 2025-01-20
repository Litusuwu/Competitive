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
    set<char>rSet;
    set<pair<char,char>> rSet2;
    cin >> s[0] >> s[1] >> s[2];
    rep(i, 3){
        if(s[i][0] == s[i][1] && s[i][1] == s[i][2]){
            rSet.insert(s[i][0]);
        }
        if(s[0][i] == s[1][i] && s[1][i] == s[2][i]){
            rSet.insert(s[0][i]);
        }
        if(s[i][0] == s[i][1] && s[i][1] != s[i][2] || s[i][1] ==  s[i][2] && s[i][1] != s[i][0] ||
             s[i][0] == s[i][2] && s[i][0] != s[i][1]){
            if(s[i][0] == s[i][1]){
                rSet2.insert({s[i][0],s[i][2]});
                rSet2.insert({s[i][2],s[i][0]});
            }
            else if(s[i][1] == s[i][2]){
                rSet2.insert({s[i][0],s[i][2]});
                rSet2.insert({s[i][2],s[i][0]});
            }
            else if(s[i][0] == s[i][2]){
                rSet2.insert({s[i][0],s[i][1]});
                rSet2.insert({s[i][1],s[i][0]});
            }
        }
        if(s[0][i] == s[1][i] && s[1][i] != s[2][i] || s[1][i] ==  s[2][i] && s[1][i] != s[0][i] ||
             s[0][i] == s[2][i] && s[0][i] != s[1][i]){

            if(s[0][i] == s[1][i]){
                rSet2.insert({s[2][i],s[1][i]});
                rSet2.insert({s[1][i],s[2][i]});
            }
            else if(s[1][i] == s[2][i]){
                rSet2.insert({s[1][i],s[0][i]});
                rSet2.insert({s[0][i],s[1][i]});
            }
            else if(s[0][i] == s[2][i]){
                rSet2.insert({s[0][i],s[1][i]});
                rSet2.insert({s[1][i],s[0][i]});
            }
        }
    }
    if(s[0][0] == s[1][1] && s[1][1] == s[2][2]){
        rSet.insert(s[0][0]);
    }
    if(s[0][2] == s[1][1] && s[1][1] == s[2][0]){
        rSet.insert(s[0][2]);
    }
    if(s[0][0] == s[1][1] && s[1][1] != s[2][2] || s[0][0] == s[2][2] && s[1][1] != s[2][2] ||
         s[2][2] == s[1][1] && s[1][1] != s[0][0] ){
        if(s[0][0]==s[1][1]){
            rSet2.insert({s[0][0],s[2][2]});
            rSet2.insert({s[2][2],s[0][0]});
        }
        else if(s[0][0]==s[2][2]){
            rSet2.insert({s[0][0],s[1][1]});
            rSet2.insert({s[1][1],s[0][0]});
        }
        else if(s[1][1]==s[2][2]){
            rSet2.insert({s[1][1],s[0][0]});
            rSet2.insert({s[0][0],s[1][1]});
        }
    }
    if(s[0][2] == s[1][1] && s[1][1] != s[2][0] || s[2][0] == s[0][2] && s[1][1] != s[0][2] || 
        s[2][0] == s[1][1] && s[1][1] != s[0][2] ){
        if(s[0][2] == s[1][1]){
            rSet2.insert({s[0][2],s[2][0]});
            rSet2.insert({s[2][0],s[0][2]});
        }
        else if(s[0][2] == s[2][0]){
            rSet2.insert({s[0][2],s[1][1]});
            rSet2.insert({s[1][1],s[0][2]});
        }
        else if(s[1][1] == s[2][0]){
            rSet2.insert({s[1][1],s[0][2]});
            rSet2.insert({s[0][2],s[1][1]});
        }
    }
    
    // cout << s[0];
    cout << rSet.size() << endl << rSet2.size()/2 << endl;
    // for(auto it : rSet2){
    //     cout << it.F << " #" << it.S << endl;
    // }
    
}


int main(){
    fastio;
    setIO("tttt");
    int time = 1 ;
    //cin >> time ;
    while(time--)Solve();
    return 0;
}

void setIO(string s){
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}