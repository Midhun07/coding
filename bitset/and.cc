#include <iostream>
#include <bitset>
using namespace std;
int main() {
    int a[4] = {2, 5, 3, 9};
    int cnt = 0, s = 0;
    for (auto i : a) {
        if (!(s & i)) {
            cnt++;
            s = i;
        }
    }
    cout << cnt << endl;
}