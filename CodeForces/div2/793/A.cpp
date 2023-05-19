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
    string S ;
    cin >> n >> S ;
    if(n % 2 == 0){
        int s = n / 2 ;
        int t = s - 1 ;
        char bef = S[n/2] ;
        int res = 0 ;
        while(t >= 0){
            if(bef != S[s]) break ;
            if(S[s] != S[t]) break ;
            if(S[s] == S[t]) res += 2 ;
            t-- ;
            s++ ;
        }
        cout << res << endl ;
    }
    else{
        int s = n / 2 + 1 ;
        int t = n / 2 - 1 ;
        int res = 1 ;
        char bef = S[n/2] ;
        while(t >= 0){
            if(bef != S[s]) break ;
            if(S[s] != S[t]) break ;
            if(S[s] == S[t]) res += 2 ;
            t-- ;
            s++ ;
        }
        cout << res << endl ;
    }
}

int main(){
    cin >> t ;
    rep(i,t) solve() ;
}