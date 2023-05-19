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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

ll n , L ;
vector<ll> O , E ;
ll X[101010] , Y[101010] ;
map<ll,bool> mp , np ;

int main(){
    cin >> L >> n ;
    L-- ;
    ll res = 0 ;
    rep(i,n){
        ll a , b ;
        cin >> a >> b ;
        X[i] = a ;
        Y[i] = b ;
        if(mp[b-a]) continue;
        mp[b-a] = true ;
        if((a + b) % 2 == 0) E.push_back(b-a) ;
        if((a + b) % 2 != 0) O.push_back(b-a) ;
        if(a > b) swap(a,b) ;
        res += L + a - b + 1 ;
    }
    sort(O.begin(),O.end()) ;
    sort(E.begin(),E.end()) ;
    rep(i,n){
        ll a = X[i] ;
        ll b = Y[i] ;
        if(np[a+b]) continue;
        np[a+b] = true ;
        ll uy = a + b , dy = - (a + b) ;
        if(a + b > L) {
            uy = 2 * L - a - b ;
            dy = a + b - 2 * L ;
        }
        if(a + b > L) res += 2 * L - a - b + 1 ;
        else res += a + b + 1 ; 
        if((a + b) % 2 == 0){
            res -= upper_bound(E.begin(),E.end(),uy) - lower_bound(E.begin(),E.end(),dy) ;
        }
        if((a + b) % 2 != 0){
            res -= upper_bound(O.begin(),O.end(),uy) - lower_bound(O.begin(),O.end(),dy) ;
        }
    }
    cout << res << endl ;
}