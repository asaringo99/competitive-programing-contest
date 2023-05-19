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
typedef pair<int,int> P ;
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

int n;
int mp[20][50505];

int main(){
    cin >> n;
    int bt = 0;
    while((1 << bt) <= n) bt++;
    vector<P> vec;
    rep(i,n) {
        vec.push_back({i+1,i+1});
        mp[0][i] = i;
    }
    int num = n;
    rrep(b,1,bt){
        for(int i = 0 ; i + (1 << b) <= n; i++){
            vec.push_back({i+1,i+(1<<b)});
            mp[b][i] = num++;
        }
    }
    cout << (int)vec.size() << endl;
    for(auto [l, r]: vec) cout << l << " " << r << endl;

    vector<int> logtable;
    logtable.resize(n+1,0);
    for(int i = 2; i < n + 1; i++){
        logtable[i] = logtable[i >> 1] + 1;
    }
    int q;
    cin >> q;
    rep(i,q){
        int l, r;
        cin >> l >> r;
        l--;
        int b = logtable[r - l];
        cout << mp[b][l] + 1 << " " << mp[b][r-(1<<b)] + 1 << endl;
    }
}