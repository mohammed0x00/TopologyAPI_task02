/*******************************************************************************
 * @file    Nmos.cpp
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Nmos Class source file
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
#include "Devices/Nmos.h"

/* ------ Functions ------ */
/* Reinitialize the device type as nmos */
Nmos::Nmos() {
	type = nmos;
}

/* Empty destructor */
Nmos::~Nmos() {

}

/* Set a node in the netlist. The node is pointed by NetlistNodeIndex node */
/* The argument NetlistNode value can be casted to string */
void Nmos::setNetlistNode(NetlistNodeIndex node, NetlistNode value)
{
	/* store {drain, gate, source} in netlist array in the same order */
	switch(node)
	{
	case drain:
		netlist[0] = value;
		break;
	case gate:
		netlist[1] = value;
		break;
	case source:
		netlist[2] = value;
		break;
	}
}

/* Returns the node in of netlist that is pointed by NetlistNodeIndex node */
Nmos::NetlistNode Nmos::getNetlistNode(Nmos::NetlistNodeIndex node)
{
	/* read {drain, gate, source} from netlist array in the same order */
	NetlistNode toReturn;
	switch(node)
	{
	case drain:
		toReturn = netlist[0];
		break;
	case gate:
		toReturn = netlist[1];
		break;
	case source:
		toReturn = netlist[2];
		break;
	}
	return toReturn;
}


/* Set M(l) of the Nmos */
void Nmos::setMl(MlNode def, MlNode min, MlNode max)
{
	/* Write values to ml struct of the class */
	ml.def = def;
	ml.min = min;
	ml.max = max;
}

/* Returns a struct of MlType that represents M(l) */
const Nmos::MlType * Nmos::getMl()
{
	/* Return the address of ml struct as a pointer to a constant */
	return &ml;
}
