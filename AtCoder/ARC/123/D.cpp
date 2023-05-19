#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

int main(){
    cin >> n ;
    ll b = -1e15 , c = 1e15 ;
    ll res = 0 ;
    rep(i,n){
        ll a ;
        cin >> a ;
        if(a > 0){
            if(c >= a){
                c = a ;
                res += abs(c) ;
            }
            else{
                ll tmp = max(b,a) ;
                b = tmp ;
                ll pmp = a - b ;
                if(pmp > c) b = a - c ;
                res += abs(b) + abs(c) ;
            }
        }
        else{
            if(b <= a){
                b = a ;
                res += abs(b) ;
            }
            else{
                ll tmp = min(c,a) ;
                c = tmp ;
                ll pmp = a - c ;
                if(pmp < b) c = a - b ;
                res += abs(b) + abs(c) ;
            }
        }
    }
    cout << res << endl ;
}