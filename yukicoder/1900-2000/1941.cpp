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

string S1 ,S2 , S3 ;

int main(){
    fast_input_output
    cin >> S1 >> S2 >> S3 ;
    string T1 = "#.#" ;
    string T2 = ".#." ;
    if(S1 == T1 && S2 == T2 && S3 == T1) cout << "Yes" << endl ;
    else if(S1 == T2 && S2 == T1 && S3 == T2) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}