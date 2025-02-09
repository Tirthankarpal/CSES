#include "bits/stdc++.h"
// #include <bits/stdc++.h>
using namespace std;
struct Node {
    int x, y;
};
bool isValid(int x, int y, int n, int m, vector<string>& str) {
    return x >= 0 && y >= 0 && x < n && y < m && str[x][y] != '#';
}
string st;
int main() {
    int n,m;
    cin>>n>>m;
    vector<string> str(n);
    vector<vector<char> > path(n,vector<char>(m,' '));
    int sti = -1, stj = -1;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        if (sti == -1) {
            for (int j = 0; j < m; j++) {
                if (str[i][j] == 'A') {
                    sti = i;
                    stj = j;
                    break;
                }
            }
        }
    }
    queue<Node> q;
    Node start = {sti, stj};
    q.push(start);
    str[sti][stj] = '#';
    int directions[4][2] = {{1, 0},{0, 1},{-1, 0},{0, -1}};
    char dirChars[] = {'D', 'R', 'U', 'L'};
    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int newX=node.x+directions[k][0];
            int newY=node.y+directions[k][1];
            if (isValid(newX,newY,n,m,str)) {
                path[newX][newY]=dirChars[k];
                if (str[newX][newY]=='B') {
                    while(newX!=sti || newY!=stj){
                        st+=path[newX][newY];
                        if(path[newX][newY]=='D'){
                            newX--;
                        }
                        else if(path[newX][newY]=='U'){
                            newX++;
                        }
                        else if(path[newX][newY]=='R'){
                            newY--;
                        }
                        else if(path[newX][newY]=='L'){
                            newY++;
                        }
                    }
                    cout<<"YES"<<endl;
                    cout<<st.size()<<endl;
                    reverse(st.begin(),st.end());
                    cout<<st<<endl;
                    return 0;
                }
                str[newX][newY]='#';
                Node newNode={newX,newY};
                q.push(newNode);
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}