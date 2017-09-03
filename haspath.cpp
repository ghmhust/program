class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == NULL || str == NULL || rows<1 || cols<1)
			return false;
		bool *exist = new bool[rows*cols];
		memset(exist, 0, rows*cols*sizeof(bool));
		int len = 0;
		for (int i = 0; i<rows; ++i){
			for (int j = 0; j<cols; ++j){
				if (haspath(matrix, rows, cols, i, j, str, exist, len))
					return true;
			}
		}
		delete[] exist;
		return false;
	}
	bool haspath(char* matrix, int rows, int cols, int row, int col, char* str, bool* exist, int len){
		if (str[len] == '\0')
			return true;
		bool flag = false;
		if (row >= 0 && row<rows && col >= 0 && col<cols && exist[row*cols + col] == 0 && matrix[row*cols + col] == str[len]){
			++len;
			exist[row*cols + col] = 1;
			flag = (haspath(matrix, rows, cols, row + 1, col, str, exist, len) ||
				haspath(matrix, rows, cols, row - 1, col, str, exist, len) ||
				haspath(matrix, rows, cols, row, col + 1, str, exist, len) ||
				haspath(matrix, rows, cols, row, col - 1, str, exist, len));
			if (!flag){
				--len;
				exist[row*cols + col] = 0;
			}
		}
		return flag;
	}
};