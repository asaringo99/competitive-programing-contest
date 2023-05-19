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

int k ;
string T ;

int S[3030303][3] ;

int main(){
    cin >> k >> T ;
    int n = T.size() ;
    rep(i,2*n){
        S[i+1][0] = S[i][0] ;
        S[i+1][1] = S[i][1] ;
        S[i+1][2] = S[i][2] ;
        if(T[i%n] == 'J') S[i+1][0]++ ;
        if(T[i%n] == 'O') S[i+1][1]++ ;
        if(T[i%n] == 'I') S[i+1][2]++ ;
    }
    int res = 1e9 ;
    rep(i,n){
        int sum = 0 ;
        int num = i ;
        for(int lev = k - 1 ; lev >= 0 ; lev--){
            int pls = 1 << lev * 2 ;
            num += pls ;
            sum += pls - (S[num][0] - S[num-pls][0]) ;
            num += pls ;
            sum += pls - (S[num][1] - S[num-pls][1]) ;
            num += pls ;
            sum += pls - (S[num][2] - S[num-pls][2]) ;
        }
        chmin(res,sum) ;
    }
    cout << res << endl ;
}