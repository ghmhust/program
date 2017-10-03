#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;
struct bigcheng{
	vector<int> a;
	vector<int> b;
	string result;
};
void chartonum(string a, string b, bigcheng& temp);
void multiply(bigcheng& temp, vector<int>& res);
void numtochar(bigcheng& temp, vector<int>& res);

void chartonum(string a, string b, bigcheng& temp){
	int size_a = a.size();
	int size_b = b.size();
	for (int i = size_a - 1; i >= 0; i--){
		temp.a.push_back(a[i] - '0');
	}
	for (int i = size_b - 1; i >= 0; i--){
		temp.b.push_back(b[i] - '0');
	}
}

void multiply(bigcheng& temp, vector<int>& res){
	for (int i = 0; i < temp.a.size(); ++i){
		for (int j = 0; j < temp.b.size(); ++j){
			res[i + j] = (temp.a[i]) + (temp.b[j]);
		}
	}
	for (int i = res.size() - 1; i >= 0; --i){
		if (res[i] != 0) break;
		else res.pop_back();
	}
	int var = 0;
	for (int i = 0; i < res.size(); ++i){
		res[i] += var;
		var = res[i] / 10;
		res[i] = res[i] % 10;
	}
	if (var != 0) res.push_back(var);
}

void numtochar(bigcheng& temp, vector<int>& res){
	int size = res.size();
	for (int i = 0; i < size; ++i){
		temp.result.push_back(char(res[size - 1 - i] + '0'));
	}
}

int main(){
	bigcheng temp;
	string a, b;
	cin >> a >> b;
	chartonum(a, b, temp);
	vector<int> res(a.size() + b.size(), 0);
	multiply(temp, res);
	numtochar(temp, res);
	cout << temp.result << endl;
	system("pause");
	return 0;
}