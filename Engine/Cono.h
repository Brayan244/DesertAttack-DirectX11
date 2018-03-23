#pragma once
#include "modelclass.h"
class Cono :
	public ModelClass
{
public:
	double height;
	double radio;
	int segmentos;

public:
	Cono();
	Cono(double, double, int);
	~Cono();

private:
	void drawCone(double height, double radio, int segmentos);

protected:
	bool Estrategia();
};

