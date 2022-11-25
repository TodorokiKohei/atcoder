#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<P> c;
    vector<int> no(h);
    rep(i, h){
        int num = 0;
        rep(j, w){
            if (s[i][j] == '#'){
                c.push_back(make_pair(i,j));
                num++;
            } 
        }
        if (num == 0) no[i] = 1;
    }

    vector<vector<int>> ans(h, vector<int>(w));
    int num = 1;
    rep(i,k){
        int stR, stC, enR, enC;
        if (i == 0){
            stR = 0; stC = 0;
        }else{
            if (c[i].first == c[i-1].first){
                stR = c[i].first;
                stC = c[i].second;
            } 
            else {
                stR = c[i-1].first+1;
                stC = 0;
            }
        }

        if (i == k-1){
            enR = h-1;
            enC = w-1;
        }else{
            if (c[i].first == c[i+1].first){
                enR = c[i].first;
                enC = c[i+1].second-1;
            }else{
                enR = c[i+1].first-1;
                enC = w-1;
            }
        }

        while(stR){
            if (no[stR-1] == 1) stR--;
            else break;
        }
        while(enR != h-1){
            if (no[enR+1] == 1) enR++;
            else break;
        }

        for(int row = stR; row <= enR; row++){
            for(int col = stC; col <= enC; col++){
                ans[row][col] = num;
            }
        }
        num++;
    }

    rep(i,h) rep(j,w){
        printf("%d%c", ans[i][j], j == w-1 ? '\n': ' ');
    }
    return 0; 
}