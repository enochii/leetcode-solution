class Solution {
/*
对于start或者end，都只有两种形式的move，XL->LX & RX -> XR
也就是R和L的相对顺序是无法改变的，这里还有一个问题是诸如：
XLXXLX LXXXXL true or false? -> false
也就是说，除了相对位置，还要考虑move的合法性
*/
public:
    bool canTransform(string start, string end) {
        size_t sz = start.size();
        if(sz!=end.size())return false;

        /*
        其实下面四个vector根本不用，在循环时根据R还是L直接判断move合法性即可，省时省空间
        */
        //std::vector<int> sl, sr, el, er;
        size_t si = 0,ei = 0;
        for(;;){
            while(si<sz&&start[si]=='X')++si;
            while(ei<sz&&end[ei]=='X')++ei;
            if(si==sz||ei==sz)break;
            if(start[si]!=end[ei])return false;//L/R在两个string的相对位置不同
            if(start[si]=='L'){
                //sl.push_back(si);
                //el.push_back(ei);
                if(si<ei)return false;
            }
            else {
                //sr.push_back(si);
                //er.push_back(ei);
                if(si>ei)return false;
            }
            ++si;++ei;
        }
        if(si!=sz||ei!=sz)return false;
        if(sl.size()!=el.size()||sr.size()!=er.size())return false;
        //for(size_t i = 0;i<sl.size();++i){
        //    if(sl[i]<el[i])return false;
        //}
        //for(size_t i = 0;i<sr.size();++i){
        //    if(sr[i]>er[i])return false;
        //}
        return true;
        }
};