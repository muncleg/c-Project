#include "stdafx.h"
#include "CShape.h"
#include"CCore.h"
#include "CStage.h"
#include"CStageManager.h"

CShape::CShape()
{
	m_iDir = RD_UP;
	m_iWidthCount = 0;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j< 4; ++j)
		{
			m_cShape[i][j] = '1'; 
		}
	}
}


CShape::~CShape()
{
}

bool CShape::Init()
{
	m_tPivot.x = 0;
	m_tPivot.y = 3;
	return true;
}

void CShape::Rotation()
{
}

void CShape::Render()
{
	
	for (int i = 0; i < 4; i++)
	{
		int iYIndex = m_tPos.y - (3 - i);
		if (iYIndex < 0)
			continue;
		
		for (int j = 0; j < 4; j++)
		{
			if (m_tPos.x + j >= STAGE_WIDTH)
				continue;

			if (m_cShape[i][j] == '0')
			{
				CCore::GetInst()->SetConsolePos(m_tPos.x + j, iYIndex);
				cout << "■";
			}
			
		}
		cout << endl;
	}
}

void CShape::RenderNext()
{
	for (int i = 0; i < 4; i++)
	{
		int iYIndex = m_tPos.y - (3 - i);
		if (iYIndex < 0)
			continue;
		
		for (int j = 0; j < 4; j++)
		{
			if (m_cShape[i][j] == '0')
			{
				CCore::GetInst()->SetConsolePos(m_tPos.x + j, iYIndex);
				cout << "■";
				
			}
		}
		cout << endl;
	}
}

bool CShape::MoveDown()
{
	CStage* pStage = CStageManager::GetInst()->GetCurrentStage();
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if(m_cShape[i][j]=='0')
			{
			if (pStage->CheckBlock(m_tPos.x + j, m_tPos.y - (2 - i)))
			{
				//q바닥에 닿은후에 현재 도형의 블럭인 부분이 하나라도
				//좌표가 0 보다 작다면 종료한다.
				for (int k = 0; k < 4; ++k)
				{
					for (int l = 0; l < 4;++l)
					{
						if (m_cShape[k][l] == '0')
						{
							if (m_tPos.y - (3 - k) < 0)
							{
								CCore::GetInst()->End();
								break;
							}
						}
					}
				}
				return true;
			}
			}
		}
	}
	if (m_tPos.y == STAGE_HEIGHT - 1)
		return true;

	++m_tPos.y;

	return false;

}

void CShape::MoveLeft()
{
	

	if (m_tPos.x == 0)
		return;

	CStage* pStage = CStageManager::GetInst()->GetCurrentStage();
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (m_cShape[i][j] == '0')
			{
				if (pStage->CheckBlock(m_tPos.x + j-1, m_tPos.y - (3 - i)))
					return ;
			}
		}
	}

	--m_tPos.x;
}

void CShape::MoveRight()
{
	if (m_tPos.x+ m_iWidthCount == STAGE_WIDTH)
		return;

	++m_tPos.x;

}
