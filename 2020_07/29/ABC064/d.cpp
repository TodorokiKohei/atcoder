#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int match = 0;
    int i = -1;
    vector<bool> used(n);
    while(i < n){
        i++;
        if (s[i] == ')') continue;
        for(int j = i+1; j < n; j++){
            if (s[j] == ')' && !used[j]){
                match++;
                used[j] = true;
                break;
            }
        }
    }
    int numR = 0, numL = 0;
    rep(i,n){
        if (s[i] == '(') numR++;
        else numL++;
    }
    numR -= match;
    numL -= match;
    rep(i, numR) s = s + ')';
    rep(j, numL) s = '(' + s;
    cout << s << endl;
    return 0;
}