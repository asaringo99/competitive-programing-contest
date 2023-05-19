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

int t ;

void solve(){
    int n ;
    cin >> n ;
    vector<int> A(101) ;
    int zero = 0 ;
    bool ok = false ;
    rep(i,n) {
        int a ;
        cin >> a ;
        A[a]++ ;
        if(a == 0) zero++ ;
        else if(A[a] > 1) ok = true ;
    }
    if(zero > 0){
        cout << n - zero << endl ;
        return ;
    }
    if(ok){
        cout << n << endl ;
        return ;
    }
    cout << n + 1 << endl ;
}

int main(){
    cin >> t ;
    rep(i,t) solve() ;
}