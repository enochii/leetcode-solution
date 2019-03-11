#pragma once

#include <string>
#include <vector>

using std::vector;
using std::string;
using std::pair;
using std::make_pair;

//
//easy?

class Solution {
public:
	int romanToInt(string s) {
		//s.push_back(' ');
		vector<pair<string, int> > match = {
			make_pair("M",1000),make_pair("CM", 900),make_pair("D",500),make_pair("CD",400),make_pair("C",100),
			make_pair("XC",90),make_pair("L",50),make_pair("xL",40),make_pair("x",10),make_pair("IX",9),
			make_pair("V",5),make_pair("IV",4),make_pair("I",1),
		};

		int result = 0;

		for (const auto& x : match) {
			if (x.second == 900 || x.second == 400 ||
				x.second == 90 || x.second == 40 ||
				x.second == 9 || x.second == 4
				)
			{
				if (s.size()>1
					&& x.first == s.substr(0, 2))
				{
					result += x.second;
					s = (std::move(s)).substr(2, s.size() - 2);
				}
			}
			else {
				while (!s.empty()) {
					if (x.first[0] == s[0]) {
						result += x.second;
						s = (std::move(s)).substr(1, s.size() - 1);
					}
					else break;
				}
			}
		}
		return result;
	}
};