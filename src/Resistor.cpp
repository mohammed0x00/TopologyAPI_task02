/*******************************************************************************
 * @file    Resistor.cpp
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Resistor Class source file
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
#include "Devices/Resistor.h"

/* ------ Functions ------ */
/* Reinitialize the device type as resistor */
Resistor::Resistor()
{
	type = resistor;
	netlist = new Netlist(RESISTOR_NETLIST_NODES);
}

/* Delete netlist object */
Resistor::~Resistor()
{
	delete netlist;
}

/* Set the resistance value of the resistor */
void Resistor::setResistance(unsigned int def, unsigned int min, unsigned int max)
{
	resistance.setDefaultValue(def);
	resistance.setMinimumValue(min);
	resistance.setMaximumValue(max);
}

/* Returns an object Resistance data type */
Resistance Resistor::getResistance()
{
	return resistance;
}
