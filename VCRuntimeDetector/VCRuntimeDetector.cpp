// VCRuntimeDetector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	wcout << _T("Checking for the availability of VC++ runtimes..") << endl;
	wcout << _T("----------- Visual C++ 2008 (VC++9) -----------") << endl;
	wcout << _T("Visual C++ 2008 (x86) ? ") << (IsVC2008Installed_x86() ? _T("true") : _T("false")) << endl;
	wcout << _T("Visual C++ 2008 (x64) ? ") << (IsVC2008Installed_x64() ? _T("true") : _T("false")) << endl;
	wcout << _T("Visual C++ 2008 SP1 (x86) ? ") << (IsVC2008SP1Installed_x86() ? _T("true") : _T("false")) << endl;
	wcout << _T("Visual C++ 2008 SP1 (x64) ? ") << (IsVC2008SP1Installed_x64() ? _T("true") : _T("false")) << endl;

	wcout << _T("----------- Visual C++ 2010 (VC++10) -----------") << endl;	
	wcout << _T("Visual C++ 2010 (x86) ? ") << (IsVC2010Installed_x86() ? _T("true") : _T("false")) << endl;
	wcout << _T("Visual C++ 2010 (x64) ? ") << (IsVC2010Installed_x64() ? _T("true") : _T("false")) << endl;
	wcout << _T("Visual C++ 2010 SP1 (x86) ? ") << (IsVC2010SP1Installed_x86() ? _T("true") : _T("false")) << endl;
	wcout << _T("Visual C++ 2010 SP1 (x64) ? ") << (IsVC2010SP1Installed_x64() ? _T("true") : _T("false")) << endl;

	wcout << _T("----------- CHECKING FOR VC++ BINARIES IN CURRENT DIRECTORY -----------") << endl;

	wcout << _T("----------- Visual C++ 2008 (VC++9) -----------") << endl;
	wcout << _T("Visual C++ 2008 (x86) ? ") << (IsVC2008AvailableLocally_x86() ? _T("true") : _T("false")) << endl;
	wcout << _T("Visual C++ 2008 (x64) ? ") << (IsVC2008AvailableLocally_x64() ? _T("true") : _T("false")) << endl;

	wcout << _T("----------- Visual C++ 2010 (VC++10) -----------") << endl;
	wcout << _T("Visual C++ 2010 (x86) ? ") << (IsVC2010AvailableLocally_x86() ? _T("true") : _T("false")) << endl;
	wcout << _T("Visual C++ 2010 (x64) ? ") << (IsVC2010AvailableLocally_x64() ? _T("true") : _T("false")) << endl;

	wcout << _T("----------- END -----------") << endl;
	wcout << _T("Enter a number and press enter to exit.") << endl;
	int stop;
	cin >> stop;
	return 0;
}

