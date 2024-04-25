#pragma once

#include <Windows.h>
#include "includes.h"

DWORD GetProcessID(const wchar_t* procName);

DWORD GetModuleBaseAddress(DWORD procId, const wchar_t* modname);
