#include "f2dRendererImpl.h"

#include "f2dSpriteImpl.h"
#include "f2dGeometryRendererImpl.h"
#include "f2dFontRendererImpl.h"
#include "f2dFontFileProvider.h"
#include "f2dFontTexProvider.h"
#include "f2dSpriteAnimationImpl.h"
#include "f2dParticle.h"

#include "../Engine/f2dEngineImpl.h"

#include <shlobj.h>

using namespace std;

////////////////////////////////////////////////////////////////////////////////

void f2dRendererImpl::DefaultListener::OnRenderDeviceLost()
{
	m_pEngine->SendMsg(F2DMSG_RENDER_ONDEVLOST);
}

void f2dRendererImpl::DefaultListener::OnRenderDeviceReset()
{
	m_pEngine->SendMsg(F2DMSG_RENDER_ONDEVRESET);
}

////////////////////////////////////////////////////////////////////////////////

f2dRendererImpl::f2dRendererImpl(f2dEngineImpl* pEngine, fuInt BackBufferWidth, fuInt BackBufferHeight, fBool Windowed, fBool VSync, F2DAALEVEL AALevel)
	: m_pEngine(pEngine), m_pDev(NULL), m_DefaultListener(pEngine)
{
	m_pDev = new f2dRenderDeviceImpl(pEngine, BackBufferWidth, BackBufferHeight, Windowed, VSync, AALevel);
	m_pDev->AttachListener(&m_DefaultListener);
}

f2dRendererImpl::~f2dRendererImpl()
{
	m_pDev->RemoveListener(&m_DefaultListener);
	FCYSAFEKILL(m_pDev);
}

fcyFileStream* f2dRendererImpl::enumSystemFont(fcStrW FontName)
{
	// 打开注册表 HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Fonts
	// 枚举符合要求的字体
	HKEY tKey;
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts", 0, KEY_READ, &tKey) == ERROR_SUCCESS)
	{
		// 枚举子键
		int tIndex = 0;
		fCharW tKeyName[MAX_PATH];
		DWORD tKeyNameLen = MAX_PATH;
		DWORD tKeyType = 0;
		BYTE tKeyData[MAX_PATH];
		DWORD tKeyDataLen = MAX_PATH;

		while (RegEnumValue(tKey, tIndex, tKeyName, &tKeyNameLen, NULL, &tKeyType, tKeyData, &tKeyDataLen) == ERROR_SUCCESS)
		{
			// 检查是否为相应字体
			if(tKeyType == REG_SZ)
			{
				fCharW tFontName[MAX_PATH];
				fCharW tFontType[MAX_PATH];
				if(2 == swscanf_s(tKeyName, L"%[^()] (%[^()])", tFontName, MAX_PATH, tFontType, MAX_PATH))
				{
					int tLen = wcslen(tFontName);

					// 去除scanf匹配的空格
					if(!tLen)
						continue;
					else 
						if(tFontName[tLen-1] == L' ')
							tFontName[tLen-1] = L'\0';

					// 是否为需要的字体
					if(wcscmp(tFontName, FontName) == 0)
					{
						RegCloseKey(tKey);

						wchar_t tTextDir[MAX_PATH];    
						SHGetSpecialFolderPath(GetDesktopWindow(), tTextDir, CSIDL_FONTS, 0);  
						wstring tPath = tTextDir;
						tPath += L'\\';
						tPath += (wchar_t*)tKeyData;

						// 打开流
						fcyFileStream* pStream = new fcyFileStream(tPath.c_str(), false);
						return pStream;
					}
				}
			}

			// 继续枚举
			tKeyNameLen = MAX_PATH;
			tKeyType = 0;
			tKeyDataLen = MAX_PATH;
			tIndex++;
		}
	}
	else
	{
		throw fcyWin32Exception("f2dRendererImpl::enumSystemFont", "RegOpenKeyEx failed.");
	}

	RegCloseKey(tKey);

	throw fcyException("f2dRendererImpl::enumSystemFont", "Font not exist.");
}

f2dRenderDevice* f2dRendererImpl::GetDevice()
{
	return m_pDev;
}

fResult f2dRendererImpl::CreateSprite2D(f2dTexture2D* pTex, f2dSprite** pOut)
{
	if(pOut)
		*pOut = NULL;
	else
		return FCYERR_INVAILDPARAM;

	if(!pTex)
		return FCYERR_INVAILDPARAM;

	try
	{
		*pOut = new f2dSpriteImpl(pTex);
	}
	catch(const fcyException& e)
	{
		m_pEngine->ThrowException(e);
		return FCYERR_INTERNALERR;
	}

	return FCYERR_OK;
}

fResult f2dRendererImpl::CreateSprite2D(f2dTexture2D* pTex, const fcyRect& Org, f2dSprite** pOut)
{
	if(pOut)
		*pOut = NULL;
	else
		return FCYERR_INVAILDPARAM;

	if(!pTex)
		return FCYERR_INVAILDPARAM;

	try
	{
		*pOut = new f2dSpriteImpl(pTex, Org);
	}
	catch(const fcyException& e)
	{
		m_pEngine->ThrowException(e);
		return FCYERR_INTERNALERR;
	}

	return FCYERR_OK;
}

