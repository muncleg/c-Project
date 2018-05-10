#include "stdafx.h"
#include "CStageManager.h"
#include"CStage.h"

CStageManager* CStageManager::m_pInst = NULL;

CStageManager::CStageManager()
{
}


CStageManager::~CStageManager()
{
}

bool CStageManager::Init()
{
	m_pCurStage = new CStage;

	if (!m_pCurStage->Init())
	{
		return false;
	}
	return true;
}

void CStageManager::Run()
{
	m_pCurStage->Render();
}
