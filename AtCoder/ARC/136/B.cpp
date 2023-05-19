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
int A[5050] , B[5050] , C[5050] ;
int X[5050] , Y[5050] ;

void f(int i , int j , int k){
    int x = B[i] , y = B[j] , z = B[k] ;
    B[i] = z ;
    B[j] = x ;
    B[k] = y ;
}

int main(){
    cin >> n ;
    rep(i,n) {
        cin >> A[i] ;
        X[A[i]]++ ;
    }
    rep(i,n) {
        cin >> B[i] ;
        Y[B[i]]++ ;
    }
    rep(i,5001) if(X[i] != Y[i]){
        cout << "No" << endl ;
        return 0 ;
    }
    rep(i,5001){
        if(X[i] > 1){
            cout << "Yes" << endl ;
            return 0 ;
        }
    }
    rep(i,n-3){
        int id = -1 ;
        rrep(j,i,n) if(B[j] == A[i]){
            id = j ;
            break ;
        }
        while(i < id - 2){
            f(id-2,id-1,id) ;
            id -= 2 ;
        }
        while(B[i] != A[i]){
            f(i,i+1,i+2) ;
        }
        // rep(i,n) cout << B[i] << " " ; cout << endl ;
    }
    bool ok = false ;
    int count = 10 ;
    while(count > 0){
        f(n-3,n-2,n-1) ;
        if(A[n-3] == B[n-3] && A[n-2] == B[n-2] && A[n-1] == B[n-1]) ok = true ;
        count-- ;
    }
    if(ok) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}