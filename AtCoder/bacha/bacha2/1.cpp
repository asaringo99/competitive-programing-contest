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
int A[101010] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    int bef = A[0] ;
    ll cnt = 1 , res = 0 ;
    rrep(i,1,n){
        if(bef < A[i]) cnt += 1 ;
        else{
            res += cnt * (cnt + 1) / 2 ;
            cnt = 1 ;
        }
        bef = A[i] ;
    }
    res += cnt * (cnt + 1) / 2 ;
    cout << res << endl ;
}