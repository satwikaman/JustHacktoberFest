// Question Link : https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/

// Level : Medium 

class Solution {
public:
    
    
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        long long res = 0;
	    map<pair<int,int>,int>mp;
	    for(int i=0;i<n;i++){
		int gcd = __gcd(rectangles[i][0],rectangles[i][1]);
		pair<int, int> key = {rectangles[i][0]/gcd, rectangles[i][1]/gcd};
		if(mp.find(key) != mp.end()) res += mp[key];
		mp[key]++;
	}

	return res;
    }
};