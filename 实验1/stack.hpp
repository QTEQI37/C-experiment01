#include<iostream>
using namespace std;

template<class T>
class stack						//栈类
{
	public:
		stack()
		{
			base = new T[10];
			top = base;
		}
		~stack()
		{
			delete[] base;
		}
		void clearstack()		//清空
		{
			top = base;
		}
		int isempty()			//判空
		{
			if (top == base)
			{
				cout << "The stack is empty!" << endl;
				return true;
			}
			else
			{
				cout << "There is someting in stack!" << endl;
				return false;
			}
		}
		int length()			//求长度
		{
			return top - base;
		}
		T gettop()			//取栈顶元素
		{
			if (length() == 0)
			{
				cout << "There is noting in the stack!" << endl;
				return 0;
			}
			else
			{
				return *(top - 1);
			}
		}
		int push(T c)			//进栈
		{
			if (length() == 10)
			{
				cout << "this stack is full!" << endl;
				return 0;
			}
			*top = c;
			top++;
			return 1;
		}
		T pop()			//出栈
		{
			if (length() == 0)
			{
				cout << "This stack is empty！" << endl;
				return 0;
			}
			return *--top;
		}
		void traverse()		//遍历
		{
			T* p;
			for (p = top - 1; p > base; p--)
			{
				cout << *p << "->";
			}
			cout << *p << endl;
		}
	protected:
		T *base;				//栈底指针
		T *top;				//栈顶指针
		static int a;
};