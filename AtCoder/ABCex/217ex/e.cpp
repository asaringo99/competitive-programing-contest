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

int q ;
priority_queue<ll,vector<ll>,greater<ll>> pque ;
queue<ll> que ;

int main(){
    cin >> q ;
    int s = 0 ;
    rep(i,q){
        int t ;
        cin >> t ;
        if(t == 1){
            ll x ;
            cin >> x ;
            que.push(x) ;
        }
        if(t == 2){
            if(pque.empty()) {
                cout << que.front() << endl ;
                que.pop() ;
            }
            else{
                cout << pque.top() << endl ;
                pque.pop() ;
            }
        }
        if(t == 3) {
            while(!que.empty()) pque.push(que.front()) , que.pop() ;
        }
    }
}