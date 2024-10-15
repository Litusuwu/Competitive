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
    int n, x;
    cin >> n >> x;
    priority_queue<int> cars;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        cars.push(k);
    }
    int ans = 0;
    while (!cars.empty()) {
        if(cars.size()==1){
            ans+=cars.top();
            break;
        }
        vector<int> to_update;
        int index;
        for (int z = 0; z < x && !cars.empty(); ++z) {
            int car_count = cars.top();
            cars.pop();
            
            to_update.push_back(car_count);
            index = z;   
        }
        for (int val : to_update) {
            cars.push(val - to_update[index]);
        }
        ans++;
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