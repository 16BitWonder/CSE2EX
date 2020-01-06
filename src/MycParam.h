#pragma once

#include "WindowsWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ARMS_LEVEL
{
	int exp[3];
} ARMS_LEVEL;

typedef struct REC
{
	long counter[4];
	unsigned char random[4];
} REC;

extern ARMS_LEVEL gArmsLevelTable[14];

void AddExpMyChar(int x);
void ZeroExpMyChar(void);
BOOL IsMaxExpMyChar(void);
void DamageMyChar(int damage);
void ZeroArmsEnergy_All(void);
void AddBulletMyChar(int no, int val);
void AddLifeMyChar(int x);
void AddMaxLifeMyChar(int val);
void PutArmsEnergy(BOOL flash);
void PutActiveArmsList(void);
void PutMyLife(BOOL flash);
void PutMyAir(int x, int y);
void PutTimeCounter(int x, int y);
BOOL SaveTimeCounter(void);
int LoadTimeCounter(void);

#ifdef __cplusplus
}
#endif
