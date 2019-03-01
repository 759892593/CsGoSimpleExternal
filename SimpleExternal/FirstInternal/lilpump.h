#pragma once
#include "Header.h"
#include "OOF.h"
#include <iostream>
#include <vector>
#include <string>

struct Vector {
	float x, y, z = 0;
	bool	operator==(const Vector &) const;
	bool	operator!=(const Vector &) const;
	Vector(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	Vector() {}

	inline Vector& operator=(const Vector& v)
	{
		x = v.x; y = v.y; z = v.z; return *this;
	}

	inline Vector& operator=(const float* v)
	{
		x = v[0]; y = v[1]; z = v[2]; 
	}

	inline float& operator[](int i)
	{
		return ((float*)this)[i];
	}

	inline float operator[](int i) const
	{
		return ((float*)this)[i];
	}

	inline Vector& operator+=(const Vector& v)
	{
		x += v.x; y += v.y; z += v.z; return *this;
	}

	inline Vector& operator-=(const Vector& v)
	{
		x -= v.x; y -= v.y; z -= v.z; 
	}

	inline Vector& operator*=(const Vector& v)
	{
		x *= v.x; y *= v.y; z *= v.z; 
	}

	inline Vector& operator/=(const Vector& v)
	{
		x /= v.x; y /= v.y; z /= v.z; 
	}

	inline Vector& operator+=(float v)
	{
		x += v; y += v; z += v; 
	}

	inline Vector& operator-=(float v)
	{
		x -= v; y -= v; z -= v; 
	}

	inline Vector& operator*=(float v)
	{
		x *= v; y *= v; z *= v; 
	}

	inline Vector& operator/=(float v)
	{
		x /= v; y /= v; z /= v; return *this;
	}

	inline Vector operator-() const
	{
		return Vector(-x, -y, -z);
	}

	inline Vector operator+(const Vector& v) const
	{
		return Vector(x + v.x, y + v.y, z + v.z);
	}

	inline Vector operator-(const Vector& v) const
	{
		return Vector(x - v.x, y - v.y, z - v.z);
	}

	inline Vector operator*(const Vector& v) const
	{
		return Vector(x * v.x, y * v.y, z * v.z);
	}

	inline Vector operator/(const Vector& v) const
	{
		return Vector(x / v.x, y / v.y, z / v.z);
	}

	inline Vector operator+(float v) const
	{
		return Vector(x + v, y + v, z + v);
	}

	inline Vector operator-(float v) const
	{
		return Vector(x - v, y - v, z - v);
	}

	inline Vector operator*(float v) const
	{
		return Vector(x * v, y * v, z * v);
	}

	inline Vector operator/(float v) const
	{
		return Vector(x / v, y / v, z / v);
	}

};

inline bool Vector::operator==(const Vector &v) const
{
	return v.x == x && v.y == y && v.z == z;
}
inline bool Vector::operator!=(const Vector &e) const
{
	return e.x != x || e.y != y || e.z != z;
}
struct Input_t {
	uintptr_t m_pVftable;                   // 0x00
	bool      m_bTrackIRAvailable;          // 0x04
	bool      m_bMouseInitialized;          // 0x05
	bool      m_bMouseActive;               // 0x06
	bool      m_bJoystickAdvancedInit;      // 0x07
	uint8_t   Unk1[44];                     // 0x08
	uintptr_t m_pKeys;                      // 0x34
	uint8_t   Unk2[100];                    // 0x38
	bool      m_bCameraInterceptingMouse;   // 0x9C
	bool      m_bCameraInThirdPerson;       // 0x9D
	bool      m_bCameraMovingWithMouse;     // 0x9E
	Vector    m_vecCameraOffset;            // 0xA0
	bool      m_bCameraDistanceMove;        // 0xAC
	int32_t   m_nCameraOldX;                // 0xB0
	int32_t   m_nCameraOldY;                // 0xB4
	int32_t   m_nCameraX;                   // 0xB8
	int32_t   m_nCameraY;                   // 0xBC
	bool      m_bCameraIsOrthographic;      // 0xC0
	Vector    m_vecPreviousViewAngles;      // 0xC4
	Vector    m_vecPreviousViewAnglesTilt;  // 0xD0
	float     m_flLastForwardMove;          // 0xDC
	int32_t   m_nClearInputState;           // 0xE0
	uint8_t   Unk3[0x8];                    // 0xE4
	uintptr_t m_pCommands;                  // 0xEC
	uintptr_t m_pVerifiedCommands;          // 0xF0
};

class Input_T
{
public:
	char pad_0000[12]; //0x0000
	bool m_bTrackIRAvailable; //0x000C
	bool m_bMouseInitialized; //0x000D
	bool m_bMouseActive; //0x000E
	bool m_bJoystickAdvancedInit; //0x000F
	char pad_0010[224]; //0x0010
	uintptr_t m_pCommands; //0x00F0
	uintptr_t m_pVerifiedCommands; //0x00F4
	char pad_00F8[1920]; //0x00F8
}; //Size: 0x0878





struct UserCmd_t {
	uintptr_t pVft;                // 0x00
	int32_t   m_iCmdNumber;        // 0x04
	int32_t   m_iTickCount;        // 0x08
	Vector m_vecViewAngles;     // 0x0C
	Vector m_vecAimDirection;   // 0x18
	float     m_flForwardmove;     // 0x24
	float     m_flSidemove;        // 0x28
	float     m_flUpmove;          // 0x2C
	int32_t   m_iButtons;          // 0x30
	uint8_t   m_bImpulse;          // 0x34
	uint8_t   Pad1[3];
	int32_t   m_iWeaponSelect;     // 0x38
	int32_t   m_iWeaponSubtype;    // 0x3C
	int32_t   m_iRandomSeed;       // 0x40
	int16_t   m_siMouseDx;         // 0x44
	int16_t   m_siMouseDy;         // 0x46
	bool      m_bHasBeenPredicted; // 0x48
	uint8_t   Pad2[27];
}; // size is 100 or 0x64

struct SilentTest 
{
	int iCurrentSequenceNumber;
	UserCmd_t UserCmd;
};
struct VerifiedUserCmd_t {
	UserCmd_t m_Command;
	uint32_t  m_Crc;
};

extern string getName(int index);

struct Color {
	Color(int r1, int b1, int g1, int a1) {
		r = r1 / 255;
		g = g1 / 255;
		b = b1 / 255;
		a = a1 / 255;
	}
	Color(float r1, float b1, float g1, float a1)
	{
		r = r1 ;
		g = g1 ;
		b = b1 ;
		a = a1 ;
	}
	float r, g, b,a;

};
struct GlowBool {

