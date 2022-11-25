#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define  all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    int n, x;
    while (true){
        cin >> n >> x;
        if (n == 0 && x == 0) break;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    if (i + j + k == x) ans++;
                }
            }
        }
        cout << ans << endl;    
    }
    return 0;
}