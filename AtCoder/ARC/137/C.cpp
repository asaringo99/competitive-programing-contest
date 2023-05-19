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
vector<int> A ;

int main(){
    cin >> n ;
    A.push_back(0) ;
    int last = 0 , count = 0 ;
    rep(i,n) {
        int a ;
        cin >> a ;
        if(a - last <= 1) continue ;
        A.push_back(a) ;
        last = a ;
        count++ ;
    }
    n = A.size() ;
    // if(n % 2 == 1) A.push_back(0) , n++ ;
    // sort(A.begin(),A.end()) ;
    // int val = 0 ;
    // for(int i = 0 ; i + 1 < n ; i += 2){
    //     val ^= (A[i+1] - A[i] - 1) ;
    // }
    if(count % 2 == 0 && count > 0) cout << "Alice" << endl ;
    else cout << "Bob" << endl ;
}