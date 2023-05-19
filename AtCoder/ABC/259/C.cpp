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

string S , T ;
int n , m ;

int main(){
    fast_input_output
    cin >> S >> T ;
    n = S.size() ;
    m = T.size() ;
    string s = "" , t = "" ;
    s += S[0] ;
    s += S[1] ;
    rrep(i,2,n){
        char u = S[i] ;
        int nn = s.size() ;
        if(s[nn-1] == u && s[nn-2] == u) continue;
        s += u ;
    }
    t += T[0] ;
    t += T[1] ;
    rrep(i,2,m){
        char u = T[i] ;
        int mm = t.size() ;
        if(t[mm-1] == u && t[mm-2] == u) continue;
        t += u ;
    }
    cout << s << endl ;
    cout << t << endl ;
    if(s != t) cout << "No" << endl ;
    else cout << "Yes" << endl ;
}