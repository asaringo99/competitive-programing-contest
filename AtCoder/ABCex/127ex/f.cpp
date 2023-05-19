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

priority_queue<ll> lef ;
priority_queue<ll,vector<ll>,greater<ll>> rig ;
int q ;

int main(){
    cin >> q ;
    ll sum = 0 ;
    rep(i,q){
        int t ;
        cin >> t ;
        if(t == 1){
            ll a , b ;
            cin >> a >> b ;
            lef.push(a) ;
            rig.push(a) ;
            ll x = lef.top() ; lef.pop() ;
            ll y = rig.top() ; rig.pop() ;
            lef.push(y) ; rig.push(x) ;
            sum += abs(y - x) + b ;
        }
        if(t == 2){
            cout << lef.top() << " " << sum << endl ;
        }
    }
}