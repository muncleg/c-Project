#pragma once
#include"CShape.h"
class CShapeS :
	public CShape
{
public:
	CShapeS();
	~CShapeS();

public:
	virtual bool Init();
	virtual void Rotation();
};

