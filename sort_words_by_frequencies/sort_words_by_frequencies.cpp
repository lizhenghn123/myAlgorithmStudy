/*******
https://gist.github.com/chenshuo/4519962
��ȡһ���ļ��е����ݣ������ʽ���ͳ��Ƶ�ʡ�
ע�⣺Ҫ�󵥴�֮��������һ���ո�ֿ������ⵥ�ʺ���ı�������һ�����塣
����word�� �� word ��������ͬ�ĵ��ʣ����ʵ����û��ȥ����㡣
�˴��������Ǻ���sort_words_by_frequencies���ɳ�˶��д��ͳ�ƴ��룬�ܲ���˼·�ܺã�
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