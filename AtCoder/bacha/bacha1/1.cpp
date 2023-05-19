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
int R[3030] ;
int dp[3030][3030] ;

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> R[i] ;
    if(n < 3){
        cout << 0 << endl ;
        return 0 ;
    }
    vector<int> res = {R[0]} ;
    int check = 0 ;
    rrep(i,1,n){
        int m = res.size() ;
        m-- ;
        if(res[m] < R[i] && check != 1){
            res.push_back(R[i]) ;
            check = 1 ;
        }
        else if(res[m] < R[i] && check == 1){
            res.pop_back() ;
            res.push_back(R[i]) ;
            check = 1 ;
        }
        else if(res[m] > R[i] && check != -1){
            res.push_back(R[i]) ;
            check = -1 ;
        }
        else if(res[m] > R[i] && check == -1){
            res.pop_back() ;
            res.push_back(R[i]) ;
            check = -1 ;
        }
    }
    if(res.size() < 3) cout << 0 << endl;
    else cout << res.size() << endl ;
}