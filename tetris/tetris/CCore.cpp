#include "stdafx.h"
#include "CCore.h"
#include"CStageManager.h"
#include"CShapeManager.h"
CCore* CCore::m_pInst = NULL;

CCore::CCore():
	m_bLoop(true)
{
	srand((unsigned int) time(0));
}


CCore::~CCore()

{
	CShapeManager::DestroyInst();
	CStageManager::DestroyInst();
}

bool CCore::Init()
{
	//�ܼ�â �ڵ� ����
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (m_hConsole == INVALID_HANDLE_VALUE)
		return false;
	//�������� �����ڸ� �ʱ�ȭ�Ѵ�
	if (!CStageManager::GetInst()->Init())
	{
		return false;
	}
	return true;
}

void CCore::Run()
{
	while(m_bLoop)
	{
		system("cls");
		CShapeManager::GetInst()->Update();
		CStageManager::GetInst()->Run();
		CShapeManager::GetInst()->Render();
	
		
		Sleep(100);
	}


}

void CCore::SetConsolePos(int x, int y)
{

	//Ư�����ڸ� ��� 1ĭ�̱� ������ *2fmfgownsek
	COORD pos = { (x+1)*2 ,y };
	SetConsoleCursorPosition(m_hConsole, pos);
}
