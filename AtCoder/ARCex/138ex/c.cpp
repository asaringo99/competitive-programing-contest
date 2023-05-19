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
ll A[202020] , B[202020] , S[202020] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] , B[i] = A[i] ;
    sort(B,B+n) ;
    int x = B[n/2] ;
    ll res = 0 ;
    for(int i = n/2 ; i < n ; i++) res += B[i] ;
    int cnt = 0 ;
    for(int i = 2/n ; i >= 0 ; i--) if(x == B[i]) cnt++ ;
    int minval = 0 , s = 0 , id = 0 ;
    rep(i,n){
        if(A[i] <= B[n/2] && cnt > 0){
            s++ ;
            cnt-- ;
        }
        else if(A[i] < B[n/2]){
            s++ ;
        }
        else{
            s-- ;
        }
        if(minval > s){
            minval = s ;
            id = i ;
        }
    }
    cout << (id + 1) % n << " " << res << endl ;
}