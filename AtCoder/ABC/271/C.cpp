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
#define endl "\n"

int n ;
vector<ll> A;
set<int> st;

int main(){
    fast_input_output
    int rem = 0;
    cin >> n ;
    rep(i,n) {
        int a;
        cin >> a;
        if(st.count(a)) rem++;
        else A.push_back(a);
        st.insert(a);
    }
    sort(A.begin(),A.end());
    int m = A.size();
    int read = 0;
    int fin = A.size();
    rep(i,m){
        if(A[i] - read == 1){
            read = A[i];
            continue;
        }
        ll r = A[i] - read - 1;
        r *= 2;
        if(rem >= r){
            rem -= r;
            read = A[i];
        }
        else{
            r -= rem;
            rem = 0;
            if(fin - r <= i) {
                read += (fin - i - 1) / 2;
                break;
            }
            read = A[i];
            fin -= r;
        }
    }
    read += rem / 2;
    cout << read << endl;
}