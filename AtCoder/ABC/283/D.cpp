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

string S;
int n;
int T[30];
vector<vector<char>> vec;

int main(){
    fast_input_output
    cin >> S;
    n = S.size();
    int s = 0;
    vec.push_back({});
    rep(i,n){
        if(S[i] == '('){
            vector<char> V = {};
            vec.push_back(V);
        }
        else if(S[i] == ')'){
            vector<char> V = vec[vec.size() - 1];
            vec.pop_back();
            for(char u : V){
                T[u-'a']--;
            }
        }
        else{
            char c = S[i];
            if(T[c-'a'] > 0){
                cout << "No" << endl;
                return 0;
            }
            vec[vec.size() - 1].push_back(c);
            T[c-'a']++;
        }
    }
    cout << "Yes" << endl;
}