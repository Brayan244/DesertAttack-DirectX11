#pragma once
#include "modelclass.h"
class Toroide :
	public ModelClass
{
public:
	Toroide();
	~Toroide();

protected:
	bool Estrategia();
	void drawTorus(double, double, int, int);
	void drawCone(double,double, int);
	void drawRomboid(double, double, int);
	

};

