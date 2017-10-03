#include<cstring>
using namespace std;
class String{
public:
	String(const char*str);		//普通构造函数
	String(const String& other);		//拷贝构造函数
	~String();							//析构函数
	String & operator = (const String &other);   //赋值函数
	String & operator + (const String &other);	 //字符串连接
	bool operator == (const String &other);		//字符串相等
	int size();
private:
	char* data;
};

String::String(const char*str){
	if (str == NULL){
		data = new char[1];
		*data = '\0';
	}
	else{
		int lenth = strlen(str);
		data = new char[lenth + 1];
		strcpy(data, str);
	}
}
String::String(const String& other){
	if (!other.data) data = 0;
	data = new char[strlen(other.data + 1)];
	strcpy(data, other.data);
}
String::~String(){
	if (data){
		delete[] data;
		data = 0;		//指针置0
	}
}
