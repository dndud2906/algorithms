#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue> //queue
#include <algorithm> //sort
#include <cstdio> //scanf

using namespace std;

int n;
int map[25][25] = { 0, };
int chk[25][25] = { 0, };
int route[313] = { 0, };
int cnt = 0;

queue<pair<int, int> > q;
int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && chk[i][j] == 0) {
				cnt++;	//´ÜÁö ¼ö
				route[cnt - 1]++;
				chk[i][j] = 1;
				int cx = j;
				int cy = i;
				q.push(make_pair(cy, cx));
				while (true) {
					for (int k = 0; k < 4; k++) {
						int nx = cx + dirX[k];
						int ny = cy + dirY[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[ny][nx] == 1 && chk[ny][nx] == 0) {
							chk[ny][nx] = 1;
							q.push(make_pair(ny, nx));
							route[cnt - 1]++;
						}
					}
					if (!q.empty()) {
						q.pop();
						if (q.empty())
							break;
						cx = q.front().second;
						cy = q.front().first;
					}
				}
			}
		}
	}

	sort(route, route + cnt);
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
		cout << route[i] << endl;

	return 0;
}