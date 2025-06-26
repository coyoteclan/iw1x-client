#include "pch.h"
#include "variables.h"

namespace stock
{
	/*const int MAX_STRING_CHARS = 1024;
	const int CS_SERVERINFO = 0;
	const int CS_SYSTEMINFO = 1;
	const int CVAR_ARCHIVE = 1;
	const int KEYCATCH_CONSOLE = 0x0001;
	const int KEYCATCH_UI = 0x0002;
	const int KEYCATCH_MESSAGE = 0x0004;
	const int KEYCATCH_CGAME = 0x0008;
	const int EF_MG42_ACTIVE = 0xc000;
	const int YAW = 1;
	const int FPS_FRAMES = 32;//*/
	
	namespace cgame_mp
	{
		WEAK adjuster<cvarTable_t> cvarTable{ 0x300749A0, BASE_CGAME_MP };
		WEAK adjuster<int (*)(int arg, ...)> syscall{ 0x30074898, BASE_CGAME_MP };
	}

	WEAK adjuster<int> cls_keyCatchers{ 0x0155f2c4 };
	WEAK adjuster<HWND> hWnd{ 0x16C35E8 };
	WEAK adjuster<int> cmd_argc{ 0x008930f0 };
	WEAK adjuster<char*> cmd_argv{ 0x00890bf0 };
	WEAK adjuster<float> viewangles{ 0x0143a9a0 };
	WEAK adjuster<float> cg_zoomSensitivity{ 0x3020b5f4, BASE_CGAME_MP };
	WEAK adjuster<float> ads_progress{ 0x30207214, BASE_CGAME_MP }; // Between 0 and 1, might be cg.zoomTime
	WEAK adjuster<float> fov_visible{ 0x3020958c, BASE_CGAME_MP }; // Not the cg_fov cvar value, might be cg.zoomval
	WEAK adjuster<pmove_t*> pm{ 0x3019d570, BASE_CGAME_MP };
	WEAK adjuster<weaponInfo_t[]> cg_weapons{ 0x300eef3c, BASE_CGAME_MP };
	WEAK adjuster<qboolean> refreshActive{ 0x401EA698, BASE_UI_MP };
	WEAK adjuster<qboolean> clc_demoplaying{ 0x015ef004 };
	WEAK adjuster<vm_t*> cgvm{ 0x01617348 };
	WEAK adjuster<qboolean> mouseActive{ 0x8e2520 };
	WEAK adjuster<qboolean> mouseInitialized{ 0x8e2524 };
	WEAK adjuster<connstate_t> cls_state{ 0x155F2C0 };
	WEAK adjuster<qboolean> clc_demorecording{ 0x015ef000 };
	WEAK adjuster<cvar_t[]> cvar_indexes{ 0x0163b420 };
	WEAK adjuster<netadr_t> clc_serverAddress{ 0x015ce86c };
	WEAK adjuster<netadr_t> cls_autoupdateServer{ 0x015ca57c };

	WEAK adjuster<int> width{ 0x016c3ae4 }; // 016c3ae4
	WEAK adjuster<int> height{ 0x016c3ae8 };






	//WEAK adjuster<vm_t*> uivm{ 0, 0x0161747c };
	//WEAK adjuster<int> ping{ 0x41405d };
}
