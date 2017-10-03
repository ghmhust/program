#include <string>
#include <iostream>
using namespace std;
//ÊäÈë×Ö·û´® ×ª int
int str2int1(string& str, int len, int index){
	int temp = 0;
	for (int i = index; i<len; ++i){
		int var = str[i] - '0';
		if (var >= 0 && var <= 9){
			temp = temp * 10 + var;
		}
		else return 0;
	}
	return temp;
}
int str2int2(string& str, int len){
	int temp = 0;
	for (int i = 1; i<len; ++i){
		int var = str[i] - '0';
		if (var >= 0 && var <= 9){
			temp = temp * 10 + var;
		}
		else return 0;
	}
	return (0 - temp);
}
int StrToInt(string str) {
	int len = str.size();
	if (len == 0) return 0;
	int temp = str[0] - '0';
	if (str[0] == '+')
		return str2int1(str, len, 1);
	if (temp >= 0 && temp <= 9)
		return str2int1(str, len, 0);
	return str2int2(str, len);
}

int main(){
	string s;
	cin >> s;
	int out = StrToInt(s);
	cout << out << endl;
	system("pause");
	return 0;
}