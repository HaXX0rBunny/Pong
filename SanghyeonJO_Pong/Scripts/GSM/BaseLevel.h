#pragma once

namespace GSM
{
	class BaseLevel
	{
		//Pure Abstract - Can not be instantiated
		//Others will inherit form me, I am just an Interface

	public:
		//Init
		virtual void Init()=0;
		//Updat
		virtual void Update()=0;
		//Exit
		virtual void Exit()=0;

		//Other functionality
		//Private data
	};
}