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
    int n , k ;
    string S ;
    cin >> n >> k >> S ;
    vector<bool> used(n) ;
    ll sum = 0 ;
    rep(i,n) sum += S[i] == '1' ? 11 : 0 ;
    int kk = k ;
    bool ok = false ;
    for(int i = n - 1 ; i >= 0 ; i--){
        if(S[i] == '1'){
            used[i] = true ;
            sum -= 10 ;
            ok = true ;
            break;
        }
        if(k == 0) break ;
        k-- ;
    }
    if(!ok) k = kk ;
    for(int i = 0 ; i < n ; i++){
        if(used[i]) break ;
        if(S[i] == '1'){
            sum -= 1 ;
            break ;
        }
        if(k == 0) break ;
        k-- ;
    }
    cout << sum << endl ;
}

int main(){
    cin >> t ;
    rep(i,t) solve() ;
}