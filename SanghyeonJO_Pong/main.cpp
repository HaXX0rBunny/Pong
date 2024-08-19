// ---------------------------------------------------------------------------
// includes

#include <crtdbg.h> // To check for memory leaks
#include "AEEngine.h"
#include "GSM/GameStateManager.h"
#include "GSM/MainLevel.h"
#include "GSM/GoalLevel.h"
#include "RTTI/Registry.h"
#include "RTTI/BaseRTTI.h"
// ---------------------------------------------------------------------------
// main

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);


	int gGameRunning = 1;

	// Initialization of your own variables go here

	// Using custom window procedure
	AESysInit(hInstance, nCmdShow, 1600, 900, 1, 60, true, NULL);

	// Changing the window title
	AESysSetWindowTitle("AESir");

	GSM::GameStateManager* gsm = GSM::GameStateManager::GetGSMPtr();
	//Test RTTI

//	Registry* RTTIptr = Registry::GetPtr();

	//Find the function, call the function and store that BaseRTTI*
	//BaseRTTI* p = RTTIptr->FindAndCreate("TransformComp");
	//p->Load("AAA"); // This should call to TransformComp::Load(string)
	//delete p;// This should call to TransformComp::~TransformComp()

	//Test for each comp
	//Test INVALID name on the find

	//Registry::Delete();

	
	// reset the system modules
	AESysReset();

	
	gsm->ChangeLevel(new Levels::MainLevel);

	// Game Loop
	while (gsm->ShouldExit() == false)
	{
		// Informing the system about the loop's start
		AESysFrameStart();


		// Your own update logic goes here
		gsm->Update();


		// Informing the system about the loop's end
		AESysFrameEnd();

		// check if forcing the application to quit
		if (AEInputCheckTriggered(AEVK_ESCAPE) || 0 == AESysDoesWindowExist())
			gsm->ChangeLevel(new Levels::GoalLevel);
	}
	gsm->DeleteGSM();
	//GSM::GameStateManager->Delete();
	//GOM::Delete();
	//Registry::Delete();
	// free the system
	AESysExit();
}
/*
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <pair>
int randomRange(int min, int max)
{
	return std::rand()%(max=min)+min;
}
void PrintVec(const std::vector<int>& v)
{
for(int i:v)
std::cout<<i<<"";
std::cout <<std::endl;
}
void PrintVec(const std::vector<std::pair<int, std::string>>& v)
{
for(const std::pair<int,std::string>&i:v)
std::cout<<"["<<i.first<<" "<<i.second <<"] ";
std::cout <<std::endl;
}
bool SortFn(int a, int b)
{
return a>b;
}
bool addFirst(int a, int b)
{
if(a%2 !=b%2)
{
return a<b;
}
else
{
return (a%2) ==1;
}
}
bool SortN(int a, int b, int n)
{
if(a>n)
{
return Sort(a,b);
}
else
{
return addFirst(a,b);
}
}
class Functor
{
	int n;
public:
	Functor(in i) :m(i){}
bool operator()(int a, int b)
{
return SortN(a,b,n);
}
int operaotr()()<void>{return n;}
}
bool SortPair(const std::pair<int, std::string>& a, const std::pair<int, std::string>& a2)
{
return a.fist<b.first;
}

bool IsPairIntEqual()
{
	return a.first ==b;
}


class FunctorFind
{
int b;
public:
FunctorFinc(int B): b(B){}

bool operator()(const std::pair<int, std::string>& a)
{
	return IspairIntEqual(a,b);
}
}

int main()
{
std::vector<int> numbers
std::vecto<std::Pair<int, std::string>> pairVec;

for(int i = 0.i<10.i++)
	pairVec.push_back(std::piar<int, std::string>(randomRange(0,10, std::string(1,'a'+i)));
	PrintVec(pairVec);
	std::sort(pairVec.begin(0, pairVec.end());
	PrintVec(pairVec);
	//std::find(pairVec.begin(), pairVec.end(),2);

	//std::find_if(pairVec.begin(), pairVec.end(),IsPairIntEqual);

	auto res = std::find_if(pairVec.begin(), pairVec.end(),FunctorFind(2));

Functor f(6);

f.operator()(4,5);
f(4,5);
f();

for(int i=0;i<10;i++)
{
numbers.push_back(randomRange(0,10))
}
PrintVec(numbers);

std::sort(number.begin(), numbers.end()); //operator <
PrintVec(numbers);


std::sort(number.begin(), numbers.end(),SortFn); //SortFn(operator >)
PrintVec(numbers);

std::sort(number.begin(), numbers.end(),addFirst); //SortFn(operator >)
PrintVec(numbers);


//std::sort(number.begin(), numbers.end(),SortN); //SortFn(operator >)
//PrintVec(numbers);


std::sort(number.begin(), numbers.end(),f); //SortFn(operator >)
PrintVec(numbers);



std::sort(number.begin(), numbers.end(),Functor(3)); //SortFn(operator >)
PrintVec(numbers);

return 0;


}


*/