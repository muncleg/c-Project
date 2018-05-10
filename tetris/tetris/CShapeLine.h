#pragma once
#include"CShape.h"
class CShapeLine : public CShape
{
public:
	CShapeLine();
	~CShapeLine();

public:
	virtual bool Init();
	virtual void Rotation();
};

