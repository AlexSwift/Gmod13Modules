#define GMMODULE
#define DEBUGPRINTFUNC LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB); LUA->GetField( -1, "print" ); char dbuff[256]; sprintf_s(dbuff, "[HackTheServer]: CurrentFunction: %s", __FUNCTION__); LUA->PushString(dbuff); LUA->Call( 1, 0 ); LUA->Pop();

#include "CLuaShared.h"
#include "main.h"
#include "Lua\Interface.h"
#include "interface.h"
#include "cdll_int.h"

CreateInterfaceFn fnLuaShaFactory = NULL;
ILuaShared2 *g_pLuaShared = NULL;
lua_State *stateID = NULL;

void PushLFunction( lua_State *state, const char *Name, int (*ptrFunc)( lua_State *state ) )
{

	LUA->PushSpecial( GarrysMod::Lua::SPECIAL_GLOB );
	LUA->PushString( Name );
	LUA->PushCFunction( ptrFunc );

	LUA->SetTable( -3 );
}

GMOD_MODULE_OPEN()
{

	fnLuaShaFactory = Sys_GetFactory( "lua_shared.dll" );
	g_pLuaShared = (ILuaShared2 *)fnLuaShaFactory( "LUASHARED003", NULL );

	(lua_State *) stateID = g_pLuaShared->GetLuaInterface( 3 );

	return 0;

}

GMOD_MODULE_CLOSE()
{

	return 0;

}
