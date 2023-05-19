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

int n , k  ;
int X[303] , Y[303] ;

map<P,bool> used ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) cin >> X[i] >> Y[i] ;
    if(k == 1){
        cout << "Infinity" << endl ;
        return 0 ;
    }
    ll res = 0 ;
    rep(i,n) rrep(j,i+1,n){
        int count = 2 ;
        ll dx = X[j] - X[i] ;
        ll dy = Y[j] - Y[i] ;
        // cout << X[j] << " " << X[i] << endl ;
        if(dx < 0) dx *= -1 , dy *= -1 ;
        if(dx == 0 && dy < 0) dy *= -1 ;
        // cout << i << " " << j << endl ;
        ll g = gcd(abs(dx),abs(dy)) ;
        dx/=g ;
        dy/=g ;
        // cout << "d : " <<  dx << " " << dy << endl ;
        if(used[P(i,j)]) continue ;
        used[P(i,j)] = true ;
        vector<int> vec = {i,j} ;
        rrep(k,j+1,n){
            ll dx2 = X[k] - X[i] ;
            ll dy2 = Y[k] - Y[i] ;
            // cout << "e : " << k << " "  << dx2 << " " << dy2 << endl ;
            if(dx2 < 0) dx2 *= -1 , dy2 *= -1 ;
            if(dx2 == 0 && dy2 < 0) dy2 *= -1 ;
            // cout << "e : " << k << " "  << dx2 << " " << dy2 << endl ;
            ll g = gcd(abs(dx2),abs(dy2)) ;
            dx2/=g ;
            dy2/=g ;
            // cout << dx << " " << dx2 << " " << dy << " " << dy2 << endl ;
            if(dx == dx2 && dy == dy2){
                // cout << k << endl ;
                count++ ;
                vec.push_back(k) ;
            }
        }
        if(count >= k) {
            // cout << i << " " << j << endl ;
            res++ ;
        }
        int m = vec.size() ;
        rep(k,m) rrep(l,k+1,m) {
            // cout << "dk : " << k << " " << l << endl ;
            used[P(vec[k],vec[l])] = true ;
        }
    }
    cout << res << endl ;
}