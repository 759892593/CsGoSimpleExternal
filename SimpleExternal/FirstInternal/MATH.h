#pragma once
#include <Windows.h>
#include <cmath>
#include "lilpump.h"
namespace MATH {
	Vector anglecalc(Vector source, Vector destination);
	void clampAngle(Vector& vIn);
	float flGetDistance(Vector from, Vector to);
	double GetDistanceToAngle(Vector AimAt, Vector CurrentAngle);
	Vector CalcAngle(Vector src, Vector dst);
	Vector RCSCalcAngle(Vector source, Vector destination, Vector RCS);
	void MakeSmooth(Vector org, Vector aimbot, Vector* aimat, float smooth);
	void Smooth(Vector src, Vector *back, Vector flLocalAngles, float smooth);
}