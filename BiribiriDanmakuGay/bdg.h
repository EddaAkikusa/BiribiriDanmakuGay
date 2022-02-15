#pragma once
#include <Windows.h>
#include "resource.h"

extern IMAGE_DOS_HEADER __ImageBase;
HINSTANCE g_hInstance = (HINSTANCE)&__ImageBase;
