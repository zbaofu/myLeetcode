#include "others.h"

bool otherSolution ::judgeCircle(string moves) {
	int x = 0;
	int y = 0;
	for (int i = 0; i < moves.size(); i++) {
		if (moves[i] == 'R') x++;
		else if (moves[i] == 'L') x--;
		else if (moves[i] == 'U') y++;
		else if (moves[i] == 'D') y--;

	}
	if (x == 0 && y == 0) return true;
	return false;
}

// 题200 岛屿数量
// DFS
void otherSolution::numIslandsDfs(vector<vector<char>>& grid, int r, int c) {

	// 遍历过的元素置0
	grid[r][c] = '0';

	// 终止条件和递归放在一起
	if (r - 1 >= 0 && grid[r - 1][c] == '1') numIslandsDfs(grid, r - 1, c);
	if (r + 1 < grid.size() && grid[r + 1][c] == '1') numIslandsDfs(grid, r + 1, c);
	if (c - 1 >= 0 && grid[r][c - 1] == '1') numIslandsDfs(grid, r, c - 1);
	if (c + 1 < grid[0].size() && grid[r][c + 1] == '1') numIslandsDfs(grid, r, c + 1);
}

int otherSolution::numIslands(vector<vector<char>>& grid) {
	if (grid.size() == 0) return 0;

	int nums = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == '1') {
				nums++;
				numIslandsDfs(grid, i, j);
			
			}
		}
	}
	return nums;
}

