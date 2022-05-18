/*******************************************************************************
 * @file    Ml.cpp
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Ml Class source file
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
#include "Attributes/Ml.h"

/* ------ Functions ------ */
/* Empty constructor */
Ml::Ml()
{

}

/* Initialize the values */
Ml::Ml(double def, double min, double max)
{
	setDefaultValue(def);
	setMinimumValue(min);
	setMaximumValue(max);
}

/* Empty destructor */
Ml::~Ml()
{

}

/* Set the default ml value */
void Ml::setDefaultValue(double value)
{
	def = value;
}

/* Set the minimum ml value */
void Ml::setMinimumValue(double value)
{
	min = value;
}

/* Set the maximum ml value */
void Ml::setMaximumValue(double value)
{
	max = value;
}

/* Get the default ml value */
double Ml::getDefaultValue()
{
	return def;
}

/* Get the minimum ml value */
double Ml::getMinimumValue()
{
	return min;
}

/* Get the maximum ml value */
double Ml::getMaximumValue()
{
	return max;
}
