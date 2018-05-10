#pragma once
#include "CShape.h"
class CShapeRGun :
	public CShape
{
public:
	CShapeRGun();
	~CShapeRGun();


public:
	virtual bool Init();
	virtual void Rotation();
};

