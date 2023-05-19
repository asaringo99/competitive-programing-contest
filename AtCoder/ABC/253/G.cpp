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

int n , l , r ;

int main(){
    fast_input_output
    cin >> n >> l >> r ;
    ll sum = 0 ;
    P L , R ;
    rep(i,n){
        if(sum + (n - 1 - i) >= l){
            ll cnt = 0 ;
            while(sum + cnt < l){
                L = P(i,i+cnt) ;
                cnt++ ;
            }
            break ;
        }
        sum += n - i - 1 ;
    }

    sum = 0 ;
    rep(i,n){
        if(sum + (n - 1 - i) >= r){
            ll cnt = 0 ;
            while(sum + cnt < r){
                R = P(i,i+1+cnt) ;
                cnt++ ;
            }
            break ;
        }
        sum += n - i - 1 ;
    }

    vector<int> vec(n) , res(n) ;
    rep(i,n) vec[i] = i ;
    auto [al,ar] = L ;
    auto [bl,br] = R ;

    rrep(i,ar,n) swap(vec[al],vec[i]) ;
    rep(i,n){
        if(i < ar) res[i] = vec[i] ;
        else res[i] = vec[n-1-i] ;
    }
}