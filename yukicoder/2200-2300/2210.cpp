#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

int n, k;
int A[202020], S[202020];
vector<int> vec;

int main(){
    fast_input_output
    cin >> n >> k;
    k--;
    rep(i,n) cin >> A[i];
    for(int i = n - 2; i >= 0; i--){
        if(A[i] == A[i+1]) S[i] = S[i+1];
        else if(A[i] > A[i+1]) S[i] = 1;
        else S[i] = -1;
    }
    vec.resize(n,-1);
    vector<int> R = {n-1};
    int s = 0, g = n - 1;
    rep(i,n-1){
        int t = S[i];
        if(t == 0) R.push_back(i);
        else if(t == 1){
            vec[s] = i;
            s++;
        }
        else{
            vec[g] = i;
            g--;
        }
    }
    rrep(i,s,g+1) vec[i] = R[i-s];
    int skip = vec[k];
    rep(i,n) if(i != skip) cout << A[i] << " "; cout << endl;
}