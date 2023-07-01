#include <bits/stdc++.h>
using namespace std ;

class UsefulString {
    string value;

    string swapIndex(int i, int j, string str) {
        string exchangedIndexString = str;
        swap(exchangedIndexString[i], exchangedIndexString[j]);
        return exchangedIndexString;
    }

    public:
        UsefulString(string input): value(input) {}
        UsefulString exchangeIndex(int i, int j) {
            string afterValue = swapIndex(i,j,value);
            return UsefulString(afterValue);
        }
        string getValue() {
            return value;
        }
};

void solve(){
    UsefulString s("hello");
    auto t = s.exchangeIndex(0,2);
    cout << t.getValue() << endl;
}

int main(){
    solve();
}