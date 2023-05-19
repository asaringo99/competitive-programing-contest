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

int n , k ;
int T[202020] , Y[202020] ;

priority_queue<ll> que ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n) cin >> T[i] >> Y[i] ;
    
    ll sum = 0 , res = -1e16 ;
    for(int i = n - 1 ; i >= 0 ; i--){
        if(i == 0 || T[i] == 1){
            while((int)que.size() > k){
                sum += que.top() ;
                que.pop() ;
            }
            chmax(res,sum+Y[i]) ;
            k-- ;
        }
        else{
            if(Y[i] >= 0) sum += Y[i] ;
            else que.push(Y[i]) ;
        }
        if(k < 0) break ;
    }
    cout << res << endl ;
}