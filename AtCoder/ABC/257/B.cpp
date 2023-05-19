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

int n , k , q ;
int A[2020] , L[2020] , B[2020] ;

int main(){
    fast_input_output
    cin >> n >> k >> q ;
    rep(i,n) A[i] = -1 ;
    rep(i,k) {
        int a ;
        cin >> a ;
        a-- ;
        A[a] = i ;
        B[i] = a ;
    }
    rep(i,q) cin >> L[i] ;
    rep(i,q){
        int l = L[i] ;
        int cnt = 0 ;
        rep(i,n){
            if(i == n-1) continue;
            if(A[i] != -1) cnt++ ;
            if(cnt == l){
                if(A[i+1] == -1){
                    B[A[i]] = i + 1 ;
                    swap(A[i],A[i+1]) ;
                }
                break ;
            }
        }
    }
    rep(i,k) cout << B[i] + 1 << " " ; cout << endl ;
}