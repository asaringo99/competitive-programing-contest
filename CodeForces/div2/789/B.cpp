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
    string S , T ;
    cin >> n >> S ;
    T = S ;
    S += S[n-1] ;
    reverse(T.begin(),T.end()) ;
    int sum = 1 , res = 0 , cnt = 1 ;
    rep(i,n-1){
        if(S[i] == S[i+1]){
            sum++ ;
        }
        else{
            if(sum % 2 == 0) sum = 1 ;
            else{
                S[i+1] = S[i] ;
                sum++ ;
                res++ ;
                if(i+3<n && S[i+1] != S[i+2] && S[i+2] != S[i+3]){
                    S[i+2] = S[i] ;
                    res++ ;
                }
            }
        }
    }

    rep(i,n-1) if(S[i] != S[i+1]) cnt++ ;
    cout << res << " " << cnt << endl ;
}

int main(){
    cin >> t ;
    rep(i,t) solve() ;
}