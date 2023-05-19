#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const int mod = 1000000007 ;

int n , k ;
ll dp[101][101010] ;
set<ll> st ;
vector<ll> vec ;
map<ll,ll> mp , conv , rev ;

int main(){
    cin >> n >> k ;
    for(ll i = 1 ; i * i <= n ; i++){
        mp[i] = n / i ;
        mp[n / i] = i ;
        st.insert(i) ;
        st.insert(n/i) ;
    }
    vec.push_back(0) ;
    int count = 1 ;
    for(ll u : st) {
        conv[count] = u ;
        rev[u] = count ;
        vec.push_back(u) ;
        count++ ;
    }
    rrep(i,1,count) dp[0][i] = vec[i] - vec[i-1] ;
    rep(i,k){
        ll S[101010] ;
        memset(S,0,sizeof(S)) ;
        rrep(j,1,count){
            S[j+1] = S[j] + dp[i][j] ;
        }
        rrep(j,1,count){
            ll v = conv[j] ;
            ll u = mp[v] ;
            ll r = rev[u] ;
            dp[i+1][j] += S[r+1] * (conv[j] - conv[j-1]) % mod ;
            dp[i+1][r] %= mod ;
        }
    }
    ll res = 0 ;
    rep(i,count) (res += dp[k-1][i]) %= mod ;
    cout << res << endl ;
}