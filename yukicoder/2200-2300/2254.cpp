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


// kmp をやるための前計算
vector<int> makeTable(const vector<int> s) {
    int n = s.size();
    vector<int> ret(n+1);
    ret[0] = -1;
    int j = -1;
    for(int i = 0 ; i < n ; i++){
        while(j >= 0 && s[i] != s[j]) j = ret[j] ;
        j++ ;
        ret[i+1] = j ;
    }
    return ret;
}

// str の中に word とマッチする場所のリストを返す
// ret のそれぞれの要素 el は, 「str[el] からの文字列が word と一致する」ことを示す
vector<int> kmp(const vector<int> str, const vector<int> word) {
    vector<int> table = makeTable(word), ret;
    int m = 0, i = 0, n = str.size();
    while (m+i < n) {
        if (word[i] == str[m+i]) {
            if (++i == (int)(word.size())) {
                ret.push_back(m);
                m = m+i-table[i];
                i = table[i];
            }
        }
        else {
            m = m+i-table[i];
            if (i > 0) i = table[i];
        }
    }
    return ret;
}

int n, k;

int main(){
    fast_input_output
    cin >> n >> k;
    multiset<int> S, T;
    vector<int> A(n), B(n);
    map<int,int> mp;
    rep(i,n){
        cin >> A[i];
        S.insert(A[i]);
        if(mp.count(A[i]) == 0) mp[A[i]] = i; 
        A[i] = mp[A[i]];
    }
    rep(i,n){
        cin >> B[i];
        T.insert(B[i]);
        B[i] = mp[B[i]];
    }
    if(S != T){
        cout << "No" << endl;
        return 0;
    }
    if(A == B){
        cout << "Yes" << endl;
        return 0;
    }
    if(n > k + 1 || k == 2){
        cout << "Yes" << endl;
        return 0;
    }
    if(S.size() != A.size())
    if(k == 1){
        cout << "No" << endl;
        return 0;
    }
    rep(i,n) B.push_back(B[i]);
    if(kmp(B,A).size() > 0){
        cout << "Yes" << endl;
        return 0;
    }
    reverse(all(B));
    if(kmp(B,A).size() > 0){
        cout << "Yes" << endl;
        return 0;
    }
    else cout << "No" << endl;
}