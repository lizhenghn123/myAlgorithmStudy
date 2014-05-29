/*******
http://www.weibo.com/1915548291/ziWv47wlW
���������ı��ļ�������һ���ϴ󣬴�Լ�����У�ÿ����һ�����������������wudaokou.haidian.beijing.com��
����һ����С����Լһǧ���У�ÿ����һ��������������beijing.com��
�������ҵ�һ���Ͽ���㷨��Ѹ���ж�С�ļ��еĴ������嵥�Ƿ��ܺ��Ǵ��ļ��е�����������
https://gist.github.com/chenshuo/4946651
*******/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;


bool covered(const vector<string>& vecSites, const string& line)
{
	typedef vector<string>::const_iterator Iterator;
	Iterator filter = std::lower_bound(vecSites.begin(), vecSites.end(), line);
	if (filter != vecSites.end() && *filter == line)
		return true;
	if (filter != vecSites.begin())
	{
		--filter;
		if (line.size() >= filter->size()
			&& std::equal(filter->begin(), filter->end(), line.begin()))
			return true;
	}
	return false;
}

// impl by chenshuo
void StrMatch(const char* file, const char* fiterfile)
{
	vector<string> vecSites;
	{
		ifstream in2(file);
		string site;
		while (getline(in2, site))
		{
			if(site.empty())
				continue;
			std::reverse(site.begin(), site.end());
			//if (site[site.size()-1] != '.')
			//	site.push_back('.');

			vecSites.push_back(site);
		}
	}
	sort(vecSites.begin(), vecSites.end());

	ifstream in1(fiterfile);
	string line;
	while (getline(in1, line))
	{
		if(line.empty())
			continue;
		std::reverse(line.begin(), line.end());
		//if (line[line.size()-1] != '.')
		//	line.push_back('.');

		if (!covered(vecSites, line))
		{
			//cout << "remain " << line << "\t"; 
			std::reverse(line.begin(),line.end());
			std::cout << "dismatch: " << line << "\n";
		}
	}
}

// impl by lizheng
void MyStrMatch(const char* file, const char* fiterfile)
{
	std::vector<std::string> vecSites;
	std::vector<std::string> vecSubSites;

	std::string webstr;
	std::ifstream ifs1(file);//��ȡ�������ļ�
	assert(!ifs1.fail());	
	while(!ifs1.eof())
	{
		ifs1 >> webstr;
		vecSites.push_back(webstr);
	}
	ifs1.close();

	std::ifstream ifs2(fiterfile);//��ȡС�����ļ�
	assert(!ifs2.fail());	
	while(!ifs2.eof())
	{
		ifs2 >> webstr;
		vecSubSites.push_back(webstr);
	}
	ifs2.close();

	for(std::vector<std::string>::iterator itr2 = vecSubSites.begin(); itr2!=vecSubSites.end(); ++itr2)
	{
		const std::string& filter = *itr2;
		std::vector<std::string>::iterator itr1 = vecSites.begin();
		for(; itr1!=vecSites.end(); ++itr1)
		{
			const std::string& website = *itr1;
			size_t pos = filter.find(website);
			if(pos != std::string::npos && (pos + website.length() == filter.length()) )
			{
				//std::cout << website << "\t" << filter <<"\n";
				break;
			}
		}
		if(itr1==vecSites.end())
		{
			std::cout << "dismatch: " << filter << "\n";
		}
	}
}


int main(int argc, char* argv[])
{
	StrMatch("site.txt","sitefileter.txt");

	std::cout << "\n-------------------------\n";
	MyStrMatch("site.txt","sitefileter.txt");

	system("pause");
	return 0;
}