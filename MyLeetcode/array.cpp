#include "array.h"



// ���ֲ��� 1 
int Solution::search(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (nums[middle] < target) {
			left = middle + 1;
		}
		else if (nums[middle] > target) {
			right = middle - 1;
		}
		else {
			return middle;
		}

	}
	return -1;
}


// ���ֲ��� 2 ����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
// ���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
int Solution2::search(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (nums[middle] < target) {
			left = middle + 1;
		}
		else if (nums[middle] > target) {
			right = middle - 1;
		}
		else {
			return middle;
		}

	}
	return right + 1;
}


// ���ֲ��� 3 ������34. �����������в���Ԫ�صĵ�һ�������һ��λ��
vector<int> Solution3::searchRange(vector<int>& nums, int target) {
	int left = getLeftBorder(nums, target);
	int right = getRightBorder(nums, target);
	// ���һ target�������鷶Χ�� 
	if (left == -2 || right == -2) return { -1, -1 };
	// ����� target�����鷶Χ�ڣ��Ҵ���target������{2��5��6��7} target = 6������{2��2}
	if (right - left > 1) return { left + 1, right - 1 };
	// ����� target �����鷶Χ�У��������в�����target����������{3,6,7},targetΪ5������{-1, -1}
	return { -1, -1 };

}

int Solution3::getLeftBorder(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int LeftBorder = -2;
	while (left <= right) {
		int middle = left + ((right - left) / 2);
		if (nums[middle] < target) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
			LeftBorder = right;
		}
	}
	return LeftBorder;
}

int Solution3::getRightBorder(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int RightBorder = -2;
	while (left <= right) {
		int middle = left + ((right - left) / 2);
		if (nums[middle] <= target) {
			left = middle + 1;
			RightBorder = left;
		}
		else {
			right = middle - 1;

		}
	}
	return RightBorder;
}


/*********
���ֲ��ұ��� ��69
����һ���Ǹ����� x �����㲢���� x �� ����ƽ���� ��
********/

int Solution2::mySqrt(int x) {
	int left = 0;
	int right = x;
	int ans = -1;
	while (left <= right) { 
		int mid = left + ((right - left) / 2);
		if ((long long) mid * mid <= x) {	// ���ֻ�����������֣�С����ȥ��ȡ��߽�		
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
	
		}
	}
	return ans;
}
/***********
���ֲ��ұ��� ��367 
����һ�������� num ����� num ��һ����ȫƽ�������򷵻� true �����򷵻� false
***************/
bool Solution2::isPerfectSquare(int num) {
	int left = 0;
	int right = num;
	bool Square = false;
	while (left <= right) {
		int middle = left + (right - left) / 2;
		if ((long long)middle * middle < num) {
			left = middle + 1;
		}
		else if ((long long)middle * middle > num) {
			right = middle - 1;
		}
		else {
			Square = true;
			return Square;

		}
	}
	return Square;
}

int Solution4::removeElement(vector<int>& nums, int val) {
	int Slowindex = 0;
	for (int Fastindex = 0; Fastindex < nums.size(); Fastindex++) {
		if (nums[Fastindex] != val) {
			nums[Slowindex++] = nums[Fastindex];
		}
	}
	return Slowindex;
}

int Solution4::removeDuplicates(vector<int>& nums) {
	int slowindex = 0;
	for (int fastindex = 0; fastindex < nums.size(); fastindex++) {
		if (nums[fastindex] != nums[slowindex]) {
			nums[++slowindex] = nums[fastindex];
		}
	}
	return ++slowindex;

}

void Solution4::moveZeroes(vector<int>& nums) {
	int slowindex = 0;
	int length = nums.size();
	for (int fastindex = 0; fastindex < nums.size(); fastindex++) {
		if (nums[fastindex] != 0) {
			nums[slowindex++] = nums[fastindex];
		}
		/**** �����¼ ������������Ԫ�ص����ظ�����
		else {
			nums[length--] = 0;
		}
		****/
	}
	for (int i = slowindex; i < nums.size(); i++) {
		nums[i] = 0;
	}

}

