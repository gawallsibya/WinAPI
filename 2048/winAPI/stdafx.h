// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//
#pragma once
//======================================================
// 2014.10.22 ## ������� ���ش� ##
//======================================================

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN	//MFC�� �ƴ� ���� ���α׷��� ��쿡�� 
							//WIN32_LEAN_AND_MEAN�� ������ commdlg.h���
							//�ʿ���� ��������� ��Ŭ��� ���� �ʰ� ���ش�.
		
#include <windows.h>		//������ ������� ��Ŭ���
#include <stdlib.h>			//���Ĵٵ� ���̺귯�� ��Ŭ���~ (srand)
#include <stdio.h>			//���Ĵٵ� ����� ��� ��Ŭ���~ (printf, scanf ���..)
#include <tchar.h>			//�����쿡�� ����� ���ڿ� ��� ��� ��Ŭ���~
							//MBCS (Multi Byte Character Set) 
							//-> ������ ����Ѵ� ��Ƽ����Ʈ ������ ���ڿ�~
							//WBCS (Wide Byte Character Set)
							//-> ��� ���ڸ� 2����Ʈ�� ó��~~, �����ڵ� ���...

//���� ���� ������ϵ�~~
#include "commonMacroFunction.h"
#include "commonVirtualKey.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "imageManager.h"
#include "timeManager.h"
#include "txtData.h"
#include "utils.h"
#include "effectManager.h"
#include "sceneManager.h"

//======================================================
// 2014.10.22 ## �����ι� ���ش� ## 
//======================================================
#define WINNAME (LPTSTR)(TEXT("WindowAPI"))
#define WINSTARTX 300
#define WINSTARTY 000
#define WINSIZEX 500
#define WINSIZEY 500
#define WINSTYLE WS_CAPTION | WS_SYSMENU

#define SAFE_DELETE(p)			{ if(p) { delete (p);		(p)=NULL; } }
#define SAFE_DELETE_ARRAY(p)		{ if(p) { delete[] (p);		(p)=NULL; } }
#define SAFE_RELEASE(p)			{ if(p) { (p)->release();	(p)=NULL; } }

//���� ���� ���ӽ����̽� ����ϱ�
using namespace MY_UTIL;

//�̱���
#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define TXTDATA txtData::getSingleton()
#define EFFECTMANAGER effectManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()

//======================================================
// 2014.10.22 ## �������� ���ش� ##
//======================================================
extern HINSTANCE _hInstance; 
extern HWND _hWnd;
extern POINT _ptMouse;
						

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.