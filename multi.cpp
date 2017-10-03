#include <vector>
#include <iostream>
using namespace std;

vector<int> multiply(const vector<int>& A) {
	vector<int> B;
	int length = A.size();
	if (length == 0)
		return B;
	B.push_back(1);
	for (int i = 0; i<length - 1; ++i)
	{
		B.push_back(B.back()*A[i]);
	}
	int temp = 1;
	for (int i = length - 2; i >= 0; --i)
	{
		temp *= A[i + 1];
		B[i] *= temp;
	}
	return B;
}

int main(){
	vector<int> A = { 1, 2, 3, 4, 5 };
	vector<int> B = multiply(A);
	int len = B.size();
	for (int i = 0; i < len; ++i){
		cout << B[i] << endl;
	}
	system("pause");
	return 0;
}