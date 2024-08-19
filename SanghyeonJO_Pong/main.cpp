// ---------------------------------------------------------------------------
// includes

#include <crtdbg.h> // To check for memory leaks
#include "AEEngine.h"

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





	
		// Informing the system about the loop's start
		AESysFrameStart();


		// Informing the system about the loop's end
		AESysFrameEnd();

	//GSM::GameStateManager->Delete();
	//GOM::Delete();
	//Registry::Delete();
	// free the system
	AESysExit();
}