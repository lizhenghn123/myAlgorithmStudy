//https://gist.github.com/Ninputer/2227226  https://gist.github.com/chenshuo/2232954
//��ʵ������ĺ������������baseStr��һ�������Ը��ĵģ��ַ������뽫���������������ֵĶ���ո��滻��һ���ո񣬵�һ�ո��豣����
//��ֱ��ʹ��baseStr�Ŀռ䣬���迪���µĴ洢�ռ䣬���ܳ���o(N)��ע����Сo��N���ַ����ĳ��ȣ�������ֵ���滻����ַ����ĳ��ȡ�
//��������ΪC#��������ʹ���κ����ԡ�����ʹ���κο⺯��������ͬʱ�����⺯����ʵ�֡�
#include <algorithm>
#include <string.h>
#include <cassert>


struct AreBothSpaces
{
	bool operator()(char x, char y) const
	{
		return x == ' ' && y == ' ';
	}
};

//impl by chenshuo
int removeContinuousSpaces(char* const str)
{
	size_t len = strlen(str); // or use std::string
	char* end = str+len;
	assert(*end == '\0');
	char* last = std::unique(str, end, AreBothSpaces());
	*last = '\0';
	return last - str;
}

int main()
{
	char inout[256] = "";
	strcpy(inout, "");
	removeContinuousSpaces(inout);
	assert(strcmp(inout, "") == 0);

	strcpy(inout, "a");
	removeContinuousSpaces(inout);
	assert(strcmp(inout, "a") == 0);

	strcpy(inout, " a");
	removeContinuousSpaces(inout);
	assert(strcmp(inout, " a") == 0);

	strcpy(inout, "  a");
	removeContinuousSpaces(inout);
	assert(strcmp(inout, " a") == 0);

	strcpy(inout, "a ");
	removeContinuousSpaces(inout);
	assert(strcmp(inout, "a ") == 0);

	strcpy(inout, "a  ");
	removeContinuousSpaces(inout);
	assert(strcmp(inout, "a ") == 0);

	strcpy(inout, "abc    def");
	removeContinuousSpaces(inout);
	assert(strcmp(inout, "abc def") == 0);

	strcpy(inout, "abc    def       ghi");
	removeContinuousSpaces(inout);
	assert(strcmp(inout, "abc def ghi") == 0);

	strcpy(inout, " a b   d e ");
	removeContinuousSpaces(inout);
	assert(strcmp(inout, " a b d e ") == 0);

	strcpy(inout, "           ");
	removeContinuousSpaces(inout);
	assert(strcmp(inout, " ") == 0);

	system("pause");
	return 0;
}