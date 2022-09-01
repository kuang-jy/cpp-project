class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * ���ر��ʽ��ֵ
     * @param s string�ַ��� ������ı��ʽ
     * @return int����
     */
    
    vector<int> calc(string s,int low){
        stack<int> stk;
        int num = 0;
        char op = '+';   //Ĭ�ϲ�����Ϊ+
        int i = low;
        for(;i < s.length();i++){
            //ת������
            if(s[i]>='0' && s[i] <= '9'){
                num = num*10+s[i]-'0';
                if(i != s.length()-1) continue;
            }
            if(s[i] == '('){  //���������
                vector<int> ans = calc(s, i+1);  //�ݹ����
                num = ans[0];  //����������Ϊ������Ľ�
                i = ans[1];    //�±�����Ϊ���������±�
                if(i != s.length()-1) continue;  //����������һ�������⣬��ô�������
            }
            switch(op){
                case '+':
                    stk.push(num);break;
                case '-':
                    stk.push(-num);break;
                case '*':   //�˷����ȼ���ߣ�����
                    int temp = stk.top();
                    stk.pop();
                    stk.push(temp*num);   //���ѹ��ջ��
                    break;
            }
            num = 0;  //���ò�����
            if(s[i] == ')') break;   //���������������˳�ѭ����������
            else op = s[i];
        }
        int cnt = 0;   //�����ʽ��ֵ
        while(!stk.empty()){
            cnt += stk.top();
            stk.pop();
        }
        return vector<int> {cnt,i};  //���ؽ�����Լ����������±�
    }
    
    int solve(string s) {
        return calc(s, 0)[0];
    }
};
