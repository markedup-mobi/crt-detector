#include "stdafx.h"

// Constants used to represent the MSI product CODES for all of the runtimes
const LPCTSTR _vc2008x86Code = TEXT("{FF66E9F6-83E7-3A3E-AF14-8DE9A809A6A4}");
const LPCTSTR _vc2008x64Code = TEXT("{350AA351-21FA-3270-8B7A-835434E766AD}");
const LPCTSTR _vc2008SP1x86Code = TEXT("{9A25302D-30C0-39D9-BD6F-21E6EC160475}");
const LPCTSTR _vc2008SP1x64Code = TEXT("{8220EEFE-38CD-377E-8595-13398D740ACE}");

const LPCTSTR _vc2010x86Code = TEXT("{196BB40D-1578-3D01-B289-BEFC77A11A1E}");
const LPCTSTR _vc2010x64Code = TEXT("{DA5E371C-6333-3D8A-93A4-6FD5B20BCC6E}");
const LPCTSTR _vc2010SP1x86Code = TEXT("{F0C3E5D1-1ADE-321E-8167-68EF0DE699A5}");
const LPCTSTR _vc2010SP1x64Code = TEXT("{1D8E6291-B0D5-35EC-8441-6616F567A0F7}");

// Constants used to represent the MSI product FILE NAMES for all of the runtimes pre-VC++10
const LPCTSTR _vc2008x86FolderName = TEXT("x86_microsoft.vc90.crt_1fc8b3b9a1e18e3b_9.0.21022*");
const LPCTSTR _vc2008x64FolderName = TEXT("amd64_microsoft.vc90.crt_1fc8b3b9a1e18e3b_9.0.21022*");
const LPCTSTR _vc2008SP1x86FolderName = TEXT("x86_microsoft.vc90.crt_1fc8b3b9a1e18e3b_9.0.30729*");
const LPCTSTR _vc2008SP1x64FolderName = TEXT("amd64_microsoft.vc90.crt_1fc8b3b9a1e18e3b_9.0.30729*");

// Global constants and variables used in file-lookup queries
const LPCTSTR _winSxSFolderName = TEXT("WinSXS");

/******************************************************************
Function Name:  CheckProductUsingMsiQueryProductState
Description:    Uses Microsoft Installer (MSI) instrumentation to check
for the availability of Microsoft products using its product codes.
Inputs:         pszProductToCheck - product code to look up
Results:        true if the requested product is installed
false otherwise
******************************************************************/
bool CheckProductUsingMsiQueryProductState(const LPCTSTR pszProductToCheck){
	bool bFoundRequestedProduct = false;
	INSTALLSTATE ir = INSTALLSTATE_UNKNOWN;

	// Check input parameter
	if (NULL == pszProductToCheck)
		return false;

	ir = MsiQueryProductStateW(pszProductToCheck);
	bFoundRequestedProduct = (ir == INSTALLSTATE_DEFAULT);
	return bFoundRequestedProduct;
}

/******************************************************************
Function Name:  GetWinSXSDirectory
Description:    Gets the path of the $WINDIR/WinSxS folder.
Inputs:         NONE
Results:        a string containing the path to the folder if found,
NULL otherwise.
******************************************************************/
LPCTSTR GetWinSXSDirectory(){
	LPCTSTR strDirectory = NULL;

	//Load the Windows directory
	TCHAR windir[MAX_PATH];
	GetWindowsDirectory(windir, MAX_PATH);

	TCHAR buffer[MAX_PATH];
	if (PathCombine(buffer, windir, _winSxSFolderName) != NULL){
		//operation succeeded!
		strDirectory = buffer;
	}

	return strDirectory;
}

