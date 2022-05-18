/*******************************************************************************
 * @file    Resistance.cpp
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Resistance Class source file
 * @note
 *
@verbatim
Copyright (C) 2022

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.
@endverbatim
*****************************************************************************


/* ------ Include ------ */
#include "Attributes/Resistance.h"

/* ------ Functions ------ */
/* Empty constructor */
Resistance::Resistance()
{

}

/* Initialize the values */
Resistance::Resistance(unsigned int def, unsigned int min, unsigned int max)
{
	setDefaultValue(def);
	setMinimumValue(min);
	setMaximumValue(max);
}

/* Empty destructor */
Resistance::~Resistance()
{

}

/* Set the default resistance value */
void Resistance::setDefaultValue(unsigned int value)
{
	def = value;
}

/* Set the minimum resistance value */
void Resistance::setMinimumValue(unsigned int value)
{
	min = value;
}

/* Set the maximum resistance value */
void Resistance::setMaximumValue(unsigned int value)
{
	max = value;
}

/* Get the default resistance value */
unsigned int Resistance::getDefaultValue()
{
	return def;
}

/* Get the minimum resistance value */
unsigned int Resistance::getMinimumValue()
{
	return min;
}

/* Get the maximum resistance value */
unsigned int Resistance::getMaximumValue()
{
	return max;
}
