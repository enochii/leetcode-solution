#pragma once

// Hamming Distance
//easy

class Solution {
public:
	int hammingDistance(int x, int y) {
		int distance = 0;
		while (x>0 || y>0)
		{
			distance += (x & 1) ^ (y & 1);
			x = (x >> 1), y = (y >> 1);
		}
		return distance;
	}
};