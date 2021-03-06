英文链接: https://leetcode.com/problems/evaluate-reverse-polish-notation/  
中文链接: https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/


计算逆波兰表达式
```
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

>迭代版   
维护一个栈，读到数的时候直接进栈   
每得到一个运算符，从栈顶取出两个数   
计算后将结果作为一个运算数放回栈中   
直到式子结束，此时栈中唯一一个元素便是表达式的解   
注意push进栈操作不要写成return   
最后不要遗漏return s.top();
```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1)
            return stoi(tokens[0]);
            // return atoi(tokens[0].c_str());

        stack<int> s;
        for(int i = 0; i < tokens.size(); ++i)
        {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
                s.push(stoi(tokens[i]));
            else
            {
                int v2 = s.top();
                s.pop();
                int v1 = s.top();
                s.pop();

                if(tokens[i] == "+")
                    s.push(v1 + v2);
                else if(tokens[i] == "-")
                    s.push(v1 - v2);
                else if(tokens[i] == "*")
                    s.push(v1 * v2);
                else if(tokens[i] == "/")
                {
                    if(v2 == 0)
                        s.push(0);
                    else
                        s.push(v1 / v2);
                }
            }
        }

        return s.top();
    }
};
```

>递归版   
一个有效的逆波兰表达式的末尾必定是操作符   
可以从末尾开始处理   
如果遇到操作符，向前两个位置调用递归函数，找出前面两个数字进行操作，将结果返回   
如果遇到的是数字，则直接返回即可

```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int op = tokens.size() - 1;
        return helper(tokens, op);
    }

private:
    int helper(vector<string>& tokens, int &op) {
        string s = tokens[op];

        if(s != "+" && s != "-" && s != "*" && s != "/")
            return stoi(s);
        else
        {
            int v2 = helper(tokens, --op);
            int v1 = helper(tokens, --op);

            if(s == "+")
                return v1 + v2;
            else if(s == "-")
                return v1 - v2;
            else if(s == "*")
                return v1 * v2;
            else if(s == "/")
            {
                if(v2 == 0)
                    return 0;
                else
                    return v1 / v2;
            }
        }
    }
};
```


>if(!is_operator(s))
```
private:
    bool is_operator(const string &op) 
    {
        return op.size() == 1 && string("+-*/").find(op) != string::npos;
    }
```
