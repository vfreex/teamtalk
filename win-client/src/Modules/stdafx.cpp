// stdafx.cpp : 只包括标准包含文件的源文件
// Modules.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// Workaround error LNK2005: _DllMain@12 already defined in MSVCRT.lib(dllmain.obj)
// https://social.msdn.microsoft.com/Forums/en-US/0d78aa6b-1e87-4c01-a4a7-691335b7351a/how-to-build-mfc-application-dll-in-visual-c-2010
extern "C" { int _afxForceUSRDLL; }