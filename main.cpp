#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> c(n);
    for (auto &ci : c){
        cin >> ci;
    }
    int64_t ans = 0;
    for (int left = 0; left < n; left += 2){
        int64_t bdl = 0;
        int64_t min_bdl = c[left];
        for (int right = left + 1; right < n && min_bdl >= 0; right += 2){
            bdl += c[right - 1] - c[right];
            if (bdl <= min_bdl) {
                ans += min_bdl - max<int64_t>(0, bdl) + 1;
            }
            min_bdl = min(min_bdl, bdl);
        }
    }
    cout << ans - (n / 2) << endl;
    return 0;
}
