#include <bits/stdc++.h>
using namespace std ;
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
ll A[303030] , S[101] , dig[101] ;
vector<ll> vec[101] ;

int main(){
    cin >> n ;
    rep(i,40) S[i] = 1e10 ;
    rep(i,n){
        cin >> A[i] ;
        int k = -1 ;
        rep(j,40) if(A[i] >> j & 1){
            dig[j]++ ;
            k = j ;
        }
        if(k == -1) continue ;
        vec[k].push_back(A[i]) ;
    }
    bool ok = false ;
    for(int i = 40 ; i >= 0 ; i--){
        if(vec[i].empty()) continue ;
        if(ok) break ;
        sort(vec[i].begin(),vec[i].end(),greater<ll>()) ;
        ll XOR = 0 ;
        if(dig[i] * 2 < n){
            ok = true ;
            rep(j,vec[i].size()){
                ll x = XOR ^ vec[i][j] ;
                bool gd = false ;
                rep(k,40){
                    if(x >> k & 1) {
                        if(gd) dig[k] = n - dig[k] ;
                        if(!gd) {
                            if(dig[k] * 2 < n) {
                                XOR ^= vec[i][j] ;
                                dig[k] = n - dig[k] ;
                                gd = true ;
                            }
                            else break ;
                        }
                    }
                }
            }
        }
    }
    ll res = 0 ;
    rep(i,40){
        res += (1LL << i) * dig[i] ;
    }
    cout << res << endl ;
}