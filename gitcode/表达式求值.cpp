#include <iostream>
#include <stack>
using namespace std;
stack <int> x;//һ�������ֲ�������������ӵ�ջ
int main()
{
	double a,b;
	char c;
	cin>>a;//������һ�������Ժ����+��������
	int m=10000;
	a=a;//����Ĳ���
	x.push(a);//ѹ��ջ��
	while(cin>>c>>b)
	{
		if(c=='*')//��*֮ǰ��������*֮������ֻ�����
		{
			a=x.top();
			x.pop();
			x.push(a*b);
		}
		else//��b����
			x.push(b);
	}
	a=0;
	while(x.size())
	{
		a+=x.top();
//		a%=m;//ȡģ�����֮Դ
		x.pop();
	}
	cout<<a<<endl;
	return 0;
}


