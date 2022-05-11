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
Resistor::Resistor() {
	type = resistor;
}

/* Empty destructor */
Resistor::~Resistor() {

}

/* Set a node in the netlist. The node is pointed by NetlistNodeIndex node */
/* The argument NetlistNode value can be casted to string */
void Resistor::setNetlistNode(NetlistNodeIndex node, NetlistNode value)
{
	/* store {T1, T2} in netlist array in the same order */
	switch(node)
	{
	case T1:
		netlist[0] = value;
		break;
	case T2:
		netlist[1] = value;
		break;
	}
}

/* Returns the node in of netlist that is pointed by NetlistNodeIndex node */
Resistor::NetlistNode Resistor::getNetlistNode(Resistor::NetlistNodeIndex node)
{
	/* read {T1, T2} from netlist array in the same order */
	NetlistNode toReturn;
	switch(node)
	{
	case T1:
		toReturn = netlist[0];
		break;
	case T2:
		toReturn = netlist[1];
		break;
	}
	return toReturn;
}

/* Set the resistance value of the resistor */
void Resistor::setResistance(ResistanceNode def, ResistanceNode min, ResistanceNode max)
{
	/* Write values to resistance struct of the class */
	resistance.def = def;
	resistance.min = min;
	resistance.max = max;
}

/* Returns a struct ResistanceNode that represents the resistance */
const Resistor::ResistanceType * Resistor::getResistance()
{
	/* Return the address of resistance struct as a pointer to a constant */
	return &resistance;
}
