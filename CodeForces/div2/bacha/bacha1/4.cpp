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
#define input(a) cin >> a
#define print(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl

int zzz ;
int n , q ;

void solve(){
    cin >> n >> q ;
    vector<int> A ;
    vector<bool> used(n,false) ;
    A.resize(n) ;
    rep(i,n) cin >> A[i] ;
    int res = 0 , sum = 0 , b = 0 ;
    // 違反量
    priority_queue<P,vector<P>,greater<P>> que ;
    queue<int> Q ;
    rep(i,n){
        if(q == 0){
            while(!Q.empty()){
                int v = Q.front() ; Q.pop() ;
                if(!used[v]){
                    used[v] = true ;
                    b++ ;
                    q++ ;
                    sum-- ;
                    break ;
                }
            }
            while(!que.empty()){
                auto [mag,v] = que.top() ;
                if(used[v]) {
                    que.pop() ;
                    continue;
                }
                if(mag > b) break ;
                used[v] = true ;
                que.pop() ;
                b++ ;
                q++ ;
            }
        }
        if(A[i] > q){
            Q.push(i) ;
            que.push(P(A[i]-q,i)) ;
            q-- ;
            sum++ ;
        }
        else{

        }
    }
}

int main(){
    fast_input_output
    cin >> zzz ;
    rep(i,zzz) solve() ;
}