#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

//セグメント木

const int MAX_N = 1 << 17 ;

int n ;
int dat[2 * MAX_N - 1] , A[MAX_N] ;

int gcd(int a , int b){
    if(b == 0) return a ;
    return gcd(b , a % b) ;
}

void init(int N){
    n = 1 ;
    while(n < N) n *= 2 ;
    memset(dat,0,sizeof(dat)) ;
    for(int i = 0 ; i < N ; i++) dat[i + n - 1] = A[i] ;
    for(int i = n - 2 ; i >= 0 ; i--) dat[i] = gcd(dat[2*i+1],dat[2*i+2]) ;
}

int query(int a , int b , int k , int l , int r){
    if(r <= a || b <= l) return dat[k] ;
    if(l == a && r == b) return 0 ;
    int lgcd = query(a,b,2*k+1,l,(l+r)/2) ;
    int rgcd = query(a,b,2*k+2,(l+r)/2,r) ;
    return gcd(lgcd,rgcd) ;
}

int main(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++) cin >> A[i] ;
    init(n) ;
    int res = 0 ;
    for(int i = 0 ; i < n ; i++){
        res = max(res,query(i,i+1,0,0,n)) ;
    }
    cout << res << endl ;
}