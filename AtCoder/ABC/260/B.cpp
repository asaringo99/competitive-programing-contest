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

string S ;

int main(){
    fast_input_output
    cin >> S ;
    if(S[0] == S[1] && S[1] == S[2]){
        cout << -1 << endl ;
        return 0 ;
    }
    if(S[0] == S[1]){
        cout << S[2] << endl ;
        return 0 ;
    }
    if(S[1] == S[2]){
        cout << S[0] << endl ;
        return 0 ;
    }
    if(S[0] == S[2]){
        cout << S[1] << endl ;
        return 0 ;
    }
    cout << S[0] << endl ;
}