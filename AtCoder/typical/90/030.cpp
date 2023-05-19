#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;

int is_prime[10000007] ;

void ertstns(){
    memset(is_prime,0,sizeof(is_prime)) ;
    for(int i = 2 ; i <= n ; i++){
        if(is_prime[i] == 0){
            for(int j = i ; j <= n ; j += i) is_prime[j]++ ;
        }
    }
}

int main(){
    cin >> n >> k ;
    ertstns() ;
    int res = 0 ;
    for(int i = 2 ; i <= n ; i++){
        if(is_prime[i] >= k) res++ ;
    }
    cout << res << endl ;
}