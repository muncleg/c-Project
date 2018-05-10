#pragma once
#include"CShape.h"
class CShapeZ : public CShape
{
public:
	CShapeZ();
	~CShapeZ();


public:
	virtual bool Init();
	virtual void Rotation();
};

