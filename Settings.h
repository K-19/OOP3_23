#pragma once
#include "parametrs.h"
class Settings
{
	Base base;
	Format format;
	FillChar fillch;
	bool plus;
public:
	Settings();
	Settings(Base, Format, bool, FillChar);
	Base getBase();
	Format getFormat();
	bool getPlus();
	FillChar getFchar();
	void setBase(Base);
	void setFormat(Format);
	void setPlus(bool);
	void setFChar(FillChar);
};

