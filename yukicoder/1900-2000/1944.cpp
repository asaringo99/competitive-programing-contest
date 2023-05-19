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

ld n , x , y ;
int R[202020] ;

int main(){
    fast_input_output
    cin >> n >> x >> y ;
    ld sum = 0 , minval = 1e18 , maxval = 0 ;
    rep(i,n){
        ld r ; 
        cin >> r ;
        sum += 2 * r ;
        chmin(minval,r) ;
        chmax(maxval,r) ;
    }
    if(n == 1){
        sum -= minval ;
        if(abs(x * x + y * y - sum * sum) <= 1e-5) cout << "Yes" << endl ;
        else cout << "No" << endl ;
    }
    if(maxval * maxval > x * x + y * y){
        sum -= 2 * maxval ;
        maxval -= sum ;
        if(maxval <= 0){
            cout << "Yes" << endl ;
            return 0 ;
        }
        sum = maxval ;
        if((x * x + y * y) < sum * sum) cout << "No" << endl ;
        else cout << "Yes" << endl ;
        // if((x * x + y * y) % sum == 0){
        //     if((x * x + y * y) / sum < sum) cout << "No" << endl ;
        //     else cout << "Yes" << endl ;
        // }
        // else{
        //     if((x * x + y * y) / sum >= sum) cout << "Yes" << endl ;
        //     else cout << "No" << endl ;
        // }
    }
    else{
        sum -= minval ;
        if((x * x + y * y) <= sum * sum) cout << "Yes" << endl ;
        else cout << "No" << endl ;
        // if((x * x + y * y) < sum * sum) cout << "No" << endl ;
        // else cout << "Yes" << endl ;
        // if((x * x + y * y) % sum == 0){
        //     if((x * x + y * y) / sum <= sum) cout << "Yes" << endl ;
        //     else cout << "No" << endl ;
        // }
        // else{
        //     if((x * x + y * y) / sum >= sum) cout << "No" << endl ;
        //     else cout << "Yes" << endl ;
        // }
    }
}