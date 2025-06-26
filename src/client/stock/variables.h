#include "shared.h"

#ifndef STOCK_API

#ifdef BUILDING_IW1X_DLL
#define STOCK_API __declspec(dllexport)
#else
#define STOCK_API __declspec(dllimport)
#endif

#endif

namespace stock
{
	/*STOCK_API extern const int MAX_STRING_CHARS;
	STOCK_API extern const int CS_SERVERINFO;
	STOCK_API extern const int CS_SYSTEMINFO;
	STOCK_API extern const int CVAR_ARCHIVE;
	STOCK_API extern const int KEYCATCH_CONSOLE;
	STOCK_API extern const int KEYCATCH_UI;
	STOCK_API extern const int KEYCATCH_MESSAGE;
	STOCK_API extern const int KEYCATCH_CGAME;
	STOCK_API extern const int EF_MG42_ACTIVE;
	STOCK_API extern const int YAW;
	STOCK_API extern const int FPS_FRAMES;//*/
	
	namespace cgame_mp
	{
		STOCK_API extern adjuster<cvarTable_t> cvarTable;
		STOCK_API extern adjuster<int (*)(int arg, ...)> syscall;
	}

	STOCK_API extern adjuster<int> cls_keyCatchers;
	STOCK_API extern adjuster<HWND> hWnd;
	STOCK_API extern adjuster<int> cmd_argc;
	STOCK_API extern adjuster<char*> cmd_argv;
	STOCK_API extern adjuster<float> viewangles;
	STOCK_API extern adjuster<float> cg_zoomSensitivity;
	STOCK_API extern adjuster<float> ads_progress; // Between 0 and 1, might be cg.zoomTime
	STOCK_API extern adjuster<float> fov_visible; // Not the cg_fov cvar value, might be cg.zoomval
	STOCK_API extern adjuster<pmove_t*> pm;
	STOCK_API extern adjuster<weaponInfo_t[]> cg_weapons;
	STOCK_API extern adjuster<qboolean> refreshActive;
	STOCK_API extern adjuster<qboolean> clc_demoplaying;
	STOCK_API extern adjuster<vm_t*> cgvm;
	STOCK_API extern adjuster<qboolean> mouseActive;
	STOCK_API extern adjuster<qboolean> mouseInitialized;
	STOCK_API extern adjuster<connstate_t> cls_state;
	STOCK_API extern adjuster<qboolean> clc_demorecording;
	STOCK_API extern adjuster<cvar_t[]> cvar_indexes;
	STOCK_API extern adjuster<netadr_t> clc_serverAddress;
	STOCK_API extern adjuster<netadr_t> cls_autoupdateServer;

	STOCK_API extern adjuster<int> width;
	STOCK_API extern adjuster<int> height;







	//WEAK adjuster<vm_t*> uivm{ 0, 0x0161747c };
	//WEAK adjuster<int> ping{ 0x41405d };
}

namespace cvars
{
	extern stock::cvar_t* r_fullscreen;
	extern stock::cvar_t* cl_bypassMouseInput;
	extern stock::cvar_t* cl_allowDownload;
	extern stock::cvar_t* con_boldgamemessagetime;
	extern stock::cvar_t* com_sv_running;
	extern stock::cvar_t* com_timescale;
	extern stock::cvar_t* sv_cheats;

	namespace vm
	{
		extern stock::vmCvar_t* cg_lagometer;
		extern stock::vmCvar_t* cg_fov;
		extern stock::vmCvar_t* cg_drawFPS;
		extern stock::vmCvar_t* cg_chatHeight;
	}
}