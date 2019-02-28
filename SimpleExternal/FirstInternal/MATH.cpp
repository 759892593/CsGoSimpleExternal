#include "MATH.h"

#define M_PI		3.14159265358979323846	
Vector AimAngle;
Vector Delta;


#define M_RADPI 57.295779513082f
#define DEBUG_M 0

Vector MATH::CalcAngle(Vector src, Vector dst) // Same thing maybe
{
	Vector angles;
	float Delta[3] = { (src.x - dst.x), (src.y - dst.y), (src.z - dst.z) };
	angles.x= atan(Delta[2] / sqrt(Delta[0] * Delta[0] + Delta[1] * Delta[1])) * M_RADPI;
	angles.y = atan(Delta[1] / Delta[0]) * M_RADPI;
	angles.z = 0.0f;
	if (Delta[0] >= 0.0) angles.y += 180.0f;

	return MATH::clampAngle(angles);
}

Vector MATH::anglecalc(Vector source, Vector destination) { // CalcAimanle 
	
#if DEBUG_M 
		cout << "source.x :" << source.x << " " << "destination.x :" << destination.x << endl;
		cout << "source.y :" << source.y << " " << "destination.y :" << destination.y << endl;
		cout << "source.z :" << source.z << " " << "destination.z :" << destination.z << endl;
#endif

	Delta = { (source.x - destination.x), (source.y - destination.y), ((source.z - destination.z)) }; //
	float hyp = sqrt(Delta.x * Delta.x + Delta.y * Delta.y);

	AimAngle.x = (asinf(Delta.z / hyp) * (180 / M_PI) /* - punch.x */);
	AimAngle.y = atanf(Delta.y / Delta.x) * (180 / M_PI) /* - punch.y*/ ;
	AimAngle.z = 0.0f;
	if (Delta.x >= 0.0)
	{
		AimAngle.y += 180.0f;
	}

	return clampAngle(AimAngle);
}

Vector MATH::RCSCalcAngle(Vector source, Vector destination,Vector RCS) { // CalcAimanle with recoil 


#if DEBUG_M
	cout << "source.x :" << source.x << " " << "destination.x :" << destination.x << endl;
	cout << "source.y :" << source.y << " " << "destination.y :" << destination.y << endl;
	cout << "source.z :" << source.z << " " << "destination.z :" << destination.z << endl;
#endif




	Delta = { (source.x - destination.x), (source.y - destination.y), ((source.z - destination.z)) }; 
	float hyp = sqrt(Delta.x * Delta.x + Delta.y * Delta.y);

	AimAngle.x = (asinf(Delta.z / hyp) * (180 / M_PI)  - (RCS.x * 2) );
	AimAngle.y = atanf(Delta.y / Delta.x) * (180 / M_PI)  - (RCS.y * 2);
	AimAngle.z = 0.0f;
	if (Delta.x >= 0.0)
	{
		AimAngle.y += 180.0f;
	}
	
	return clampAngle(AimAngle);
}


void MATH::Smooth(Vector src, Vector *back, Vector flLocalAngles, float smooth) // it fuckup somehow
{
	Vector AimDifference;
	AimDifference.x = flLocalAngles.x - src.x;
	AimDifference.y = flLocalAngles.y - src.y;

	Vector AimSmooth; //4x Slower
	AimSmooth.x = AimDifference.x / 10;
	AimSmooth.y = AimDifference.y / 10;


	if (flLocalAngles.x != src.x || flLocalAngles.y != src.y) //If not already aimed
	{
		back->x = src.x  +  AimSmooth.x;
		back->y = src.y   + AimSmooth.y;
		
	}

}

	

float MATH::flGetDistance(Vector from, Vector to)
{
	float x = from.x - to.x;
	float y = from.y - to.y;
	float z = from.z - to.z;

	return sqrt(x*x + y * y + z * z);
}

void MATH::MakeSmooth(Vector org,Vector aimbot, Vector* aimat, float smooth) { // idk what is this
	Vector aimsmooth;
	org.x = -aimbot.x;
	org.y = -aimbot.y;
	aimsmooth.x = org.x / smooth;
	aimsmooth.y = org.y / smooth;

	aimat->x = aimsmooth.x;
	aimat->y = aimsmooth.y;

}
			

Vector MATH::clampAngle(Vector vIn) // Check if	Angle not fuck up
{
	if (vIn.x > 89.0f && vIn.x <= 180.0f)
	{
		vIn.x = 89.0f;
	}
	if (vIn.x > 180.f)
	{
		vIn.x -= 360.f;
	}
	if (vIn.x < -89.0f)
	{
		vIn.x = -89.0f;
	}
	if (vIn.y > 180.f)
	{
		vIn.y -= 360.f;
	}
	if (vIn.y < -180.f)
	{
		vIn.y += 360.f;
	}
	if (vIn.z != 0.0f)
	{
		vIn.z = 0.0f;
	}

	if (vIn.x != vIn.x) 
	{
		vIn.x = 0;
	}
	if (vIn.y != vIn.y) 
	{
		vIn.y = 0;
	}
	if (vIn.z != vIn.z)
	{
		vIn.z = 0;
	}

	return vIn;
}




double MATH::GetDistanceToAngle(Vector AimAt, Vector CurrentAngle)
{
	AimAt.y += 180.f;
	CurrentAngle.y += 180.f;
	CurrentAngle.x += 90.f;
	AimAt.x += 90.f;
	float YDiff = max(AimAt.y, CurrentAngle.y) - min(AimAt.y, CurrentAngle.y);
	if (YDiff > 180.f)
		YDiff = 360.f - YDiff;

	return sqrt(pow(YDiff, 2) + pow(AimAt.x - CurrentAngle.x, 2));
}
