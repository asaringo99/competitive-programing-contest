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

string S ;
ll fac[21] ;
ll A[30] ;

int main(){
    cin >> S ;
    for(char u : S) A[u-'A']++ ;
    fac[0] = fac[1] = 1 ;
    rrep(i,2,21) fac[i] = fac[i-1] * i ;
    ll res = 1 ;
    rep(i,S.size()){
        ll sum = 0 ;
        rep(j,S[i]-'A'){
            if(A[j] == 0) continue ;
            ll val = 1 ;
            rep(k,26){
                if(j == k) val *= fac[A[k]-1] ;
                if(j != k) val *= fac[A[k]] ;
            }
            sum += fac[S.size() - 1 - i] / val ;
        }
        A[S[i]-'A']-- ;
        res += sum ;
    }
    cout << res << endl ;
}