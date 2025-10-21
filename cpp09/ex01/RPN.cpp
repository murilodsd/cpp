#include "RPN.hpp"
#include <limits>

// ==================== Constructors ====================
RPN::RPN()
{
}

int RPN::check_expression(const char *expression)
{
	int count_n = 0;
	int count_op = 0;

	std::istringstream iss(expression);
	std::string arg;
	while (iss >> arg)
	{
		if (arg.size() != 1 )
			throw std::logic_error("The args must be a number between 0 and 9 or *, +, - and /");
		if (arg[0] >= '0' && arg[0] <= '9')
			count_n++;
		else if (arg[0] == '-' || arg[0] == '+' || arg[0] == '*' || arg[0] == '/')
			count_op++;
		else
			throw std::logic_error("The args must be a number between 0 and 9 or *, +, - and /");
		if (count_op > 0 && count_n <= count_op)
			throw std::logic_error("This is not a valid expression");
	}
	if (count_n != count_op + 1)
		throw std::logic_error("This is not a valid expression");
	return count_n;
}

static void executeOperation(std::stack<int> &int_stack, char math_operator)
{
	int second = int_stack.top();
	int_stack.pop();
	int first = int_stack.top();
	int_stack.pop();
	switch (math_operator)
	{
		case '+':
			if (second > 0 && first > std::numeric_limits<int>::max() - second)
				throw std::overflow_error("Overflow detected in addition");
			if (second < 0 && first < std::numeric_limits<int>::min() - second)
				throw std::overflow_error("Underflow detected in addition");
			int_stack.push(first + second);
			break;
		case '-':
			if (second < 0 && first > std::numeric_limits<int>::max() + second)
				throw std::overflow_error("Overflow detected in subtraction");
			if (second > 0 && first < std::numeric_limits<int>::min() + second)
				throw std::overflow_error("Underflow detected in subtraction");
			int_stack.push(first - second);
			break;
		case '*':
			if (first != 0 && second != 0) {
				// Overflow positivo (ambos positivos)
				if (first > 0 && second > 0 && first > std::numeric_limits<int>::max() / second)
					throw std::overflow_error("Overflow detected in multiplication");
				// Overflow positivo (ambos negativos -> resultado positivo)
				if (first < 0 && second < 0 && first < std::numeric_limits<int>::max() / second)
					throw std::overflow_error("Overflow detected in multiplication");
				// Underflow (um positivo e um negativo)
				if (first > 0 && second < 0 && second < std::numeric_limits<int>::min() / first)
					throw std::overflow_error("Underflow detected in multiplication");
				if (first < 0 && second > 0 && first < std::numeric_limits<int>::min() / second)
					throw std::overflow_error("Underflow detected in multiplication");
			}
			int_stack.push(first * second);
			break;
		case '/':
			if (second == 0)
				throw std::logic_error("Division by 0");
			int_stack.push(first / second);
			break;
		default:
			throw std::logic_error("Operator doesn't exist.");
			break;
	}
}

static void execute_expression(const char *expression, std::stack<int> &int_stack)
{
	std::istringstream iss(expression);
	std::string arg;
	while (iss >> arg)
	{
		if (arg >= "0" && arg <= "9")
			int_stack.push(arg[0] - '0');
		else
			executeOperation(int_stack, arg[0]);
	}
}

int RPN::calculate(const char *expression)
{
	std::stack<int> int_stack;
	
	if (check_expression(expression) == 1)
		return std::atoi(expression);

	execute_expression(expression, int_stack);
	
	return int_stack.top();
}

// ================= Copy Constructor ==================
RPN::RPN(const RPN &other)
{
	(void)other;
}

// ========== Copy Assignment Operator Overload ==========
RPN &RPN::operator=(const RPN &other)
{
	(void) other;
	return *this;
}

// ==================== Destructor =====================
RPN::~RPN()
{
}
// ================= Auxiliar Functions =================

// ================== Member Functions ==================
