#include <stdint.h>
#include <math.h>
#include <iostream>

using namespace std;

int main() {
    uint64_t num = 0;
    int q = 0;
    cin >> q;
    cin >> num;
    q = pow(2, q);
    cout << q << endl;
    int cnt = 0;
    while (q--) {
        uint64_t temp = num;
        while (temp) {
            if (temp & 1)
                cnt++;
            temp >>= 1;
        }
    }
    cout << cnt << endl;
    return 0;
}