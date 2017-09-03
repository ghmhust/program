#include <iostream>
#include <string>
//查找输入字符串中 第一个非重复的字符
using namespace std;
class Solution
{
public:
	string s;
	int hash[256];
	void Insert(char ch)
	{
		s += ch;
		hash[ch]++;
	}
	char FirstAppearingOnce()
	{
		int len = s.size();
		for (int i = 0; i<len; ++i){
			if (hash[s[i]] == 1){
				return s[i];
			}
		}
		return '#';
	}
};

int main(){
	Solution so;
	for (int i = 0; i < 256; ++i){
		so.hash[i] = 0;
	}
	so.Insert('g');
	cout << so.FirstAppearingOnce();
	so.Insert('o');
	cout << so.FirstAppearingOnce();
	so.Insert('o');
	cout << so.FirstAppearingOnce();
	so.Insert('g');
	cout << so.FirstAppearingOnce();
	so.Insert('l');
	cout << so.FirstAppearingOnce();
	so.Insert('e');
	cout << so.FirstAppearingOnce();
	system("pause");
	return 0;
}