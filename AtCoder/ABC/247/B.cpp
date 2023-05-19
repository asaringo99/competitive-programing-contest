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
map<string,int> mp ;
string S[101] , T[101] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n){
        cin >> S[i] >> T[i] ;
        mp[S[i]]++ ;
        mp[T[i]]++ ;
    }
    bool ok = true ;
    rep(i,n){
        if(S[i] == T[i]) {
            if(mp[S[i]] != 2) ok = false ;
        }
        else if(mp[S[i]] != 1 && mp[T[i]] != 1) {
            ok = false ;
        }
    }
    if(ok) cout << "yes" << endl ;
    else cout << "No" << endl ;
}