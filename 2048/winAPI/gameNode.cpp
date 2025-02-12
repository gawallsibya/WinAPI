#include "stdafx.h"
#include "gameNode.h"

gameNode::gameNode(void)
{
}

gameNode::~gameNode(void)
{
}

HRESULT gameNode::init(void)
{
	_hdc = GetDC(_hWnd);
	_managerInit = false;

	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if(managerInit)
	{
		KEYMANAGER->init();				//Ű�Ŵ��� ����
		IMAGEMANAGER->init();			//�̹����Ŵ��� ����	
		TIMEMANAGER->init();			//Ÿ�ӸŴ��� ����
		TXTDATA->init();				//�ؽ�Ʈ������ ����
		EFFECTMANAGER->init();			//����Ʈ �Ŵ��� ����
		SCENEMANAGER->init();			//���Ŵ��� ����
	}

	return S_OK;
}

void gameNode::release(void)
{
	if(_managerInit)
	{
		//Ű�Ŵ��� �̱��� ����
		KEYMANAGER->release();
		KEYMANAGER->releaseSingleton();
		//�̹��� �Ŵ��� �̱��� ����
		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();
		//Ÿ�ӸŴ��� �̱��� ����
		TIMEMANAGER->release();
		TIMEMANAGER->releaseSingleton();
		//TXTDATA �̱��� ����
		TXTDATA->release();
		TXTDATA->releaseSingleton();
		//effectManager �̱��� ����
		EFFECTMANAGER->release();
		EFFECTMANAGER->releaseSingleton();
		//���Ŵ��� �̱��� ����
		SCENEMANAGER->release();
		SCENEMANAGER->releaseSingleton();
	}

	//DC����
	ReleaseDC(_hWnd, _hdc);
}

void gameNode::update(void)
{
}

void gameNode::render(void)
{
}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
		case WM_MOUSEMOVE:
			_ptMouse.x = static_cast<int>(LOWORD(lParam));
			_ptMouse.y = static_cast<int>(HIWORD(lParam));
		break;
		case WM_KEYDOWN:
			switch(wParam)
			{
				case VK_ESCAPE:
					PostMessage(hWnd, WM_DESTROY, 0, 0);
				break;
			}
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

