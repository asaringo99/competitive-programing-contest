#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define endl "\n"

int z ;

void solve(){
    int n;
    cin >> n;
    map<int,int> mp, sp;
    vector<pair<int,int>> X;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        a--;
        if(b == 1) mp[a]++;
        else sp[a]++;
    }
    for(auto it : mp){
        auto[x,c] = it;
        if(sp.count(x)) X.push_back({sp[x]+mp[x],mp[x]});
        else X.push_back({mp[x],mp[x]});
    }
    for(auto it : sp){
        auto[x,c] = it;
        if(!mp.count(x)) X.push_back({sp[x],0});
    }
    sort(X.begin(),X.end());
    int m = X.size();
    int res = 0, dic = 0;
    while(!X.empty()){
        int i = X.size() - 1;
        auto [s,f] = X[i];
        vector<pair<int,int>> Y;
        while(i >= 0){
            auto [sum, type] = X[i];
            if(sum != s) break;
            X.pop_back();
            Y.push_back({sum,type});
            i--;
        }
        sort(Y.begin(),Y.end());
        f = Y[Y.size()-1].second;
        for(int j = 0 ; j < Y.size() - 1 ; j++){
            auto [sum, type] = Y[j];
            if(sum == type){
                sum--;
                type--;
            }
            else sum--;
            if(sum > 0) X.push_back({sum,type});
        }
        res += s, dic += f;
    }
    cout << res << " " << dic << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}