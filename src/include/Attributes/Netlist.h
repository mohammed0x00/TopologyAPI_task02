/*******************************************************************************
 * @file    Netlist.h
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    15.05.2022
 *
 * @brief   Netlist Class
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
*******************************************************************************/

#ifndef NETLIST_H_
#define NETLIST_H_

/* ------ Include ------ */
#include <string>

/**
 * @brief  Netlist class
 */
class Netlist {
public:
	/* Public functions */
	
	/**
	 * @brief  Constructor of Netlist class.
	 * Initializes an array with the required size.
	 * @param  size: Size of netlist.
	 */
	Netlist(int size);

	/**
	 * @brief  Destructor of Device class.
	 */
	virtual ~Netlist();


	/**
	 * @brief  Set a netlist node value.
	 * @param  index: Index of the node
	 * @param  value: Node value
	 * @retval None
	 */
	void setNode(int index, std::string value);

	/**
	 * @brief  Get a netlist node value.
	 * @param  index: Index of the node
	 * @retval Node value
	 */
	std::string getNode(int index);

private:

	/** Vector to store netlist nodes */
	std::string * nodes;


};

#endif /* NETLIST_H_ */
