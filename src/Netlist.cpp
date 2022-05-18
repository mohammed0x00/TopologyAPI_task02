/*******************************************************************************
 * @file    Netlist.cpp
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Netlist Class source file
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
#include "Attributes/Netlist.h"

/* ------ Functions ------ */

Netlist::Netlist(int size)
{
	nodes = new std::string[size];
}


Netlist::~Netlist()
{
	delete[] nodes;
}

void Netlist::setNode(int index, std::string value)
{
	nodes[index] = value;
}

std::string Netlist::getNode(int index)
{
	return nodes[index];
}
