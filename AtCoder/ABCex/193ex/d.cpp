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

ll powll(ll x , ll n){
    ll res = 1 ;
    while(n > 0){
        if(n & 1) res *= x ;
        x *= x ;
        n >>= 1 ;
    }
    return res ;
}

int n ;
string S , T ;
unordered_map<int,int> mp ;

int main(){
    cin >> n >> S >> T ;
    rep(i,4) mp[S[i]-'0']-- ;
    rep(i,4) mp[T[i]-'0']-- ;
    rrep(i,1,10) mp[i] += n ;
    ld p = 0 ;
    rrep(s,1,10){
        ll sums = 0 ;
        bool ok = false ;
        rrep(i,1,10){
            if(i == s && mp[s] == 0){
                ok = true ;
                break ;
            }
            if(i == s) mp[s]-- ;
            sums += i * powll(10,abs(n-mp[i])) ;
            cout << sums << " " ;
        }
        cout << endl ;
        if(ok) continue ;
        ld ps = (ld)mp[s] / (9 * n - 8) , pt = 0 ;
        rrep(t,1,10){
            ll sumt = 0 ;
            bool gd = false ;
            rrep(i,1,10){
                if(i == t && mp[t] == 0){
                    gd = true ;
                    break ;
                }
                sumt += i * powll(10,abs(n-mp[i])) ;
                if(i == t) mp[t]-- ;
            }
            if(gd) continue ;
            cout << s << " " << t << " " << sums << " " << sumt << endl ;
            if(sums > sumt) pt += (ld)mp[t] / (9 * n - 9) ;
            mp[t]++ ;
        }
        p += ps * pt ;
        mp[s]++ ;
        cout << ps << " " << pt << endl ;
    }
    cout << fixed << setprecision(20) << p << endl ;
}