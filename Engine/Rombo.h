#pragma once
#include "modelclass.h"
class Rombo :
	public ModelClass
{
public:
	double height;
	double radio;
	int segmentos;

public:
	Rombo();
	Rombo(double, double, int);
	~Rombo();

private:
	void drawRomboid(double height, double radio, int segmentos);

protected:
	bool Estrategia();
};

