// 838. Push Dominoes

// Two Pointers

class Solution {
public:
    string pushDominoes(string dominoes) {
        //扫描两遍？
        //
        const int sz=dominoes.size();
        vector<int> order(sz,0);
        // vector<int> rorder(sz,0);
        
        for(int i=0;i<sz;){
            if(dominoes[i]!='R'){
                i++;
                continue;
            }
            // R
            int oldi=i++;
            while(i<sz&&dominoes[i]=='.'){
                order[i]=sz-(i-oldi);//离'R'越近，推力越大， 'L'同理
                i++;
            }
        }
        //
        // cout<<dominoes[1]<<'!';
        for(int i=sz-1;i>=0;){
            if(dominoes[i]!='L'){
                i--;
                continue;
            }
            //
            int oldi=i--;
            // cout<<oldi<<' ';
            while(i>=0&&dominoes[i]=='.'){
                // rorder[i]=(oldi-i);
                order[i]-=sz-(oldi-i);
                i--;
            }
            //
        }
        for(int i=0;i<sz;i++){
            if(order[i]==0)continue;
            dominoes[i]=order[i]>0?'R':'L';
            
            // if(dominoes[i]!='.'||(order[i]==rorder[i]))continue;
            // if(order[i]==0)dominoes[i]='L';
            // else if(rorder[i]==0)dominoes[i]='R';
            // else{
            //     dominoes[i]=order[i]>rorder[i]?'L':'R';
            // }
        }
        
        return dominoes;
    }
};