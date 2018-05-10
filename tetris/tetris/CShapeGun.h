#pragma once
#include"CShape.h"
class CShapeGun : public CShape
{
public:
	CShapeGun();
	~CShapeGun();


public:
	virtual bool Init();
	virtual void Rotation();
};

