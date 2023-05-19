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

ll n , m ;
ll X[101010] , Y[101010] ;
map<ll,bool> mp_p , mp_n ;
vector<ll> odd , eve ;
vector<int> vec ;

int main(){
    fast_input_output
    cin >> n >> m ;
    n-- ;
    ll res = 0 ;
    rep(i,m) {
        ll x , y ;
        cin >> x >> y ;
        x-- ; y-- ;
        X[i] = x ;
        Y[i] = y ;
        // pos
        if(!mp_p[y-x]){
            res += n - abs(y-x) + 1 ;
            mp_p[y-x] = true ;
            if((y+x)%2==0) eve.push_back(y-x) ;
            if((y+x)%2==1) odd.push_back(y-x) ;
        }
        if(!mp_n[y+x]){
            vec.push_back(i) ;
            mp_n[y+x] = true ;
        }
    }
    sort(eve.begin(),eve.end()) ;
    sort(odd.begin(),odd.end()) ;
    for(int i : vec){
        ll x = X[i] , y = Y[i] ;
        ll cnt = min(x+y,2*n-x-y) + 1 ;
        if((x+y)%2==0){
            if(x+y<n){
                ll sum = upper_bound(eve.begin(),eve.end(),x+y) - lower_bound(eve.begin(),eve.end(),-x-y) ;
                res += cnt - sum ;
            }
            else{
                ll sum = upper_bound(eve.begin(),eve.end(),-x-y+2*n) - lower_bound(eve.begin(),eve.end(),x+y-2*n) ;
                res += cnt - sum ;
            }
        }
        if((x+y)%2==1){
            if(x+y<n){
                ll sum = upper_bound(odd.begin(),odd.end(),x+y) - lower_bound(odd.begin(),odd.end(),-x-y) ;
                res += cnt - sum ;
            }
            else{
                ll sum = upper_bound(odd.begin(),odd.end(),-x-y+2*n) - lower_bound(odd.begin(),odd.end(),x+y-2*n) ;
                res += cnt - sum ;
            }
        }
    }
    cout << res << endl ;
}