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

ll powll(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

int t ;

void solve(){
    string S ;
    ll n ;
    cin >> n ;
    S = to_string(n) ;
    ll d = to_string(n).size() ;
    vector<int> vec ;
    for(ll i = 1 ; i < d ; i++){
        if(d % i == 0) vec.push_back(i) ;
    }
    vector<ll> res ;
    ll ss = 0 ;
    rep(i,d-1){
        ss *= 10LL ;
        ss += 9LL ;
    }
    res.push_back(ss) ;
    for(int u : vec){
        ll val = 0 ;
        rep(i,u){
            val *= 10LL ;
            val += S[i] - '0' ;
        }
        // cout << val << endl ;
        bool ok = true ;
        for(int i = 0 ; i < d / u ; i++){
            ll sum = 0 ;
            for(int j = 0 ; j < u ; j++){
                sum *= 10 ;
                sum += S[i*u+j] - '0' ;
            }
            // cout << val << " " << sum << endl ;
            if(sum == val) continue;
            else if(sum > val) break ;
            if(sum < val) {
                ok = false ;
                break ;
            }
        }
        if(ok){
            ll sum = 0 ;
            rep(i,d/u){
                sum *= powll(10,u) ;
                sum += val ;
            }
            res.push_back(sum) ;
        }
        else{
            if(val == powll(10,d-1)) continue ;
            val-- ;
            ll sum = 0 ;
            rep(i,d/u){
                sum *= powll(10,u) ;
                sum += val ;
            }
            res.push_back(sum) ;
        }
    }
    sort(res.begin(),res.end(),greater<ll>()) ;
    cout << res[0] << endl ;
}

int main(){
    // fast_input_output
    cin >> t ;
    rep(i,t) solve() ;
}