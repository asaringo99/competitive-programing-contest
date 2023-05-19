#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
#define endl "\n"

int n ;
ll s ;
ll A[10] ;
map<ll,ll> dp[5] , ep[5] ;
vector<ll> X , Y ;

int main(){
    fast_input_output
    cin >> n >> s ;
    rep(i,n) cin >> A[i] ;
    int m = n/2 ;
    dp[0][0] = 1 ;
    rep(i,m){
        for(auto it : dp[i]){
            ll val = it.first , cnt = it.second ;
            ll a = A[i] , x = A[i] ;
            while(val + a < s){
                dp[i+1][val+a] += cnt ;
                a *= x ;
            }
        }
    }
    for(auto it : dp[m]){
        ll val = it.first , cnt = it.second ;
        while(cnt > 0){
            X.push_back(val) ;
            cnt-- ;
        }
    }

    ep[0][0] = 1 ;
    rep(i,n-m){
        for(auto it : ep[i]){
            ll val = it.first , cnt = it.second ;
            ll a = A[i+m] , x = A[i+m] ;
            while(val + a < s){
                ep[i+1][val+a] += cnt ;
                a *= x ;
            }
        }
    }
    ll res = 0 ;
    for(auto it : ep[n-m]){
        ll val = it.first , cnt = it.second ;
        auto kt = upper_bound(X.begin(),X.end(),s-val) ;
        res += (ll)(kt - X.begin()) * cnt ;
    }
    cout << res << endl ;
}