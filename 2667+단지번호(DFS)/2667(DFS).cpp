#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

int n;
int cnt = 0;
int map[25][25] = { 0, };
int house[313] = { 0, };
int dX[4] = { 1,0,-1,0 };
int dY[4] = { 0,1,0,-1 };

void dfs(int s, int f)
{
	int cx = s;
	int cy = f;
	for (int i = 0; i < 4; i++)
	{
		int nx = cx + dX[i];
		int ny = cy + dY[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n && map[nx][ny] == 1)
		{
			map[nx][ny] = 0;
			house[cnt - 1]++;
			dfs(nx,ny);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 ) {	//instead of check array, map array value 1->0
				map[i][j] = 0;
				cnt++;
				house[cnt - 1]++;
				dfs(i,j);
			}
		}
	}
	sort(house, house + cnt);
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
		cout << house[i] << endl;

	return 0;
}