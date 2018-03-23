#pragma once
#include "modelclass.h"
class Cilindro :
	public ModelClass
{

public:
	
	double height;
	double topRadius;
	double bottomRadius; 
	int segments;

public:
	Cilindro();
	Cilindro(double, double, double, int);
	~Cilindro();

private:
	void drawCylinder(double, double, double, int);
	void drawTopCap(double, double, int, int*);
	void drawBottomCap(double, double, int, int*);

protected:
	bool Estrategia();
};

