//evaluate reverse polish notation
//计算逆波兰式（后缀表达式）的值 
//运算符仅包含"+", "-", "*"和"/"，被操作数可能是整数或其他表达式
//例如： ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
#include<vector>
#include<stack>
#include<sstream>
#include<string>
#include<iostream>
using namespace std;
/**
*
* @param tokens string字符串vector
* @return int整型
*/
    //使用栈控制计算顺序
	//将vector中的字符串依次进栈，遇到计算符则取出栈顶两个量，计算后将本次结果入栈
	int evalRPN(vector<string>& tokens) {
		stack<string> strStack;                           //存储字符串栈
		string str1, str2, resStr;                        //str1、str2:两个计算量
		                                                  //resStr:一次计算后的值
		long long num1 = 0, num2 = 0, res = 0;
		bool multiCal = false;                            //是否多次计算
		stringstream ss;
		if (tokens.size() == 1)                           //若只有一个量直接输出
		{
			ss.clear();
			ss << tokens[0];
			ss >> res;
			return res;
		}
		if (tokens.size() > 3)
			multiCal = true;

		for (auto t : tokens)
		{
			if (t != "+" && t != "-" && t != "*" && t != "/")
			{
				strStack.push(t);
			}
			else
			{
				if (strStack.size() >= 2)
				{
					str2 = strStack.top();
					strStack.pop();
					str1 = strStack.top();
					strStack.pop();
					ss.clear();
					ss << str2;
					ss >> num2;
					ss.clear();
					ss << str1;
					ss >> num1;
				}
				else if (strStack.size() == 1 && multiCal)
				{
					num1 = res;
					str2 = strStack.top();
					strStack.pop();
					ss.clear();
					ss << str2;
					ss >> num2;
				}
				if (t == "+")
				{
					res = num1 + num2;
					ss.clear();
					ss << res;
					ss >> resStr;
					strStack.push(resStr);
				}
				else if (t == "-")
				{
					res = num1 - num2;
					ss.clear();
					ss << res;
					ss >> resStr;
					strStack.push(resStr);
				}
				else if (t == "*")
				{
					res = num1*num2;
					ss.clear();
					ss << res;
					ss >> resStr;
					strStack.push(resStr);
				}
				else if (t == "/")
				{
					res = num1 / num2;
					ss.clear();
					ss << res;
					ss >> resStr;
					strStack.push(resStr);
				}
			}
		}
		return res;
	}
/*
	int main() {
		string a1 = "4";
		string a2 = "13";
		string a3 = "5";
		string a4 = "/";
		string a5 = "+";
		vector<string> token;
		token.push_back(a1);
		token.push_back(a2);
		token.push_back(a3);
		token.push_back(a4);
		token.push_back(a5);
		for (auto rt : token)
		{
			cout << rt << " ";
		}
		cout << endl;
		int res = evalRPN(token);
		cout << res << endl;
		system("pause");
	}
	*/