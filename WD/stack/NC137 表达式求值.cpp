class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    
    vector<int> calc(string s,int low){
        stack<int> stk;
        int num = 0;
        char op = '+';   //默认操作符为+
        int i = low;
        for(;i < s.length();i++){
            //转化数字
            if(s[i]>='0' && s[i] <= '9'){
                num = num*10+s[i]-'0';
                if(i != s.length()-1) continue;
            }
            if(s[i] == '('){  //子问题求解
                vector<int> ans = calc(s, i+1);  //递归求解
                num = ans[0];  //操作数重置为子问题的解
                i = ans[1];    //下标重置为子问题解的下标
                if(i != s.length()-1) continue;  //如果不是最后一个子问题，那么继续求解
            }
            switch(op){
                case '+':
                    stk.push(num);break;
                case '-':
                    stk.push(-num);break;
                case '*':   //乘法优先级最高，先算
                    int temp = stk.top();
                    stk.pop();
                    stk.push(temp*num);   //算好压回栈中
                    break;
            }
            num = 0;  //重置操作数
            if(s[i] == ')') break;   //子问题求解结束，退出循环，计算结果
            else op = s[i];
        }
        int cnt = 0;   //求解表达式的值
        while(!stk.empty()){
            cnt += stk.top();
            stk.pop();
        }
        return vector<int> {cnt,i};  //返回结果，以及这个结果的下标
    }
    
    int solve(string s) {
        return calc(s, 0)[0];
    }
};
