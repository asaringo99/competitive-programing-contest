#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int n ;

const int MAX_N = 2e5 + 7 ;

int is_prime[MAX_N] ;

void suretsu(int n){
    fill(is_prime,is_prime+n+1,2) ;
    int prime_count = 2 ;
    is_prime[1] = 1 ;
    for(int i = 2 ; i <= n ; i++){
        int count = is_prime[i] ;
        for(int j = i * 2 ; j <= n ; j += i) is_prime[j] = is_prime[i] + 1 ;
    }
}

int main(){
    cin >> n ;
    suretsu(n) ;
    for(int i = 1 ; i <= n ; i++){
        cout << is_prime[i] << " " ;
    }
    cout << endl ;
}