// Question Link : https://leetcode.com/problems/describe-the-painting/

// Level : Medium 

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long >>res; 
        long long  arr[100002] = {}; 
        bool b[100002] = {};
        
        for(int i=0;i<segments.size();i++){
            arr[segments[i][0]] += segments[i][2];
            arr[segments[i][1]] -= segments[i][2];
            b[segments[i][0]] = true;
            b[segments[i][1]] = true;
        }
        
        long long  prev=0, sum=0;
        for(int i=1;i<100002;i++){
            if(b[i] && sum ){
                res.push_back({prev , i ,sum});
            }
            if(b[i]==true)
                prev = i;
            
            sum+= arr[i];
        }
        return res;
    }   
};