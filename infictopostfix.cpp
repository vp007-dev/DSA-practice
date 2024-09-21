#include<iostream>
#include<stack>
#include<string>

using namespace std;

string infixToPostfix(string exp);
int HasHigherPrecedence(char operator1, char operator2);
bool IsOperator(char C);
bool IsOperand(char C);


int main(){
    string exp = "3 + 4 / 3 + 5 * 5 (45 / 5 * 25)";
    string postfix = infixToPostfix(exp);
    cout << postfix << endl;

}

string infixToPostfix(string exp){
    stack<char> S;
    string postfix = "";
    for(int i = 0; i < exp.length(); i++){
        if(exp[i] == ' ' || exp[i] == ',') continue;
        else if(IsOperator(exp[i])){
            while(!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), exp[i])){
                postfix += S.top();
                S.pop();
            }
            S.push(exp[i]);
        }
        else if(IsOperand(exp[i])){
            postfix += exp[i];
        }
        else if(exp[i] == '('){
            S.push(exp[i]);
        }
        else if(exp[i] == ')'){
            while(!S.empty() && S.top() !=  '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
        }
    }
    while(!S.empty()){
        postfix += S.top();
        S.pop();
    }

    return postfix;
}


bool IsOperand(char C) 
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
		return true;

	return false;
}

int IsRightAssociative(char op)
{
	if(op == '$') return true;
	return false;
}

int GetOperatorWeight(char op)
{
	int weight = -1; 
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}

int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}