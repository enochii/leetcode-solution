#pragma once

//Integer to Roman
//Medium

string match(int);
class Solution {
public:
	string intToRoman(int num) {
		int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1, };
		string result;
		for (int i = 0;i<13;++i)
		{
			while (num >= value[i])
			{
				result.append(match(value[i]));
				num -= value[i];
			}
		}

		return result;
	}
};

string match(int num)
{
	switch (num) {
	case 1:
		return "I";
	case 4:
		return "IV";
	case 5:
		return "V";
	case 9:
		return "IX";
	case 10:
		return "X";
	case 40:
		return "XL";
	case 50:
		return "L";
	case 90:
		return "XC";
	case 100:
		return "C";
	case 400:
		return "CD";
	case 500:
		return "D";
	case 900:
		return "CM";
	case 1000:
		return "M";
	default:
		break;
	}
	return "";
}