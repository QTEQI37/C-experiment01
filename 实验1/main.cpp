#include<iostream>
#include<string>
#include"stack.hpp"
using namespace std;

const int num = 5;
int search[num][num] = { {1,1,2,2,1},{1,1,2,2,1},{1,1,1,1,1},{1,1,1,1,1},{2,2,2,2,0} };
//����һ�����������а����Ӽ��˳���˳�򣬶���1 >,2 <,3 =0

static char op[num] = { '+','-','*','/','#' };

int getIndex(char c)//�ж��ַ�������˳��
{
    for (int i = 0; i < num; i++)
    {
        if (op[i] == c)
        {
            return i;
        }
    }
    cout << "Can't find!" << endl;
    return -1;

}

//��������ʽ�ӵ�ֵ
int compute(string s)
{
    char str[100];
    strcpy_s(str,s.c_str());
    double num = 0;
    bool flag = true;
    char* p;
    stack<double> opnd;//opndΪ������ջ
    stack<char> optr;//optrΪ�����ջ
    optr.push('#');
    for (p = str ; ; )
    {
        if (*p >= '0' && *p <= '9')//ʹp��0-9֮���ж����ֺ��ַ�
        {
            if (flag)
            {
                num = num * 10 + *p - '0';
                p++;
            }
            if (*p < '0' || *p > '9')
            {
                flag = false;
                opnd.push(num);
                num = 0;
                flag = true;
            }
          
        }
        else if (search[getIndex(optr.gettop())][getIndex(*p)] == 2)//push
        {
            optr.push(*p++);
        }
        else if (search[getIndex(optr.gettop())][getIndex(*p)] == 1)//pop
        {
            char m_op ;
            double num1, num2;
            m_op = optr.pop();
            num2 = opnd.pop();
            num1 = opnd.pop();

            if (m_op == '+')
            {
                opnd.push(num1 + num2);
            }
            if (m_op == '-')
            {
                opnd.push(num1 - num2);
            }
            if (m_op == '*')
            {
                opnd.push(num1 * num2);
            }
            if (m_op == '/')
            {
                if (num2 == 0) {
                    cout << "Divide by zero error!" << endl;
                    exit(-1);
                }
                opnd.push(num1 / num2);
            }
        }
        else if (search[getIndex(optr.gettop())][getIndex(*p)] == 0)//push
        {
            return opnd.gettop();
        }
        else
        {
            cout << "Input err!" << endl;
            exit(-1);
        }
    }
}

int main()
{
    string s = new char[100];
    cout << "Please enter computation expression:" << endl;
    cin >> s;
    s.insert(s.size(), 1,'#');
    double res = compute(s);

    cout << "The result is:" << res << endl;
    return 0;
}