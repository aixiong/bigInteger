#pragma once

#include<algorithm>
#include<string>
#include<vector>

namespace sMath
{   //sMath is namespace just for math with string
	using std::string;
	using std::vector;

	int compString(const string& s1, const string& s2)
	{   //compare two string,return -1, 0 or 1
		if (s1.length() == s2.length())
		{
			size_t n = s1.length();
			for (size_t i = 0; i < n; ++i)
			{
				if (s1[i] == s2[i])continue;
				else return s1[i] < s2[i] ? -1 : 1;
			}
			return 0;
		}
		else return s1.length() < s2.length() ? -1 : 1;
	}

	string addString(const string& s1, const string& s2)
	{   //add two string and return the sum
		size_t n1 = s1.length();
		size_t n2 = s2.length();
		size_t n = std::max(n1, n2) + 1;
		vector<char> vec(n, 0);
		size_t i = n1;//the index for s1
		size_t j = n2;//the index for s2
		size_t c = 0;//the carray bit
		int k = 0;//the index for vec
		while (i || j)
		{
			int a = 0, b = 0;
			if (i)a = s1[--i] - '0';
			if (j)b = s2[--j] - '0';
			int tmp = a+b + c;
			vec[k++] = tmp % 10 + '0';
			c = tmp / 10;
		}
		if (c)vec[k++] = c + '0';
		string res(vec.rend() - k, vec.rend());
		return res;
	}

	string subString(const string& s1, const string& s2)
	{
		int flag = compString(s1, s2);

		if (flag == 1)
		{
			size_t n1 = s1.length();
			size_t n2 = s2.length();
			size_t n = std::max(n1, n2);
			vector<char> vec(n, 0);
			size_t i = n1;//the index for s1
			size_t j = n2;//the index for s2
			size_t c = 0;//the carray bit
			int k = 0;//the index for vec
			while (i || j)
			{
				int a = 0, b = 0;
				if (i)a = s1[--i] - '0';
				if (j)b = s2[--j] - '0';
				int tmp = a - b + c;
				if (tmp < 0)
				{
					tmp += 10;
					c = -1;
				}
				vec[k++] = tmp % 10 + '0';
			}
			while (vec[k - 1] == '0')--k;
			string res(vec.rend() - k, vec.rend());
			return res;
		}
		else if (flag == -1)
		{
			string res = "-";
			res+= subString(s2, s1);
			return res;
		}
		else
		{
			return "0";
		}
	}
}