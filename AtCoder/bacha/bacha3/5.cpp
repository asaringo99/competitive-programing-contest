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

int t ;

void solve(){
    int n;
    cin >> n;
    vector<int> A(n) , B(n) ;
    rep(i,n) {
        cin >> A[i] ;
        A[i]-- ;
        B[i] = i ;
    }
    int cnt = 0 ;
    vector<int> res ;
    rep(i,n-2){
        bool ok = true ;
        rep(j,n) if(A[j] != B[j]) ok = false ;
        if(ok) break ;
        if(i == A[i]) continue ;
        int k ;
        rep(j,n) if(i == A[j]) k = j ;
        if(k % 2 == cnt % 2){
            if(k + 1 != n){
                swap(A[k],A[k+1]) ;
                swap(A[k-1],A[k]) ;
                res.push_back(k) ;
                res.push_back(k-1) ;
                cnt += 2 ;
                k++ ;
            }
            else{
                swap(A[k-2],A[k-1]) ;
                res.push_back(k-2) ;
                cnt++ ;
            }
        }
        while(k != i){
            k-- ;
            swap(A[k],A[k+1]) ;
            res.push_back(k) ;
            cnt++ ;
        }
    }
    if(A[n-2] != B[n-2] || A[n-1] != B[n-1]){
        if(cnt % 2 == (n - 2) % 2) res.push_back(n-2) ;
        else{
            res.push_back(n-3) ;
            res.push_back(n-2) ;
            res.push_back(n-3) ;
            res.push_back(n-2) ;
            res.push_back(n-3) ;
        }
    }
    cout << res.size() << endl ;
    for(int u : res) cout << u + 1 << " " ; cout << endl;
}

int main(){
    fast_input_output
    cin >> t ;
    rep(i,t) solve() ;
}