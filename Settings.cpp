#include "Settings.h"

Settings::Settings() : base(DEC), format(FIX), plus(false), fillch(EMPTY) {}

Settings::Settings(Base base, Format format, bool plus, FillChar fillch) : base(base), format(format), plus(plus), fillch(fillch) {}

Base Settings::getBase()
{
	return base;
}

Format Settings::getFormat()
{
	return format;
}

bool Settings::getPlus()
{
	return plus;
}

FillChar Settings::getFchar()
{
	return fillch;
}

void Settings::setBase(Base base)
{
	this->base = base;
}

void Settings::setFormat(Format format)
{
	this->format = format;
}

void Settings::setPlus(bool plus)
{
	this->plus = plus;
}

void Settings::setFChar(FillChar filchar)
{
	this->fillch = filchar;
}