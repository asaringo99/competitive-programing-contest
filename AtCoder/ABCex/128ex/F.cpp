#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)1e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;
ll s[MAX_N] ;

int main(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++) cin >> s[i] ;
    ll res = 0 ;
    for(int c = 1 ; c < n ; c++){
        map<int,bool> rem ;
        ll val = 0 ;
        for(int x = 0 ; x < n / c ; x++){
            // cout << c << " " << x << " " << val << endl ;
            if(n - 1 - x * c <= c) break ;
            if(rem[c * x] || rem[n - 1 - c * x] || c * x == n - 1 - c * x) break ;
            rem[c * x] = true ;
            rem[n - 1 - c * x] = true ;
            val += s[c * x] ;
            val += s[n - 1 - c * x] ;
            res = max(res,val) ;
        }
    }
    cout << res << endl ;
}