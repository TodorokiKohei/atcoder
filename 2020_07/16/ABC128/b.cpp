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


bool f(pair<string, int> a, pair<string, int> b){
    if (a.first == b.first){
        return a.second > b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<string, int>> sp(n);
    map<pair<string, int>, int> m;
    rep(i,n){
        string s;
        int p;
        cin >> s >> p;
        sp[i] = make_pair(s, p);
        m[sp[i]] = i;
    }
    sort(all(sp), f);
    rep(i,n) cout << m[sp[i]]+1 << endl;
    return 0;
}