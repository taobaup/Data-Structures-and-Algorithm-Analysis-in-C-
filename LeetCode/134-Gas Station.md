

英文链接: https://leetcode.com/problems/gas-station/  
中文链接: https://leetcode-cn.com/problems/gas-station/


sum判断汽车能否顺利走完start~i段的路程，否则应从下一个汽车站出发  
total将所有gas[i]-cost[i]相加，判断汽车能否走完一个环路

```
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int sum = 0;
        int total = 0;

        for(int i = 0; i < gas.size(); ++i)
        {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];

            // 不要忘记把sum重置为0
            if(sum < 0)
            {
                start = i + 1;
                sum = 0;
            }
        }

        return total >= 0 ? start : -1;
    }
};
```
