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
int A[505050] ;
int B[505050] ;
vector<int> C ;

int main(){
    fast_input_output
    cin >> n ;
    rrep(i,1,n+1) {
        int a ;
        cin >> a ;
        A[i] = a ;
        B[a] = i ;
        if(i == a) C.push_back(i) ;
    }
    ll k = C.size() ;
    ll res = k * (k - 1) / 2 ;
    rrep(i,1,n+1){
        if(B[i] == 0) continue;
        int a = A[i] ;
        if(a <= i) continue;
        int b = A[a] ;
        if(b == i) res++ ;
    }
    cout << res << endl ;
}