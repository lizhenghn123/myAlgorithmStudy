/*******
https://gist.github.com/chenshuo/4519962
读取一个文件中的内容，按单词进行统计频率。
注意：要求单词之间至少有一个空格分开，另外单词后面的标点符号是一个整体。
即：word！ 和 word 算两个不同的单词，因此实现中没有去掉标点。
此处，尤其是函数sort_words_by_frequencies是由陈硕所写的统计代码，很不错，思路很好！
*******/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>
using namespace std;


typedef std::unordered_map<std::string, int> WordCount;
WordCount counts;

struct Greater
{
	bool operator()(const std::pair<int, WordCount::const_iterator>& lhs,
		const std::pair<int, WordCount::const_iterator>& rhs) const
	{
		return lhs.first > rhs.first;
	}
};

// impl by chenshuo
void sort_words_by_frequencies(const WordCount& counts)
{
	typedef std::vector<std::pair<int, WordCount::const_iterator> > FreqList;
	FreqList freq;
	freq.reserve(counts.size());
	for (WordCount::const_iterator it = counts.begin(); it != counts.end(); ++it)
	{
		freq.push_back(make_pair(it->second, it));
	}

	std::sort(freq.begin(), freq.end(), Greater());
	for (FreqList::iterator itr = freq.begin(); itr!=freq.end(); ++itr)
	{
		std::cout << itr->first << '\t' << itr->second->first << '\n';
	}
}

void read_text(const char* file)
{
	std::ifstream ifs(file);
	assert(!ifs.fail());
	std::string line;
	while(!ifs.eof())
	{
		ifs >> line;
		std::istringstream iss(line);
		std::string word;
		while (iss >> word)
		{
			counts[word] ++;
		}
	}
	ifs.close();
}

int main(int argc, char* argv[])
{
	read_text("words.txt");

	sort_words_by_frequencies(counts);
 
	getchar();
	return 0;
}