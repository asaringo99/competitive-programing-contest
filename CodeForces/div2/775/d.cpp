#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> A(n), S(3*k+1);
    vector<bool> B(k+1,false), C(k+1,false);
    rep(i,n) cin >> A[i], S[A[i]]++, C[A[i]] = true;
    int s = 0;
    rep(i,3*k+1){
        s += S[i];
        S[i] = s;
    }
    sort(all(A));
    if(A[0] != 1){
        cout << "No" << endl;
        return;
    }
    rep(i,n){
        int a = A[i];
        if(a == 1) continue;
        if(B[a]) continue;
        B[a] = true;

        for(int j = 2; j * a <= 2*k; j++){
            if(S[j*a-1] - S[(j-1)*a-1] > 0){
                int d = j - 1;
                if(!C[d]){
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    cout << "Yes" << endl;
}

int main(){
    fast_io
    int z;
    cin >> z;
    rep(i,z) solve();
}