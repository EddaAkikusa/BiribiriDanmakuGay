#pragma once

#include <WinSock2.h>
#include <Windows.h>

extern IMAGE_DOS_HEADER __ImageBase;

static HINSTANCE GetInstance(void)
{
    return (HINSTANCE)&__ImageBase;
}

#include "resource.h"
#include "session.h"