/******************************************************************
Function Name:  CheckProductUsingWinSxSFolder
Description:    Queries the $WINDIR/WinSxS folder for the appropriate
install path for the requested product.
Inputs:         pszProductToCheck - the product name to look up.
Results:        true if the requested product is installed
false otherwise
******************************************************************/
bool CheckProductUsingWinSxSFolder(const LPCTSTR pszProductToCheck){
	bool bFoundRequestedProduct = false;

	LPCTSTR strWinSxSDir = GetWinSXSDirectory();

	if (strWinSxSDir != NULL){
		TCHAR searchPath[MAX_PATH];
		if (PathCombine(searchPath, strWinSxSDir, pszProductToCheck) != NULL){
			WIN32_FIND_DATA FindFileData;
			HANDLE hFind;
			hFind = FindFirstFile(searchPath, &FindFileData);
			if (hFind != INVALID_HANDLE_VALUE){ //found it!
				bFoundRequestedProduct = true;
				FindClose(hFind);
			}
		}
		
	}

	return bFoundRequestedProduct;
}


/******************************************************************
Function Name:  IsVC2008Installed_x86
Description:    Checks if the VC++9 runtime for x86 is installed on this machine.
Inputs:         NONE
Results:        true if the VC++9 runtime for x86 is installed
false otherwise
******************************************************************/
bool IsVC2008Installed_x86(){
	return CheckProductUsingMsiQueryProductState(_vc2008x86Code) || CheckProductUsingWinSxSFolder(_vc2008x86FolderName);
}

/******************************************************************
Function Name:  IsVC2008Installed_x64
Description:    Checks if the VC++9 runtime for x64 is installed on this machine.
Inputs:         NONE
Results:        true if the VC++9 runtime for x64 is installed
false otherwise
******************************************************************/
bool IsVC2008Installed_x64(){
	return CheckProductUsingMsiQueryProductState(_vc2008x64Code) || CheckProductUsingWinSxSFolder(_vc2008x64FolderName);
}

/******************************************************************
Function Name:  IsVC2008SP1Installed_x86
Description:    Checks if the VC++9 runtime (SP1) for x86 is installed on this machine.
Inputs:         NONE
Results:        true if the VC++9 runtime (SP1) for x86 is installed
false otherwise
******************************************************************/
bool IsVC2008SP1Installed_x86(){
	return CheckProductUsingMsiQueryProductState(_vc2008SP1x86Code) || CheckProductUsingWinSxSFolder(_vc2008SP1x86FolderName);
}

/******************************************************************
Function Name:  IsVC2008SP1Installed_x64
Description:    Checks if the VC++9 runtime (SP1) for x64 is installed on this machine.
Inputs:         NONE
Results:        true if the VC++9 runtime (SP1) for x64 is installed
false otherwise
******************************************************************/
bool IsVC2008SP1Installed_x64(){
	return CheckProductUsingMsiQueryProductState(_vc2008SP1x64Code) || CheckProductUsingWinSxSFolder(_vc2008SP1x64FolderName);
}

/******************************************************************
Function Name:  IsVC2010Installed_x86
Description:    Checks if the VC++10 runtime for x86 is installed on this machine.
Inputs:         NONE
Results:        true if the VC++10 runtime for x86 is installed
false otherwise
******************************************************************/
bool IsVC2010Installed_x86(){
	return CheckProductUsingMsiQueryProductState(_vc2010x86Code);
}

/******************************************************************
Function Name:  IsVC2010Installed_x64
Description:    Checks if the VC++10 runtime for x64 is installed on this machine.
Inputs:         NONE
Results:        true if the VC++10 runtime for x64 is installed
false otherwise
******************************************************************/
bool IsVC2010Installed_x64(){
	return CheckProductUsingMsiQueryProductState(_vc2010x64Code);
}

/******************************************************************
Function Name:  IsVC2010SP1Installed_x86
Description:    Checks if the VC++10 runtime (SP1) for x86 is installed on this machine.
Inputs:         NONE
Results:        true if the VC++10 runtime (SP1) for x86 is installed
false otherwise
******************************************************************/
bool IsVC2010SP1Installed_x86(){
	return CheckProductUsingMsiQueryProductState(_vc2010SP1x86Code);
}

/******************************************************************
Function Name:  IsVC2010SP1Installed_x64
Description:    Checks if the VC++9 runtime (SP1) for x64 is installed on this machine.
Inputs:         NONE
Results:        true if the VC++9 runtime (SP1) for x64 is installed
false otherwise
******************************************************************/
bool IsVC2010SP1Installed_x64(){
	return CheckProductUsingMsiQueryProductState(_vc2010SP1x64Code);
}