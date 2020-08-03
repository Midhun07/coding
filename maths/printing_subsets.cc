#include <bits/stdc++.h>
using namespace std;

void print_subsets(int n, int item, vector<int> vec) {
    if (item == n) {
        cout << "{ ";
        for(auto i : vec)
            cout << i << " ";
        cout << "}" << endl;
        vec.clear();
        return;
    }
    vec.push_back(item);
    print_subsets(n, item+1, vec); // including the current item
    vec.pop_back(); // skipping the current item
    print_subsets(n, item+1, vec);
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> vec;
    print_subsets(n, 0, vec);
    return 0;
}