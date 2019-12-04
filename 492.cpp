// 492. Construct the Rectangle
class Solution {
public:
    vector<int> constructRectangle(int area) {
        for(int w = (int)sqrt(area); w > 0;w--)
        {
            if(area % w == 0)
            {
                return {area/w, w};
            }
        }
        
        return {};
    }
};