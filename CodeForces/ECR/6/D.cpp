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
    ll n, m;
    cin >> n;
    vector<ll> A(n);
    rep(i,n) cin >> A[i];
    cin >> m;
    vector<ll> B(m);
    rep(i,m) cin >> B[i];
    ll sum_a = 0;
    ll sum_b = 0;
    rep(i,n) sum_a += A[i];
    rep(i,m) sum_b += B[i];
    vector<tuple<ll,int,int>> S, T;
    rep(i,n) rrep(j,i+1,n) S.push_back({(A[i]+A[j])*2,i,j});
    rep(i,m) rrep(j,i+1,m) T.push_back({(B[i]+B[j])*2,i,j});
    sort(all(S));
    sort(all(T));
    ll res = abs(sum_a - sum_b);
    vector<pair<int,int>> ans = {};
    rep(i,n){
        rep(j,m){
            if(res > abs((sum_a - A[i] + B[j]) - (sum_b + A[i] - B[j]))){
                res = abs((sum_a - A[i] + B[j]) - (sum_b + A[i] - B[j]));
                ans = {{i+1,j+1}};
            }
        }
    }
    ll val = sum_a - sum_b;
    if(!T.empty()){
        for(auto[a,i,j] : S){
            auto it = upper_bound(all(T),tuple<ll,int,int>(a-val,-1,-1));
            if(it != T.end()){
                auto[b,x,y] = *it;
                if(res > abs((sum_a - a / 2 + b / 2) - (sum_b + a / 2 - b / 2))){
                    res = abs((sum_a - a / 2 + b / 2) - (sum_b + a / 2 - b / 2));
                    ans = {{i+1,x+1}, {j+1,y+1}};
                }
            }
            it--;
            auto[b,x,y] = *it;
            if(res > abs((sum_a - a / 2 + b / 2) - (sum_b + a / 2 - b / 2))){
                res = abs((sum_a - a / 2 + b / 2) - (sum_b + a / 2 - b / 2));
                ans = {{i+1,x+1}, {j+1,y+1}};
            }
        }
    }
    cout << res << endl;
    cout << ans.size() << endl;
    for(auto[x,y] : ans){
        cout << x << " " << y << endl;
    }
}

int main(){
    fast_io
    solve();
}