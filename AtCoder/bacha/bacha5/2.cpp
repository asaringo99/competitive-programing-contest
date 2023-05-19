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

int main(){
    fast_input_output
    int s = 1 ;
    int y = 1 , x = 1 , cnt = 0 ;
    bool ok = false ;
    while(y <= 1500){
        while(x + s <= 1500){
            if(x + s > 1500) break ;
            cout << x << " " << y << endl ;
            x += s ;
            s++ ;
            x += s ;
            y++ ;
            cnt++ ;
            if(cnt == 100) {
                ok = true ;
                break;
            }
        }
        if(ok) break ;
        x = s ;
        y += s ;
        y += s ;
    }
}