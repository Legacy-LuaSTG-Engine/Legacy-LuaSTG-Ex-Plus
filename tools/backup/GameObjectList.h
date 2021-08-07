#pragma once

//CHU姥爷的宏孩儿链表，现在已经成为孤儿了

#include <cstdint>
#include <limits>
#include <lua.hpp>

#define LGOBJ_GROUPCNT 16

#define LIST_INSERT_BEFORE(target, p, field) \
	do { \
		p->p##field##Prev = (target)->p##field##Prev; \
		p->p##field##Next = (target); \
		p->p##field##Prev->p##field##Next = p; \
		p->p##field##Next->p##field##Prev = p; \
	} while(false)

#define LIST_INSERT_AFTER(target, p, field) \
	do { \
		p->p##field##Prev = (target); \
		p->p##field##Next = (target)->p##field##Next; \
		p->p##field##Prev->p##field##Next = p; \
		p->p##field##Next->p##field##Prev = p; \
	} while(false)

#define LIST_REMOVE(p, field) \
	do { \
		p->p##field##Prev->p##field##Next = p->p##field##Next; \
		p->p##field##Next->p##field##Prev = p->p##field##Prev; \
	} while(false)

#define LIST_INSERT_SORT(p, field, func) \
	do { \
		if (p->p##field##Next->p##field##Next && func(p->p##field##Next, p)) \
		{ \
			GameObject* pInsertBefore = p->p##field##Next->p##field##Next; \
			while (pInsertBefore->p##field##Next && func(pInsertBefore, p)) \
				pInsertBefore = pInsertBefore->p##field##Next; \
			LIST_REMOVE(p, field); \
			LIST_INSERT_BEFORE(pInsertBefore, p, field); \
		} \
		else if (p->p##field##Prev->p##field##Prev && func(p, p->p##field##Prev)) \
		{ \
			GameObject* pInsertAfter = p->p##field##Prev->p##field##Prev; \
			while (pInsertAfter->p##field##Prev && func(p, pInsertAfter)) \
				pInsertAfter = pInsertAfter->p##field##Prev; \
			LIST_REMOVE(p, field); \
			LIST_INSERT_AFTER(pInsertAfter, p, field); \
		} \
	} while (false)

struct GameObject {
	int64_t uid;
	lua_Number layer;

	GameObject *pObjectPrev, *pObjectNext;
	GameObject *pRenderPrev, *pRenderNext;
	GameObject *pCollisionPrev, *pCollisionNext;

	void Reset() {
		pObjectPrev = pObjectNext = nullptr;
		pRenderPrev = pRenderNext = nullptr;
		pCollisionPrev = pCollisionNext = nullptr;
	}
};

static inline bool ObjectListSortFunc(GameObject* p1, GameObject* p2)
{
	// 总是以uid为参照
	return p1->uid < p2->uid;
}

static inline bool RenderListSortFunc(GameObject* p1, GameObject* p2)
{
	// layer小的靠前。若layer相同则参照uid。
	return (p1->layer < p2->layer) || ((p1->layer == p2->layer) && (p1->uid < p2->uid));
}

class GameObjectPool {
	uint64_t m_iUid = 0;
	GameObject m_pObjectListHeader, m_pObjectListTail;
	GameObject m_pRenderListHeader, m_pRenderListTail;
	GameObject m_pCollisionListHeader[LGOBJ_GROUPCNT], m_pCollisionListTail[LGOBJ_GROUPCNT];

	GameObjectPool() {
		memset(&m_pObjectListHeader, 0, sizeof(GameObject));
		memset(&m_pRenderListHeader, 0, sizeof(GameObject));
		memset(m_pCollisionListHeader, 0, sizeof(m_pCollisionListHeader));
		memset(&m_pObjectListTail, 0, sizeof(GameObject));
		memset(&m_pRenderListTail, 0, sizeof(GameObject));
		memset(m_pCollisionListTail, 0, sizeof(m_pCollisionListTail));
		m_pObjectListHeader.pObjectNext = &m_pObjectListTail;
		m_pObjectListHeader.uid = std::numeric_limits<uint64_t>::min();
		m_pObjectListTail.pObjectPrev = &m_pObjectListHeader;
		m_pObjectListTail.uid = std::numeric_limits<uint64_t>::max();
		m_pRenderListHeader.pRenderNext = &m_pRenderListTail;
		m_pRenderListHeader.uid = std::numeric_limits<uint64_t>::min();
		m_pRenderListHeader.layer = std::numeric_limits<lua_Number>::min();
		m_pRenderListTail.pRenderPrev = &m_pRenderListHeader;
		m_pRenderListTail.uid = std::numeric_limits<uint64_t>::max();
		m_pRenderListTail.layer = std::numeric_limits<lua_Number>::max();
		for (size_t i = 0; i < LGOBJ_GROUPCNT; ++i)
		{
			m_pCollisionListHeader[i].pCollisionNext = &m_pCollisionListTail[i];
			m_pCollisionListTail[i].pCollisionPrev = &m_pCollisionListHeader[i];
		}
	}

	GameObject* freeObject(GameObject* p) {
		GameObject* ret = p->pObjectNext

		// 从对象链表移除
		LIST_REMOVE(p, Object);

		// 从渲染链表移除
		LIST_REMOVE(p, Render);

		// 从碰撞链表移除
		LIST_REMOVE(p, Collision);

		return ret;
	}
	
	void ResetPool() {
		GameObject* p = m_pObjectListHeader.pObjectNext;
		while (p != &m_pObjectListTail)
			p = freeObject(p);
	}

	void DoFrame() {
		GameObject* p = m_pObjectListHeader.pObjectNext;
		while (p && p != &m_pObjectListTail)
		{
			p = p->pObjectNext;
		}
	}

	void DoRender() {
		GameObject* p = m_pRenderListHeader.pRenderNext;
		while (p && p != &m_pRenderListTail)
		{
			p = p->pRenderNext;
		}
	}

	void CollisionCheck(size_t groupA, size_t groupB) {
		GameObject* pA = m_pCollisionListHeader[groupA].pCollisionNext;
		GameObject* pATail = &m_pCollisionListTail[groupA];
		GameObject* pBHeader = m_pCollisionListHeader[groupB].pCollisionNext;
		GameObject* pBTail = &m_pCollisionListTail[groupB];
		while (pA && pA != pATail)
		{
			GameObject* pB = pBHeader;
			while (pB && pB != pBTail)
			{
				pB = pB->pCollisionNext;
			}
			pA = pA->pCollisionNext;
		}
	}
};

/*

// 插入链表域
LIST_INSERT_BEFORE(&m_pObjectListTail, p, Object);  // Object链表只与uid有关，因此总在末尾插入
LIST_INSERT_BEFORE(&m_pRenderListTail, p, Render);  // Render链表在插入后还需要进行排序
LIST_INSERT_BEFORE(&m_pCollisionListTail[p->group], p, Collision);  // 为保证兼容性，对Collision也做排序
LIST_INSERT_SORT(p, Render, RenderListSortFunc);
LIST_INSERT_SORT(p, Collision, ObjectListSortFunc);

LIST_INSERT_SORT(p, Render, RenderListSortFunc); // 刷新p的渲染层级

{
	int group = luaL_checkinteger(L, 3);
	if (group != p->group)
	{
		if (0 <= p->group && p->group < LGOBJ_GROUPCNT)
			LIST_REMOVE(p, Collision);
		p->group = group;
		if (0 <= group && group < LGOBJ_GROUPCNT)
		{
			LIST_INSERT_BEFORE(&m_pCollisionListTail[group], p, Collision);
			LIST_INSERT_SORT(p, Collision, ObjectListSortFunc);  // 刷新p的碰撞次序
			LASSERT(m_pCollisionListHeader[group].pCollisionNext != nullptr);
			LASSERT(m_pCollisionListTail[group].pCollisionPrev != nullptr);
		}
	}
}

*/
