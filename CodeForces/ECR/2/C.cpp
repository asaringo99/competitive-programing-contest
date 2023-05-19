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
    string S;
    cin >> S;
    int n = S.size();
    int cnt = 0;
    vector<int> A(26,0);
    rep(i,n) A[S[i] - 'a']++;
    vector<int> C;
    rep(i,26) if(A[i] % 2 == 1) C.push_back(i);
    string X = "";
    string Y = "";
    if(C.size() == 1){
        int k = -1;
        rep(i,26){
            while(A[i] > 0){
                if(A[i] == 1){
                    k = i;
                    break;
                }
                X += (char)('a' + i);
                Y += (char)('a' + i);
                A[i] -= 2;
            }
        }
        reverse(all(Y));
        X += (char)('a'+k);
        cout << X << Y << endl;
        return;
    }
    rep(i,C.size()){
        C[C.size()-1-i] = C[i];
    }
    sort(all(C));
    int k = 0;
    rep(i,26){
        if(k + 2 <= C.size() && C[k] == i){
            X += (char)('a' + i);
            Y += (char)('a' + i);
            k += 2;
        }
        while(A[i] > 0){
            if(A[i] == 1){
                break;
            }
            X += (char)('a' + i);
            Y += (char)('a' + i);
            A[i] -= 2;
        }
    }
    if(k < C.size()) X += (char)('a' + C[k]);
    reverse(all(Y));
    cout << X << Y << endl;
}

int main(){
    fast_io
    solve();
}