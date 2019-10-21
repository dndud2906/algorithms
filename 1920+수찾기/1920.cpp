#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
//scanf, printf must use
//cin, cout timeout..

int n, m, num;
int nv[100000] = { 0, };

void binarySearch(int val)
{
	int start = 0;
	int end = n - 1;
	int mid;
	while (end - start >= 0)
	{
		mid = (start + end) / 2;

		if (nv[mid] == val) {
			printf("1\n");
			return;
		}
		else if (nv[mid] > val) 
			end = mid - 1;
		else if (nv[mid] < val) 
			start = mid + 1;
	}
	printf("0\n");
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &nv[i]);
	}
	sort(nv, nv + n);
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &num);
		binarySearch(num);
	}

	return 0;
}