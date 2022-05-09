/*
 * Nmos.cpp
 *
 *  Created on: May 6, 2022
 *      Author: mohammed
 */

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
