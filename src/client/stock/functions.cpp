#include "pch.h"

#include "shared.h"

namespace stock
{
	uintptr_t addr_CL_MouseEvent = 0x0040b0a0;

	int Cmd_Argc()
	{
		return *cmd_argc;
	}
	
	char* Cmd_Argv(int arg)
	{
		return cmd_argv[arg];
	}
	
	weaponInfo_t* BG_GetInfoForWeapon(int weaponNum)
	{
		auto cg_weapons_ptr = *reinterpret_cast<uintptr_t*>(*cg_weapons);
		return reinterpret_cast<weaponInfo_t**>(cg_weapons_ptr)[weaponNum];
	}
	
	const char* Info_ValueForKey(const char* buffer, const char* key)
	{
		__asm
		{
			mov ebx, key;
			mov ecx, buffer;
			mov eax, 0x0044ada0;
			call eax;
		}
	}
	
	void CL_MouseEvent(int _dx, int _dy)
	{
		__asm
		{
			mov ecx, _dx;
			push eax;
			mov eax, _dy;
			call addr_CL_MouseEvent;
			add esp, 0x4;
		}
	}
	
	void PM_ClipVelocity(vec3_t _in, vec3_t normal, vec3_t _out, float overbounce)
	{
		uintptr_t addr_PM_ClipVelocity = ABSOLUTE_CGAME_MP(0x30007380);
		__asm
		{
			push overbounce;
			mov esi, _out;
			mov ecx, normal;
			mov edx, _in;
			call addr_PM_ClipVelocity;
			add esp, 0x4;
		}
	}

	WEAK adjuster<void(float x, float y, int fontID, float scale, float* color, const char* text, float spaceBetweenChars, int maxChars, int arg9)> SCR_DrawString{ 0x004df570 };
	WEAK adjuster<cvar_t* (const char* name)> Cvar_FindVar{ 0x00439280 };
	WEAK adjuster<cvar_t* (const char* name, const char* value, int flags)> Cvar_Get{ 0x00439350 };
	WEAK adjuster<cvar_t* (const char* name, const char* value)> Cvar_Set{ 0x00439650 };
	WEAK adjuster<LRESULT CALLBACK(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)> MainWndProc{ 0x466BE0 };
	WEAK adjuster<void()> IN_DeactivateMouse{ 0x4616b0 };
	WEAK adjuster<void()> IN_ActivateMouse{ 0x461730 };	
	WEAK adjuster<void(const char* cmd_name, xcommand_t function)> Cmd_AddCommand{ 0x00428840 };
	WEAK adjuster<void(int code, const char* fmt, ...)> Com_Error{ 0x00435ad0 };
	WEAK adjuster<void(cbufExec_t exec_when, const char* text)> Cbuf_ExecuteText{ 0x00428290 };
	WEAK adjuster<const char*(netadr_t a)> NET_AdrToString{ 0x00449150 };
	WEAK adjuster<qboolean(netadr_t a, netadr_t b)> NET_CompareAdr{ 0x00449230 };
	WEAK adjuster<void(float x, float y, float width, float height, qhandle_t hShader)> CG_DrawPic{ 0x300192d0, BASE_CGAME_MP };

	//WEAK adjuster<void(int x, int y, int width, int height, char *fileName)> R_TakeScreenshot{ 0x004b0f90 };
	// it appears the function needs to be called using asm

	void R_TakeScreenshot(int x, int y, int width, int height, char* fileName)
	{
		/*
		from ida:
		mov     eax, dwExStyle (width probably)
		lea     edx, [esp+110h+var_104]
		push    edx
		push    eax
		mov     eax, dwStyle (height probably)
		push    0 (x)
		push    0 (y)
		call    R_TakeScreenshot (0x4B0F90)
		*/
		uintptr_t addr_R_TakeScreenshot = 0x004b0f90; // R_TakeScreenshotJPEG 004B10A0 // R_TakeScreenshot 0x004b0f90
		__asm
		{
			mov eax, width;
			lea edx, [esp + 0x100 + fileName]; // doesn't work
			push edx;
			push eax;
			mov eax, height;
			push 0; // x
			push 0; // y
			call addr_R_TakeScreenshot;
			add esp, 0x14;
		}
	}
}
