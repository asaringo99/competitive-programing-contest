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

ll n , k ;
ll A[202020] ;
bool used[202020] ;
ll S[202020] , C[202020] ;

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> A[i] ;
    ll cnt = 0 , sum = 0 , mag = 0 , count = 0 ;
    if(k < 1000000LL){
        while(k > 0){
            ll mod = sum % n ;
            sum += A[mod] ;
            k-- ;
        }
        cout << sum << endl ;
        return 0 ;
    }
    while(true){
        if(used[sum % n]) {
            count = cnt - C[sum % n] ;
            mag = sum - S[sum % n] ;
            break ;
        }
        ll mod = sum % n ;
        S[mod] = sum ;
        C[mod] = cnt ;
        cnt++ ;
        sum += A[mod] ;
        used[mod] = true ;
    }
    k -= cnt ;
    ll x = k / count ;
    sum += x * mag ;
    k %= count ;
    while(k > 0){
        ll mod = sum % n ;
        sum += A[mod] ;
        k-- ;
    }
    cout << sum << endl ;
}