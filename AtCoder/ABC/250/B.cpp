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

int n , a , b ;



int main(){
    fast_input_output
    cin >> n >> a >> b ;
    rep(i,n*a){
        rep(j,n*b){
            if((i%(2*a)<a && j%(2*b)<b)||(i%(2*a)>=a && j%(2*b)>=b)) cout << '.' ;
            else cout << "#" ;
        }
        cout << endl ;
    }
}