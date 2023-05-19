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
int A[101010] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    sort(A,A+n) ;
    if(A[n-1] - A[0] > 1){
        cout << "No" << endl ;
        return 0 ;
    }
    if(A[0] == A[n-1]){
        if(n / A[0] > 1) cout << "Yes" << endl ;
        else cout << "No" << endl ;
        return 0 ;
    }
    int a = A[0] , id = -1 ;
    rep(i,n){
        if(A[i] == a) id = i + 1 ;
    }
    if(id > a) cout << "No" << endl;
    else cout << "Yes" << endl ;
}