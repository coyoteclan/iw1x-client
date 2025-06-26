#ifndef STOCK_FUNCTIONS_H
#define STOCK_FUNCTIONS_H


#ifndef STOCK_API

#ifdef BUILDING_IW1X_DLL
#define STOCK_API __declspec(dllexport)
#else
#define STOCK_API __declspec(dllimport)
#endif

#endif

#include "stock/constants.h"

namespace stock
{
	STOCK_API int Cmd_Argc();
	STOCK_API char* Cmd_Argv(int arg);
	STOCK_API weaponInfo_t* BG_GetInfoForWeapon(int weaponNum);
	STOCK_API const char* Info_ValueForKey(const char* buffer, const char* key);
	STOCK_API void CL_MouseEvent(int _dx, int _dy);
	STOCK_API void PM_ClipVelocity(vec3_t _in, vec3_t normal, vec3_t _out, float overbounce);

	STOCK_API extern adjuster<void(float x, float y, int fontID, float scale, float* color, const char* text, float spaceBetweenChars, int maxChars, int arg9)> SCR_DrawString;
	STOCK_API extern adjuster<cvar_t* (const char* name)> Cvar_FindVar;
	STOCK_API extern adjuster<cvar_t* (const char* name, const char* value, int flags)> Cvar_Get;
	STOCK_API extern adjuster<cvar_t* (const char* name, const char* value)> Cvar_Set;
	STOCK_API extern adjuster<LRESULT CALLBACK(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)> MainWndProc;
	STOCK_API extern adjuster<void()> IN_DeactivateMouse;
	STOCK_API extern adjuster<void()> IN_ActivateMouse;	
	STOCK_API extern adjuster<void(const char* cmd_name, xcommand_t function)> Cmd_AddCommand;
	STOCK_API extern adjuster<void(int code, const char* fmt, ...)> Com_Error;
	STOCK_API extern adjuster<void(cbufExec_t exec_when, const char* text)> Cbuf_ExecuteText;
	STOCK_API extern adjuster<const char*(netadr_t a)> NET_AdrToString;
	STOCK_API extern adjuster<qboolean(netadr_t a, netadr_t b)> NET_CompareAdr;
	STOCK_API extern adjuster<void(float x, float y, float width, float height, qhandle_t hShader)> CG_DrawPic;

	//STOCK_API extern adjuster<void(int x, int y, int width, int height, char *fileName)> R_TakeScreenshot;
	STOCK_API extern void R_TakeScreenshot(int x, int y, int width, int height, char* fileName);






	//WEAK adjuster<void(float x, float y, float width, float height, qhandle_t hShader)> SCR_DrawPic{ 0x004168d0 };
	//WEAK adjuster<void(float x, float y, const char* s, float alpha)> CG_DrawBigString{ 0x30019710, BASE_CGAME_MP };
	//WEAK adjuster<void(const char* msg, ...)> Com_Printf{ 0x004357b0 };
	//WEAK adjuster<void()> CL_Disconnect_f{ 0x0040f5f0 };
	//WEAK symbol<int(vm_t* vm, int callnum, ...)> VM_Call{ 0, 0x00460480 };
}

#endif
