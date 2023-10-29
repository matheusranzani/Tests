#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M, X;

  cin >> N >> M;

  vector<int> album;

  while (M--) {
    cin >> X;

    if (album.size() == 0) {
      album.push_back(X);
      continue;
    }

    int flag = 0;

    for (int i = 0; i < album.size(); i++) {
      if (album[i] == X) {
        flag = 1;
        break;
      }
    }

    if (!flag) {
      album.push_back(X);
    }
  }

  cout << N - album.size() << endl;

  return 0;
}
