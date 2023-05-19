#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ld,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define endl "\n"

struct F{
    ll a , b;
    F(int a_, int b_): a(a_), b(b_) {}
    bool operator< (const F& x) const {
        return a * x.b > b * x.a ;
    }
    bool operator> (const F& x) const {
        return b * x.a < a * x.b ;
    }
};

int m, k;

priority_queue<F,vector<F>,greater<F>> que ;
map<F,bool> used ;

int main(){
    fast_input_output
    cin >> m >> k ;
    
    rrep(i,2,m+1) que.push(F(1,i)) ;
    
    while(!que.empty() && k > 0){
        F f = que.top() ; que.pop() ;
        if(used[f]) continue;
        used[f] = true ;
        k-- ;
        if(k == 0){
            cout << f.a << " " << f.b << endl ;
            return 0 ;
        }
        if(f.a + 1 == f.b) continue;
        ll x = f.a + 1 ;
        while(x != f.b){
            int g = gcd(x,f.b) ;
            if(g == 1){
                que.push(F(x/g,f.b)) ;
                break ;
            }
            x++ ;
        }
    }
    cout << -1 << endl ;
}