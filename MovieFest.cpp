#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int> > movies(n);

    for (int i = 0; i < n; i++) {
        int st, end;
        cin >> st >> end;
        movies[i] = make_pair(st,end); 
    }
    sort(movies.begin(), movies.end());

    int res = 0;
    int last_end = 0;
    for (const auto& movie : movies) {
        int st = movie.first;
        int end = movie.second;
        if (st >= last_end) {
            res++;
            last_end = end;
        }
        else{
            last_end = min(last_end, end);
        }
    }

    cout << res << endl;
    return 0;
}