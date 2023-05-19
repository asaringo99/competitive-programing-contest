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
vector<int> T[101010] ;
priority_queue<ll,vector<ll>,greater<ll>> que1 , que2 ;

int main(){
    fast_input_output
    cin >> n >> k ;
    rep(i,n){
        int t , d ;
        cin >> t >> d ;
        t-- ;
        T[t].push_back(d) ;
    }
    ll sum = 0 ;
    rep(i,n) {
        sort(T[i].begin(),T[i].end(),greater<ll>()) ;
        int m = T[i].size() ;
        if(m > 0){
            que1.push(T[i][0]) ;
            rrep(j,1,m) que2.push(T[i][j]) , sum += T[i][j] ;
            sum += T[i][0] ;
        }
    }
    que2.push(1000000000000000000LL) ;
    sum += (ll)que1.size() * (ll)que1.size() ;
    int m = n - k ;
    while(m > 0){
        ll top1 = que1.top() , top2 = que2.top() ;
        ll s = que1.size() , t = s - 1 ;
        top1 += s * s - t * t ;
        if(top1 < top2){
            que1.pop() ;
            sum -= top1 ;
        }
        else{
            que2.pop() ;
            sum -= top2 ;
        }
        m-- ;
    }
    cout << sum << endl ;
}