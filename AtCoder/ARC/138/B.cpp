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
int A[202020] , B[202020] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) B[i] = A[i] == 1 ? 0 : 1 ;
    if(A[0] == 1){
        cout << "No" << endl ;
        return 0 ;
    }
    if(n == 1) if(A[0] == 0) cout << "Yes" << endl ;
    
    bool ok = false ;
    if(A[0] == 0 && A[1] == 0) ok = true ;
    rrep(i,2,n){
        if(A[i] == 1){
            if(ok) {
                cout << "No" << endl ;
                return 0 ;
            }
        }
    }
    int cnt = 0 , sum = 0 , st = -1 ;
    for(int i = 0 ; i < n ; i+=1){
        if(A[i] == 0 && A[i+1] == 1) cnt++ ;
        if(A[i] == 1 && A[i+1] == 0) cnt++ ;
        else break ;
    }
    int b = -1 ;
    rep(i,n){
        if(b == 0 && A[i] == 1) sum++ ;
        if(b == 1 && A[i] == 0) sum++ ;
        b = A[i] ;
    }
    if(A[n-1] == 0) sum-- ;
    if(cnt * 2 >= sum) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}