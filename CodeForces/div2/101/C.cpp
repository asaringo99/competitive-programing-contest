#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

queue<string> que[3030];
vector<pair<string,int>> res;

const int H = 1000000000;
int n;

// v: 深さ
bool dfs(int v, int &sum){
    string s = que[v].front(); que[v].pop();
    res.push_back({s,H-v});
    if((int)res.size() == n) return true;
    sum++;
    int k = -1;
    for(int i = sum; i >= 0; i--){
        if(que[i].empty()) continue;
        k = i;
        break;
    }
    if(k == -1) return false;
    return dfs(k,sum);
}

void solve(){
    cin >> n;
    rep(i,n) {
        string c;
        ll h;
        cin >> c >> h;
        que[h].push(c);
    }
    int sum = 0;
    bool ok = dfs(0, sum);
    // for(auto p : res){
    //     cout << p.first << " " << p.second << endl;
    // }
    if(!ok) cout << -1 << endl;
    else{
        for(auto p : res){
            cout << p.first << " " << p.second << endl;
        }
    }
}

int main(){
    // fast_io
    solve();
}