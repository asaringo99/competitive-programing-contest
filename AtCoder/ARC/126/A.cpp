#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , t ;

int main(){
    cin >> t ;
    rep(i,t){
        ll a , b , c , res = 0 ;
        cin >> a >> b >> c ;
        b/=2;
        if(b<c){
            c -= b ;
            res += b ;
            ll x = c / 2 ;
            ll y = c % 2 ;
            if(x >= a) res += a;
            else{
                a -= x ;
                res += x ;
                if(y == 1 && a >= 3){
                    res += 1 ;
                    a -= 3 ;
                    a /=5 ;
                    res += a ;
                }
                else{
                    a /= 5 ;
                    res +=a ;
                }
            }
        }
        else{
            b -= c ;
            res += c ;
            if(2 * b >= a){
                a /= 2 ;
                res +=a ;
            }
            else{
                a -= 2 * b ;
                res += b ;
                a /= 5 ;
                res += a ;
            }
        }
        cout << res << endl;
    }
}