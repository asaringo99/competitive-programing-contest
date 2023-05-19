#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,char> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , q ;
vector<P> vec ;
string S ;

int main(){
    fast_input_output
    cin >> n >> q >> S ;
    int c = 0 ;
    ll sum = 0 ;
    int p = 0 ;
    int s = 0 ;
    int g = n - 1 ;
    rep(i,q){
        int t , x ;
        cin >> t >> x ;
        // cout << s << " " << g << endl ;
        if(t == 1){
            s = g - x + 1 ;
            (s += n) %= n ;
            g = (s - 1 + n) % n ;
        }
        else{
            int id = s + x - 1 ;
            id += n ;
            id %= n ;
            cout << S[id] << endl ;
        }
    }
}