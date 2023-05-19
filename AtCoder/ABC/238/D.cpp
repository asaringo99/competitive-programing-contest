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

int main(){
    cin >> n ;
    rep(i,n){
        ll a , b ;
        cin >> a >> b ;
        bool ok = true ;
        ll sum = 0 ;
        bool used[101] ;
        memset(used,0,sizeof(used)) ;
        rep(j,60){
            if(a >> j & 1) {
                sum += 2 * (1LL << j) ;
                used[j] = true ;
            }
        }
        b -= sum ;
        if(b < 0){
            cout << "No" << endl ;
            continue ;
        }
        rep(j,60){
            if(b >> j & 1 && used[j]) ok = false ;
        }
        if(ok) cout << "Yes" << endl ;
        else cout << "No" << endl ;
    }
}