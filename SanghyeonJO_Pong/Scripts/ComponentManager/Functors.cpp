#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <map>

//Helper functions
int randomRange(int min, int max)
{
	return std::rand() % (max - min) + min;
}

void PrintVec(const std::vector<int>& v)
{
	for (int i : v)
		std::cout << i << " ";

	std::cout << std::endl;
}

void PrintVec(const std::vector< std::pair<int, std::string>>& v)
{
	for (const std::pair<int,std::string>& i : v)
		std::cout << "[" << i.first << " " << i.second << "] ";

	std::cout << std::endl;
}


//Sorting  functions.
// Returns bool and input parameters are the 2 elements to compare (2 ints)
bool SortFn(int a, int b)
{
	return a > b;
}

bool oddFirst(int a, int b)
{
	if (a % 2 == b % 2)
	{
		return a < b;
	}
	else
	{
		return (a % 2) == 1;
	}
}

//This can NOT be inputed on a sort function. It takes 3 parameters, while the sort fn only takes 2
bool SortN(int a, int b, int n)
{
	if (a < n)
		return SortFn(a, b);
	else
		return oddFirst(a, b);
}

//We can use a functor to solve it!
class Functor
{
	int n;
public:

	Functor(int i) : n(i) {}

	//This allows for an object of this class to be "used as a function" of the given parameters
	bool operator()(int a, int b)
	{
		return SortN(a, b, n);
	}

	//This allows for an object of this class to be "used as a function" of the given parameters
	int operator()(void){ return n; }
};

//Sorts 2 pairs
bool SortPair(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b)
{
	return a.first < b.first;
}

//Check a pair and an int. This is NOT a find function as the parameters are not equal
bool IsPairIntEqual(const std::pair<int, std::string>& a, int b)
{
	return a.first == b;
}

//We can make a functor to solve it!
class FunctorFind
{
	int b;
public:

	FunctorFind(int B) : b(B) {}
	//std::find_if returns true when the call to a function that takes only one T parameter is true
	bool operator()(const std::pair<int, std::string>& a)
	{
		//Use my b value, set at constructor
		return IsPairIntEqual(a, b);
	}
};

void test1()
{
	std::vector<int> numbers;
	Functor f(6);

	f.operator()(4, 5);
	f(4, 5);
	f();

	for (int i = 0; i < 10; i++)
	{
		numbers.push_back(randomRange(0, 10));
	}

	PrintVec(numbers);

	std::sort(numbers.begin(), numbers.end());	//operator <
	PrintVec(numbers);

	std::sort(numbers.begin(), numbers.end(), SortFn);	//SortFn (operator >)
	PrintVec(numbers);

	std::sort(numbers.begin(), numbers.end(), oddFirst);	//SortFn (operator >)
	PrintVec(numbers);

	//std::sort(numbers.begin(), numbers.end(), SortN);	//SortFn (operator >)
	//PrintVec(numbers);

	std::sort(numbers.begin(), numbers.end(), f);	//SortFn (operator >)
	PrintVec(numbers);

	std::sort(numbers.begin(), numbers.end(), Functor(3));	//SortFn (operator >)
	PrintVec(numbers);


}
void test2()
{
	std::vector<std::pair<int, std::string> > pairVec;

	for(int i = 0; i < 10; i++)
		pairVec.push_back(std::pair<int, std::string>(randomRange(0, 10), std::string(1,'a' + i)));

	PrintVec(pairVec);

	std::sort(pairVec.begin(), pairVec.end(), SortPair);
	PrintVec(pairVec);

	//std::find(pairVec.begin(), pairVec.end(), 2);
	//std::find_if(pairVec.begin(), pairVec.end(), IsPairIntEqual);
	auto res = std::find_if(pairVec.begin(), pairVec.end(), FunctorFind(2));
}

int main()
{
	test1();
	test2();
	return 0;
}

//Todo