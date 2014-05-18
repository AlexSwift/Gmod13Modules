#ifndef CLuaShared_H
#define CLuaShared_H

#include "Lua/Interface.h"

class ILuaShared2
{
public:
	virtual void Member0 ();
	virtual void Member1 ();
	virtual void Member2 ();
	virtual void Member3 ();
	virtual void Member4 ();
	virtual void Member5 ();
	virtual lua_State* GetLuaInterface ( unsigned char interfaceNumber );
};

#endif