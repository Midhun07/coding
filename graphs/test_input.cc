#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream iff;
  iff.open("in_cc_dfs.txt");
  string s;
  getline(iff, s, '\n');
  int line = 0;
  while (!iff.eof()) {
    stringstream str(s);
    line++;
    // cout << "searching line " << line << " " << s << " "<< endl;
    vector<string> vec;
    string temp;
    int cnt = 0;
    while (getline(str, temp, ' ')) {
      vec.push_back(temp);
    }
    if (vec.size() == 2) {
      if (vec[0] == vec[1]) {
        cnt++;
        cout << vec[0] << " " << vec[1] << " @ line: " << line << endl;
        break;
      }
    }
    getline(iff, s, '\n');
  }
  iff.close();
  return 0;
}
