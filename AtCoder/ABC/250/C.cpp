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

int n , q ;
int A[202020] , B[202020] ;

int main(){
    fast_input_output
    cin >> n >> q ;
    rep(i,n) A[i] = i , B[i] = i ;
    rep(i,q){
        int x ;
        cin >> x ;
        x-- ;
        int k = B[x] ;
        if(k != n - 1){
            int a = A[(k+1)%n] ;
            B[a] = k ;
            B[x] = (k + 1) % n ;
            swap(A[k],A[(k+1)%n]) ;
        }
        else{
            int a = A[k-1] ;
            B[a] = k ;
            B[x] = (k - 1) ;
            swap(A[k],A[(k-1)]) ;
        }
    }
    rep(i,n) cout << A[i] + 1 << " " ; cout << endl ;
}