fResult f2dRendererImpl::CreateSprite2D(f2dTexture2D* pTex, const fcyRect& Org, const fcyVec2& HotSopt, f2dSprite** pOut)
{
	if(pOut)
		*pOut = NULL;
	else
		return FCYERR_INVAILDPARAM;

	if(!pTex)
		return FCYERR_INVAILDPARAM;

	try
	{
		*pOut = new f2dSpriteImpl(pTex, Org, HotSopt);
	}
	catch(const fcyException& e)
	{
		m_pEngine->ThrowException(e);
		return FCYERR_INTERNALERR;
	}

	return FCYERR_OK;
}

fResult f2dRendererImpl::CreateGeometryRenderer(f2dGeometryRenderer** pOut)
{
	if(pOut)
		*pOut = NULL;
	else
		return FCYERR_INVAILDPARAM;

	try
	{
		*pOut = new f2dGeometryRendererImpl();
	}
	catch(const fcyException& e)
	{
		m_pEngine->ThrowException(e);
		return FCYERR_INTERNALERR;
	}

	return FCYERR_OK;
}

fResult f2dRendererImpl::CreateFontRenderer(f2dFontProvider* pProvider, f2dFontRenderer** pOut)
{
	if(pOut)
		*pOut = NULL;
	else
		return FCYERR_INVAILDPARAM;

	try
	{
		*pOut = new f2dFontRendererImpl(pProvider);
	}
	catch(const fcyException& e)
	{
		m_pEngine->ThrowException(e);
		return FCYERR_INTERNALERR;
	}

	return FCYERR_OK;
}

fResult f2dRendererImpl::CreateFontFromFile(f2dStream* pStream, fuInt FaceIndex, const fcyVec2& FontSize, const fcyVec2& BBoxSize, F2DFONTFLAG Flag, f2dFontProvider** pOut)
{
	if(pOut)
		*pOut = NULL;
	else
		return FCYERR_INVAILDPARAM;

	if(!pStream)
		return FCYERR_INVAILDPARAM;

	try
	{
		*pOut = new f2dFontFileProvider(m_pDev, pStream, FontSize, BBoxSize, FaceIndex, Flag);
	}
	catch(const fcyException& e)
	{
		m_pEngine->ThrowException(e);
		return FCYERR_INTERNALERR;
	}

	return FCYERR_OK;
}

fResult f2dRendererImpl::CreateSystemFont(fcStrW FaceName, fuInt FaceIndex, const fcyVec2& FontSize, F2DFONTFLAG Flag, f2dFontProvider** pOut)
{
	fcyRefPointer<fcyFileStream> pStream;
	
	try
	{
		pStream.DirectSet(enumSystemFont(FaceName));
	}
	catch(const fcyException& e)
	{
		m_pEngine->ThrowException(e);

		return FCYERR_INTERNALERR;
	}

	return CreateFontFromFile(pStream, FaceIndex, FontSize, fcyVec2(0.0f, 0.0f), Flag, pOut);
}

fResult f2dRendererImpl::CreateFontFromTex(f2dStream* pDefineFile, f2dTexture2D* pTex, f2dFontProvider** pOut)
{
	if(pOut)
		*pOut = NULL;
	else
		return FCYERR_INVAILDPARAM;

	if(!pDefineFile)
		return FCYERR_INVAILDPARAM;

	try
	{
		*pOut = new f2dFontTexProvider(pDefineFile, pTex);
	}
	catch(const fcyException& e)
	{
		m_pEngine->ThrowException(e);
		return FCYERR_INTERNALERR;
	}

	return FCYERR_OK;
}

fResult f2dRendererImpl::CreateFontFromTex(fcStrW pDefineText, f2dTexture2D* pTex, f2dFontProvider** pOut)
{
	if(pOut)
		*pOut = NULL;
	else
		return FCYERR_INVAILDPARAM;

	if(!pDefineText)
		return FCYERR_INVAILDPARAM;

	try
	{
		*pOut = new f2dFontTexProvider(pDefineText, pTex);
	}
	catch(const fcyException& e)
	{
		m_pEngine->ThrowException(e);
		return FCYERR_INTERNALERR;
	}

	return FCYERR_OK;
}

fResult f2dRendererImpl::CreateSpriteAnimation(f2dSpriteAnimation** pOut)
{
	if(pOut)
		*pOut = NULL;
	else
		return FCYERR_INVAILDPARAM;

	try
	{
		*pOut = new f2dSpriteAnimationImpl();
	}
	catch(const fcyException& e)
	{
		m_pEngine->ThrowException(e);
		return FCYERR_INTERNALERR;
	}

	return FCYERR_OK;
}

fResult f2dRendererImpl::CreateParticlePool(f2dParticlePool** pOut)
{
	if(pOut)
		*pOut = NULL;
	else
		return FCYERR_INVAILDPARAM;

	try
	{
		*pOut = new f2dParticlePoolImpl();
	}
	catch(const fcyException& e)
	{
		m_pEngine->ThrowException(e);
		return FCYERR_INTERNALERR;
	}

	return FCYERR_OK;
}
