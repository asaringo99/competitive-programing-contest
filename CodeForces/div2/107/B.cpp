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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

void solve(){
    int n;
    cin >> n;
    vector<string> S(n);
    vector<vector<int>> phone(n,vector<int>(3,0));
    int num_girl = 0, num_taxi = 0, num_pizza = 0;
    rep(i,n){
        int k;
        string T;
        cin >> k >> T;
        S[i] = T;
        rep(j,k){
            string V;
            cin >> V;
            bool girl = true;
            set<int> st;
            for(char u : V) st.insert(u);
            if(st.size() == 2){
                phone[i][0]++;
                girl = false;
            }
            bool ok = true;
            int num = 10;
            for(char u : V){
                if(u == '-') continue;
                int val = u - '0';
                if(val >= num) ok = false;
                num = val;
            }
            if(ok) {
                phone[i][1]++;
                girl = false;
            }
            if(girl){
                phone[i][2]++;
            }
        }
        chmax(num_taxi,phone[i][0]);
        chmax(num_pizza,phone[i][1]);
        chmax(num_girl,phone[i][2]);
    }
    vector<string> Taxi, Pizza, Girl;
    rep(i,n){
        if(phone[i][0] == num_taxi) Taxi.push_back(S[i]);
        if(phone[i][1] == num_pizza) Pizza.push_back(S[i]);
        if(phone[i][2] == num_girl) Girl.push_back(S[i]);
    }
    cout << "If you want to call a taxi, you should call: ";
    rep(i,Taxi.size()){
        cout << Taxi[i];
        if(i == Taxi.size()-1){
            cout << '.' << endl;
        }
        else{
            cout << ", ";
        }
    }
    cout << "If you want to order a pizza, you should call: ";
    rep(i,Pizza.size()){
        cout << Pizza[i];
        if(i == Pizza.size()-1){
            cout << '.' << endl;
        }
        else{
            cout << ", ";
        }
    }
    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    rep(i,Girl.size()){
        cout << Girl[i];
        if(i == Girl.size()-1){
            cout << '.' << endl;
        }
        else{
            cout << ", ";
        }
    }
}

int main(){
    fast_io
    solve();
}