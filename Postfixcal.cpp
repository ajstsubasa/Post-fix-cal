
//Name: Abayjeet Singh
//Assignment 3
//A Post-Fix Calculator.

#include<iostream>
#include<sstream>
#include<string>
#include<stack>
#include<cctype>
#include<cmath>
bool isoperator(const char & input);
double perform_operation(const char& op);
bool isInvalid(const char &op);

using namespace std;
stack<double> mystack;

int main()
{
	while (1)
	{
		char quit;
		cout << " Welcome to the postfix calculator , Please enter values in Postfix Form :" << endl;
		
		string expression;
		int i = 0;
		double num;

		getline(cin, expression);
		double result = 0.0;



		string number;
		while (expression[i] != '\0')
		{
			stringstream sso;

			if (expression[i] == '-')
			{
				
				
			}
			if (isdigit(expression[i]))
			{
			
				number += expression[i];
			


			}
			
		
			if (expression[i] == '.')
			{
				number += '.';
			
			}

			if (isspace(expression[i]) && !isoperator(expression[i - 1]))
			{
				//cout << number << " ";
				sso << number;
				sso >> num;
			
				//cout << num << " ";
				mystack.push(num);
	
				number = " ";

			}

			if (isoperator(expression[i]))
			{
				if (isInvalid(expression[i]))
				{
					cout << "Invalid expression" << endl;
					system("pause");
					return 0;
				}
				result = perform_operation(expression[i]);
			}

			if (!isoperator(expression[i]) && expression[i + 1] == '\0')
			{
				//cout << number << " ";
				sso << number;
				sso >> num;
				//cout << num << " ";
				mystack.push(num);
				number = " ";

			}


			i++;

			

		}
		if (mystack.size() > 1)
		{


			cout << "Invalid Expression" << endl;
			system("pause");
			return -1;
		}
		if (!isfinite(result))
		{
			cout << "Result is Infinity " << endl;
			system("pause");
			return -1;
		}

		cout << "The Result is  :" << result << endl;
		system("pause");
		cout << endl;
		cout << " Enter q to quit or and c to continue calculating" << endl;
		cin >> quit;

		if (quit == 'q')
		{
			break;
		}
		cin.ignore();
		while (!(mystack.empty()))
		{
			mystack.pop();

		}
		
		
	}
	

	
}
bool isoperator(const char & input)
{
	char  op[] = { '+','-','*','/','S','!','~','$','^' };
	for (int i = 0; i < 9; i++)
	{
		if(input==op[i])
		{
			return true;
		}
	}
	return false;

}
double perform_operation(const char& op)
{
	double rval = 0;
	double lval = 0;
	double result = 1;
	/*
	if (mystack.empty())
	{
		throw logic_error("Not a valid expression");
	
	}
	*/
	rval = mystack.top();
	mystack.pop();
	if (op != '~' && op!='!' &&op !='S' &&op!='$')

	{
		if (mystack.size() != 0)
		{
			lval = mystack.top();
			mystack.pop();
		}
	}
	
	if (op == '+')
	{
		//cout <<lval << "  " << rval << endl;
		result = rval + lval;
		mystack.push(result);
	}
	 else if (op == '-')
	{
		 //cout << lval << "  " << rval << endl;
		result =lval - rval;
		mystack.push(result);
	}
	 else if (op == '*')
	 {
		 //cout << lval << "  " << rval << endl;
		 result = lval * rval;
		 mystack.push(result);
	 }
	 else if (op == '/')
	 {
		 //cout << lval << "  " << rval << endl;
		 result = lval / rval;
		 mystack.push(result);
	 }
	 else if (op == '~')
	 {
		 
		 result = - ( rval);
		 mystack.push(result);
	 }
	 else if (op == '!')
	 {
		 while (rval >= 1)
		 {
			 
			 result = result * rval;
			
			 rval =rval - 1;
		 }
		 mystack.push(result);
	 }
	 else if (op == 'S' || op=='$')
	 {
		
		 result = 0;
		 int i = 0;
		 while (i < rval)
		 {
			
			 result += mystack.top();
			 mystack.pop();
		
			 i++;
		 }
		 if (op == '$')
		 {
			 mystack.push(result / rval);
		 }
		 else
		 {
			 mystack.push(result);
		 }

	 }
	 else if (op == '^')
	 {
		 if (lval == 0)
		 {
			 result = 0;
			 mystack.push(result);
	     }
		 else if (rval == 0)
		 {
			 result = 1;
			 mystack.push(result);
		 }
		 
		 else
		 {
			 result = pow(lval, rval);

			 mystack.push(result);
		 }
		 

		 

	}
	return result;

}
bool isInvalid(const char&op)
{


	if (op == '/' || op == '*' || op == '-' || op == '+')
	{
		if (mystack.size() <= 1)
		{
			return true;
		}
	}
	if (op == '/')
	{

		if (mystack.top() == 0)
		{
			return true;
		}
	}
	if (op == '!')
	{
		if (mystack.top()<=0)
		{
			return true;
		}
	}

	if (op == 'S')
	{
		if (mystack.top() > (mystack.size() - 1))
		{
			
			return true;
		}
	}
	if (op == '$')
	{
		if (mystack.top() > (mystack.size() - 1))
		{

			return true;
		}
		if (mystack.top() == 0)
		{
			return true;
		}
	}
	if (mystack.size() == 0)
	{
		return true;
	}
	return false;
}