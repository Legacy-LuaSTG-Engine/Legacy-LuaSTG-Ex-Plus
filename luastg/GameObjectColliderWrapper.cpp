#include "Global.h"
#include "AppFrame.h"
#include "LuaWrapper\LuaWrapper.hpp"
#include "GameObjectPool.h"

using namespace LuaSTGPlus;

#ifdef USING_ADVANCE_COLLIDER

void GameObjectColliderWrapper::Register(lua_State* L)LNOEXCEPT {
	struct WrapperImplement
	{
		static int IsValid(lua_State* L) {
			Wrapper* p = static_cast<Wrapper*>(luaL_checkudata(L, 1, LUASTG_LUA_TYPENAME_COLLIDERWRAPPER));
			GameObject* obj = LPOOL.GetPooledObject(p->id);
			if (obj) {
				if (obj->uid == p->uid) {
					lua_pushboolean(L, true);
				}
				else {
					lua_pushboolean(L, false);
				}
			}
			else {
				lua_pushboolean(L, false);
			}
			return 1;
		}

		static int Meta_NewIndex(lua_State* L)LNOEXCEPT
		{
			// t, k, v
			Wrapper* p = static_cast<Wrapper*>(luaL_checkudata(L, 1, LUASTG_LUA_TYPENAME_COLLIDERWRAPPER));
			std::string key = luaL_checkstring(L, 2);
			if (key == "a") {
				p->handle->colliders[p->cur].a = (float)luaL_checknumber(L, 3);
				p->handle->colliders[p->cur].calcircum();
			}
			else if (key == "b") {
				p->handle->colliders[p->cur].b = (float)luaL_checknumber(L, 3);
				p->handle->colliders[p->cur].calcircum();
			}
			else if (key == "type") {
				int itype = luaL_checkinteger(L, 3);
				GameObjectColliderType enumtype;
				switch (itype)
				{
				case 0:
					enumtype = GameObjectColliderType::Circle;
					break;
				case 1:
					enumtype = GameObjectColliderType::OBB;
					break;
				case 2:
					enumtype = GameObjectColliderType::Ellipse;
					break;
				case 3:
					enumtype = GameObjectColliderType::Diamond;
					break;
				case 4:
					enumtype = GameObjectColliderType::Triangle;
					break;
				case 5:
					enumtype = GameObjectColliderType::Point;
					break;
				default:
					return luaL_error(L, "Invalid collider type.");
					break;
				}
				p->handle->colliders[p->cur].type = enumtype;
				p->handle->colliders[p->cur].calcircum();
			}
			else if (key == "x") {
				p->handle->colliders[p->cur].dx = (float)luaL_checknumber(L, 3);
			}
			else if (key == "y") {
				p->handle->colliders[p->cur].dy = (float)luaL_checknumber(L, 3);
			}
			else if (key == "rot") {
				p->handle->colliders[p->cur].rot = (float)(luaL_checknumber(L, 3) * LDEGREE2RAD);
			}
			else if (key == "id") {
				p->cur = luaL_checkinteger(L, 3) - 1;//记得lua的数组索引和C++的区别
			}
			else {
				return luaL_error(L, "New members are not allowed to be added.");
			}
			return 0;
		}
		static int Meta_Index(lua_State* L)LNOEXCEPT
		{
			// t, k //v
			Wrapper* p = static_cast<Wrapper*>(luaL_checkudata(L, 1, LUASTG_LUA_TYPENAME_COLLIDERWRAPPER));
			std::string key = luaL_checkstring(L, 2);
			if (key == "a") {
				lua_pushnumber(L, p->handle->colliders[p->cur].a);
			}
			else if (key == "b") {
				lua_pushnumber(L, p->handle->colliders[p->cur].b);
			}
			else if (key == "type") {
				int _type = (int)p->handle->colliders[p->cur].type;
				lua_pushinteger(L, _type);
			}
			else if (key == "x") {
				lua_pushnumber(L, p->handle->colliders[p->cur].dx);
			}
			else if (key == "y") {
				lua_pushnumber(L, p->handle->colliders[p->cur].dy);
			}
			else if (key == "rot") {
				double _rot = (double)p->handle->colliders[p->cur].rot;
				lua_pushnumber(L, _rot * LRAD2DEGREE);
			}
			else if (key == "id") {
				lua_pushinteger(L, p->cur + 1);//记得lua的数组索引和C++的区别
			}
			else if (key == "IsValid") {
				lua_pushcfunction(L, IsValid);
			}
			else {
				return luaL_error(L, "Attempts to access nonexistent members.");
			}
			return 1;
		}
		static int Meta_ToString(lua_State* L)LNOEXCEPT
		{
			Wrapper* p = static_cast<Wrapper*>(luaL_checkudata(L, 1, LUASTG_LUA_TYPENAME_COLLIDERWRAPPER));
			lua_pushfstring(L, "lstg.GameObjectColliderManager object");
			return 1;
		}
	};
	
	luaL_Reg tMethods[] =
	{
		{ "IsValid", &WrapperImplement::IsValid },
		{ NULL, NULL }
	};
	luaL_Reg tMetaTable[] =
	{
		{ "__tostring", &WrapperImplement::Meta_ToString },
		{ "__newindex", &WrapperImplement::Meta_NewIndex },
		{ "__index", &WrapperImplement::Meta_Index },
		{ NULL, NULL }
	};
	
	luaL_openlib(L, LUASTG_LUA_TYPENAME_COLLIDERWRAPPER, tMethods, 0);  // t
	luaL_newmetatable(L, LUASTG_LUA_TYPENAME_COLLIDERWRAPPER);  // t mt
	luaL_openlib(L, 0, tMetaTable, 0);  // t mt
	//lua_pushliteral(L, "__index");  // t mt s
	//lua_pushvalue(L, -3);  // t mt s t
	//lua_rawset(L, -3);  // t mt (mt["__index"] = t)
	lua_pushliteral(L, "__metatable");  // t mt s
	lua_pushvalue(L, -3);  // t mt s t
	lua_rawset(L, -3);  // t mt (mt["__metatable"] = t)  保护metatable不被修改
	lua_pop(L, 2);
}

void GameObjectColliderWrapper::CreateAndPush(lua_State* L, GameObject* obj)LNOEXCEPT {
	Wrapper* p = static_cast<Wrapper*>(lua_newuserdata(L, sizeof(Wrapper)));// udata
	p->handle = obj;
	p->id = obj->id;
	p->uid = obj->uid;
	luaL_getmetatable(L, LUASTG_LUA_TYPENAME_COLLIDERWRAPPER);//udata, mt
	lua_setmetatable(L, -2);//udata
}

#endif // USING_ADVANCE_COLLIDER
