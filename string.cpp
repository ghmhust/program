#include<cstring>
using namespace std;
class String{
public:
	String(const char*str);		//��ͨ���캯��
	String(const String& other);		//�������캯��
	~String();							//��������
	String & operator = (const String &other);   //��ֵ����
	String & operator + (const String &other);	 //�ַ�������
	bool operator == (const String &other);		//�ַ������
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
		data = 0;		//ָ����0
	}
}