vector<int> Solution4::sortedSquares(vector<int>& nums) {
	int k = nums.size() - 1;
	vector<int> result(nums.size(), 0);
	for (int i = 0, j = nums.size() - 1; i <= j;) {
		if (nums[i] * nums[i] < nums[j] * nums[j]) {
			result[k--] = nums[j] * nums[j];
			j--;
		}
		else {
			result[k--] = nums[i] * nums[i];
			i++;
		}
	}
	return result;
}

int Solution4::minSubArrayLen(int target, vector<int>& nums) {
	int result = INT32_MAX;
	int sum = 0;
	int j = 0;
	int sublength = 0;
	for (size_t i = 0; i < nums.size(); i++) {
		sum += nums[i];
		while (sum >= target) {
			sublength = i - j + 1;
			result = sublength < result ? sublength : result;
			sum -= nums[j++];		
		}
	}
	return result == INT32_MAX ? 0 : result;
}

int Solution4::totalFruit(vector<int>& fruits) {
	int maxlength = 0;
	int left = 0, right = 0;
	int lb = fruits[left], rb = fruits[right];
	while (right < fruits.size()) {
		if (fruits[right] == lb || fruits[right] == rb) {
			maxlength = max(maxlength, right - left + 1);
			right++;	
		}
		else {
			left = right - 1;
			lb = fruits[left];
			while (left >= 1 && fruits[left - 1] == lb ) left--;
			rb = fruits[right];
			maxlength = max(maxlength, right - left + 1);
		
		}
	}
	return maxlength;

}

// ����ҿ� ѭ�����
vector<vector<int>> Solution4::generateMatrix(int n) {
	int startx = 0, starty = 0; //���г�ʼλ
	int loop = n / 2; //ѭ��Ȧ�� 3/2=1
	int mid = n / 2; //����Ԫ��
	int offset = 1;
	int count = 1;
	vector<vector<int>> result(n, vector<int>(n, 0)); //����n��n�Ķ�ά����
	while (loop--) {
		int i = startx; //��
		int j = starty; //��
		for (j = starty; j < n - offset; j++) {
			result[i][j] = count++;
		}
		for (i = startx; i < n - offset; i++) {
			result[i][j] = count++;
		}
		for (; j > starty; j--) {
			result[i][j] = count++;
		}
		for (; i > startx; i--) {
			result[i][j] = count++;
		}
		offset++;
		startx++;
		starty++;
	
	}
	if (n % 2) result[mid][mid] = n * n;
	return result;

}

// ����ҿ� ѭ�����
vector<int> Solution4::spiralOrder(vector<vector<int>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return {};
	int startx = 0, starty = 0;
	size_t row = matrix.size(), col = matrix[0].size();
	vector<int> result(row * col); //���������
	int mid = min(row, col) / 2;
	int loop = min(row, col)/2;
	int offset = 1;
	int count = 0;
	while (loop--) {
		int i = startx;
		int j = starty;

		for (j = starty; j < starty + col - offset; j++) {
			result[count++] = matrix[startx][j];	
		}
		for (i = startx; i < startx + row - offset; i++) {
			result[count++] = matrix[i][j];
		}
		for (; j > starty; j--) {
			result[count++] = matrix[i][j];
		}
		for (; i > startx; i--) {
			result[count++] = matrix[i][starty];
		}
		offset+= 2;
		startx++;
		starty++;
	}
	if (min(row, col) % 2) {
		if (row > col) {
			for (int i = mid; i < mid + row - col + 1;++i) {
				result[count++] = matrix[i][mid];
			}
			
		}
		else {
			for (int i = mid; i < mid + col- row + 1; ++i) {
				result[count++] = matrix[mid][i];
			}
		
		}
	
	}

	return result;

}