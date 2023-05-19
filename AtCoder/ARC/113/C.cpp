#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12
#define a_z "abcdefghijklmnopqrstuvwxyz"

string S ;

int main(){
    cin >> S ;
    reverse(S.begin(),S.end()) ;
    map<char,ll> rem ;
    ll sum = 0 ;
    for(int i = 0 ; i < S.size() - 2 ; i++){
        rem[S[i]]++ ;
        if(S[i+1] == S[i+2]){
            rem[S[i+1]] = 0 ;
            for(char u : a_z){
                sum += rem[u] ;
                rem[u] = 0 ;
            }
            rem[S[i+1]] = i + 1 ;
        }
    }
    cout << sum << endl ;
}