	GlowBool(bool g, bool unk, bool full) {
		glow = g, unkow = unk, fullbloom = full;
	}
	bool glow, unkow, fullbloom;
};

void Glow(int i, Color c, bool fullblom);

namespace Mem
{
	template<typename TYPE>
	TYPE Read(uintptr_t address) {
		TYPE buffer;
		ReadProcessMemory(Hack.__HandleProcess, (LPCVOID)address, &buffer, sizeof(buffer), 0);
		return buffer;
	}
	template<typename TYPE>
	TYPE Write(uintptr_t address, TYPE buffer) {
		WriteProcessMemory(Hack.__HandleProcess, (LPVOID)address, &buffer, sizeof(buffer), 0);
		return buffer;
	}
	
	void WriteMem(uintptr_t address, LPVOID lpBuffer, uintptr_t size);
	void ReadMem(uintptr_t address, LPVOID lpBuffer, uintptr_t size);

	
	
}


namespace enginetools {
	uintptr_t getentbyindex(int i);
	void SetViewAngle(Vector aimat);
	UserCmd_t GetUserCmd(int seqnum);
	Vector GetAngle();
	Vector GetCmdAngle();
	int GetiCurrentSequenceNumber();
	void SendPacket(bool a);
	void Fire();
	void UnFire();
	void Jump();
	void SetClanTag(string tagstring);
}


void Glow(int i, Color c, bool fullblom);

class BoneMatrix
{
public:
	byte pad3[12];
	float x;
	byte pad1[12];
	float y;
	byte pad2[12];
	float z;
};


struct CBaseEntity {
	int health;
	int team;
	int shootfired;
	bool dead;
	int glowindex;
	int flags;
	int crosshairid;
	int dormant;
	string name;
	Vector position;
	uintptr_t playerbase;
	uintptr_t playerbonemtrix;

	Vector bonepos;

	
	CBaseEntity(uintptr_t adr = 0) {
		playerbase = Mem::Read <uintptr_t>(Hack.Client + adr);
	}
	void Read() { 
		health = Mem::Read<int>(playerbase + OOF::netvars::m_iHealth);
		team = Mem::Read<int>(playerbase + OOF::netvars::m_iTeamNum);
		dead = Mem::Read<bool>(playerbase + OOF::netvars::m_lifeState);
		shootfired = Mem::Read<int>(playerbase + OOF::netvars::m_iShotsFired);
		playerbonemtrix = Mem::Read<uintptr_t>(playerbase + OOF::netvars::m_dwBoneMatrix);
		position = Mem::Read<Vector>(playerbase + OOF::netvars::m_vecOrigin);
		glowindex = Mem::Read<int>(playerbase + OOF::netvars::m_iGlowIndex);
		flags = Mem::Read<int>(playerbase + OOF::netvars::m_fFlags);
		crosshairid = Mem::Read<int>(playerbase + OOF::netvars::m_iCrosshairId);
		dormant = Mem::Read<int>(playerbase + OOF::signatures::m_bDormant);
	}
	Vector GetBonePos(int bone) {

		BoneMatrix A;
		A = Mem::Read<BoneMatrix>(playerbonemtrix + sizeof(BoneMatrix)*bone);
		return Vector(A.x, A.y, A.z );
	}

	Vector GetPunchAngle() {
		Vector a = Mem::Read<Vector>(playerbase + OOF::netvars::m_aimPunchAngle); 
		return a;
		
	}
};

struct Target_t {
	string name;
	int healt;
	double fov;
	float distance;
	Vector aimat;
	void A(double fov1,Vector aim) {

		fov = fov1;
		aimat = aim;
	}

};

