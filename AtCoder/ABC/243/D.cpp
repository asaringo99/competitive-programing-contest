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

ll n , x ;
string S ;

int main(){
    fast_input_output
    cin >> n >> x >> S ;
    int count = 0 ;
    rep(i,n){
        if(count > 0){
            if(S[i] == 'L' || S[i] == 'R') count++ ;
            else count-- ;
            if(count == 0) x /= 2 ;
        }
        else{
            if(S[i] == 'L') x = x * 2 ;
            if(S[i] == 'R') x = x * 2 + 1 ;
            if(S[i] == 'U') x = x / 2 ;
            if(x > 1000000000000000000LL) count++ ;
        }
    }
    cout << x << endl ;
}