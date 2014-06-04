//https://gist.github.com/Ninputer/2227226  https://gist.github.com/chenshuo/2232954
//请实现下面的函数，输入参数baseStr是一个（可以更改的）字符串，请将其中所有连续出现的多个空格都替换成一个空格，单一空格需保留。
//请直接使用baseStr的空间，如需开辟新的存储空间，不能超过o(N)（注意是小o，N是字符串的长度）。返回值是替换后的字符串的长度。
//样例代码为C#，但可以使用任何语言。如需使用任何库函数，必须同时给出库函数的实现。
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