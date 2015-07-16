#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <windows.h>
#include <windowsx.h>

using namespace std;

namespace GodEngine
{
	typedef unsigned char uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint32;
	typedef unsigned long long uint64;

#if USE_DOUBLE_PRECISION == 1
	typedef double Real;
#else
	typedef float Real;
#endif

	typedef string String;
	typedef stringstream StringStream;
	typedef map<String, String> Dictionary;

}