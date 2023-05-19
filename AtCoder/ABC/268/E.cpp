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
int A[202020], B[202020], C[202020];

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i];
    ll res = 0, ans = 1e18;
    if(n % 2 == 0){
        priority_queue<int,vector<int>,greater<int>> que1, que2;
        rep(i,n){
            int b = min(abs(A[i]-i),abs(n-abs(A[i]-i))%n);
            int c = (A[i] - i + n) % n;
            res += b;

            if(c <= n / 2){
                que1.push(b);
            }
            else{
                que2.push(n/2-b);
            }
        }
        chmin(ans,res);
        rep(i,n){
            while(!que1.empty()){
                int v = que1.top();
                if(v != i) break;
                que1.pop();
                que2.push(i+n/2);
            }
            while(!que2.empty()){
                int v = que2.top();
                if(v != i) break;
                que2.pop();
                que1.push(i+n/2);
            }
            res += que2.size() - que1.size();
            chmin(ans,res);
        }
        cout << ans << endl;
        return 0;
    }
    
    priority_queue<int,vector<int>,greater<int>> que1, que2;
    rep(i,n){
        int b = min(abs(A[i]-i),abs(n-abs(A[i]-i)));
        int c = (A[i] - i + n) % n;
        res += b;

        if(c <= n / 2){
            que1.push(b);
        }
        else{
            que2.push(n/2-b);
        }
    }
    chmin(ans,res);
    rep(i,n){
        while(!que1.empty()){
            int v = que1.top();
            if(v != i) break;
            que1.pop();
            que2.push(i+n/2);
        }
        res -= que1.size();
        while(!que2.empty()){
            int v = que2.top();
            if(v != i) break;
            que2.pop();
            que1.push(i+n/2+1);
        }
        res += que2.size();
        chmin(ans,res);
    }
    cout << ans << endl;
}