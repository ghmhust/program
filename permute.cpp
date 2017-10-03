#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

void permution(vector<int>& temp, int index){
	if (index >= temp.size()){
		for (int i = 0; i < temp.size(); ++i)
			cout << temp[i];
		cout << endl;
	}
	for (int i = index; i < temp.size(); ++i){
		swap(temp[index], temp[i]);
		permution(temp, index + 1);
		swap(temp[index], temp[i]);
	}
}

void permute(vector<int>& temp){
	permution(temp, 0);
}

int main(){
	int n = 0;
	while (cin >> n){
		vector<int> temp(n);
		for (int i = 0; i < n; ++i){
			cin >> temp[i];
		}
		permute(temp);
	}
	return 0;
}