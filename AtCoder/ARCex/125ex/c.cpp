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

int n, k ;
int A[202020];

int main(){
    // fast_input_output
    cin >> n >> k ;
    set<int> st;
    rrep(i,1,n+1) st.insert(i);
    rep(i,k){
        cin >> A[i];
        st.erase(A[i]);
    }
    rep(i,k+1){
        if(i == k){
            while(!st.empty()){
                auto it = st.end(); it--;
                cout << *it << " ";
                st.erase(it);
            }
            break;
        }
        int a = A[i];
        if(i == k-1){
            while(!st.empty()){
                auto it = st.end(); it--;
                if(*it < a) break;
                cout << *it << " ";
                st.erase(it);
            }
        }
        cout << a << " ";
        if(!st.empty() && *(st.begin()) < a && i < k - 1){
            cout << *(st.begin()) << " ";
            st.erase(st.begin());
        }
    }
    cout << endl;
}