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
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)
#define endl "\n"

ll n , k ;

ll combination(ll n , ll k){
    ll res = 1 ;
    rep(i,k) res *= n - i ;
    rep(i,k) res /= i + 1 ;
    return res ;
}

ll f(ll tot){
    ll sum = 0 ;
    rep(i,4){
        if(i % 2 == 0 && tot - i * (n + 1) - (3 - i) >= 0) sum += combination(tot - i * (n + 1) - (3 - i) + 2 , 2) * combination(3,i) ;
        if(i % 2 == 1 && tot - i * (n + 1) - (3 - i) >= 0) sum -= combination(tot - i * (n + 1) - (3 - i) + 2 , 2) * combination(3,i) ;
    }
    return sum ;
}

ll g(ll tot){
    ll sum = 0 ;
    rep(i,3){
        if(i % 2 == 0 && tot - i * (n + 1) - (2 - i) >= 0) sum += combination(tot - i * (n + 1) - (2 - i) + 1 , 1) * combination(2,i) ;
        if(i % 2 == 1 && tot - i * (n + 1) - (2 - i) >= 0) sum -= combination(tot - i * (n + 1) - (2 - i) + 1 , 1) * combination(2,i) ;
    }
    return sum ;
}


int main(){
    cin >> n >> k ;
    ll sum = 0 ;
    rrep(i,3,3*n+1){
        ll comb = f(i) ;
        if(sum + comb >= k){
            rrep(a,1,n+1){
                ll tmp = g(i - a) ;
                if(sum + tmp >= k){
                    rrep(b,1,n+1){
                        if(i - a - b > n) continue ;
                        sum++ ;
                        if(sum == k){
                            cout << a << " " << b << " " << i - a - b << endl ;
                            return 0 ;
                        }
                    }
                }
                sum += tmp ;
            }
        }
        sum += comb ;
    }
}