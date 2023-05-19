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

int n ;
char s1 , s2 , s3 , t1 , t2 , t3 ;

int main(){
    cin >> s1 >> s2 >> s3 >> t1 >> t2 >> t3 ;
    if(s1 == t1 && s2 == t2 && s3 == t3) cout << "Yes" << endl ;
    else if(s3 == t1 && s1 == t2 && s2 == t3) cout << "Yes" << endl ;
    else if(s2 == t1 && s3 == t2 && s1 == t3) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}