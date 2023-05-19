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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<pair<int,int>> vec;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        vec.push_back({a,1});
        vec.push_back({b+1,-1});
    }
    sort(all(vec));
    int m = vec.size();
    int sum = 0;
    bool ok = false;
    vector<int> V;
    rep(i,m){
        auto[x,c] = vec[i];
        sum += c;
        if(sum >= k && !ok){
            ok = true;
            V.push_back(x);
        }
        if(sum < k && ok){
            ok = false;
            V.push_back(x-1);
        }
    }
    cout << V.size() / 2 << endl;
    for(int i = 0; i < V.size(); i += 2){
        int a = V[i];
        int b = V[i+1];
        cout << a << " " << b << endl;
    }
}

int main(){
    fast_io
    solve();
}