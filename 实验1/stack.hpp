#include<iostream>
using namespace std;

template<class T>
class stack						//ջ��
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
		void clearstack()		//���
		{
			top = base;
		}
		int isempty()			//�п�
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
		int length()			//�󳤶�
		{
			return top - base;
		}
		T gettop()			//ȡջ��Ԫ��
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
		int push(T c)			//��ջ
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
		T pop()			//��ջ
		{
			if (length() == 0)
			{
				cout << "This stack is empty��" << endl;
				return 0;
			}
			return *--top;
		}
		void traverse()		//����
		{
			T* p;
			for (p = top - 1; p > base; p--)
			{
				cout << *p << "->";
			}
			cout << *p << endl;
		}
	protected:
		T *base;				//ջ��ָ��
		T *top;				//ջ��ָ��
		static int a;
};