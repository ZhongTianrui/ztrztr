#include <bits/stdc++.h>
using namespace std;
class mymath{
	public:
		mymath(){
			num = 0;
		}
	public:
		int num;
};
mymath add(int num1, int num2) {
	int sum = num1 ^ num2;
    int carry = (num1 & num2) << 1;  
    while(carry != 0){
        int a = sum;
        int b = carry;
        sum = a ^ b;
        carry = (a & b) << 1;  
    }
    mymath mm;
    mm.num = sum;
    return mm;
}
mymath sub(int num1, int num2) {
	mymath subtractor_mm = add(~num2, 1);// 先求减数的补码（取反加一）
	int subtractor = subtractor_mm.num;
    subtractor_mm = add(num1, subtractor); // add()即上述加法运算　　
    int result = subtractor_mm.num;
    mymath mm;
    mm.num = result;
}
mymath operator-(mymath &a, mymath &b) {
	return sub(a.num, b.num);
}
mymath operator+(mymath &a, mymath &b) {
	return add(a.num, b.num);
}
typedef mymath mym;
int main() {
	ios::sync_with_stdio(false);
	mym a, b, c;
	a.num = b.num = 5;
	cin >> a.num >> b.num;
	c = a + b;
	cout << c.num;
// 	c = a - b;
// 	cout << c.num;
	return 0;
}