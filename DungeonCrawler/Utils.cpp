#include "Utils.h"


//Utils::Utils(void)
//{
//}
//
//
//Utils::~Utils(void)
//{
//}


string Utils::GetApplicationPath()
{
	char buffer[MAX_PATH];
	GetModuleFileName( NULL, buffer, MAX_PATH );

	char *pos = strrchr(buffer, '\\');
	if (pos != NULL) 
	   *pos = '\0';

	string appPath(buffer);
	return appPath;
}
