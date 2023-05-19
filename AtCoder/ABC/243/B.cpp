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
int A[1010] ;
int B[1010] ;
map<int,int> mp ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i] , mp[A[i]]++ ;
    rep(i,n) cin >> B[i] , mp[B[i]]++ ;
    int count = 0 ;
    rep(i,n) if(A[i] == B[i]) count++ ;
    cout << count << endl ;
    int sum = 0 ;
    for(auto it : mp) if(it.second > 1) sum++ ;
    cout << sum - count << endl ;
}