#pragma once
#include"CShape.h"

class CRectangle: public CShape
{
public:
	CRectangle();
	~CRectangle();



public:
	virtual bool Init();
};

