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
int A[10101] , S[10101] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    int res = 1e8 ;
    rep(i,n){
        rep(j,n) S[j] = A[j] ;
        rrep(k,1,4){
            int sum = n ;
            S[i] = k ;
            int lef = 0 , rig = 0 ;
            while(rig < n){
                int c = S[rig] ;
                while(rig < n && c == S[rig]) rig++ ;
                if(rig - lef >= 4) sum - (rig - lef) ;
                if(i == 5 && k == 2) cout << rig - lef << endl ;
                while(lef < n && c == S[lef]) lef++ ;
            }
            chmin(res,sum) ;
        }
    }
    cout << res << endl ;
}