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
ll A[1 << 18] ;
multiset<int> st ;

int main(){
    fast_input_output
    cin >> n ;
    priority_queue<ll> que ;

    rep(i,1<<n) cin >> A[i] , st.insert(A[i]) ;
    auto ite = st.end() ; ite-- ;
    int val = *ite ; st.erase(ite) ;
    que.push(val) ;
    rrep(i,1,n+1){
        priority_queue<ll> que2 ;
        while(!que.empty()){
            ll x = que.top() ; que.pop() ;
            auto it = st.lower_bound(x) ;
            if(it == st.begin()){
                cout << "No" << endl ;
                return 0 ;
            }
            it-- ;
            que2.push(x) ;
            que2.push(*it) ;
            st.erase(it) ;
        }
        while(!que2.empty()) que.push(que2.top()) , que2.pop() ;
    }
    cout << "Yes" << endl ;
}