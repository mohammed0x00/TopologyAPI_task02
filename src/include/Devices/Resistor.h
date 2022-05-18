/*******************************************************************************
 * @file    Resistor.h
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Resistor Class
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

#ifndef RESISTOR_H_
#define RESISTOR_H_

/* ------ Include ------ */
#include "Device.h"
#include "Attributes/Resistance.h"

/**
 * @brief  String of resistor type device.
 */
#define RESISTOR_TYPE_STRING	(std::string) "resistor"

/**
 * @brief  Number of netlist nodes for each resistor object.
 */
#define RESISTOR_NETLIST_NODES  		2
#define RESISTOR_NETLIST_NODE_T1 		0
#define RESISTOR_NETLIST_NODE_T2 		1

/**
 * @brief  Resistor class
 */
class Resistor : public Device {
public:
	/* Public functions */
	
	/**
	 * @brief  Constructor of Resistor class.
	 * It initializes the Device type as Resistor device.
	 */
	Resistor();
	
	/**
	 * @brief  Destructor of Resistor class.
	 */
	virtual ~Resistor();

	/**
	 * @brief  Set the resistance value of the resistor.
	 * @param  def: Default resistance value
	 * @param  min: Minimum resistance value
	 * @param  max: Maximum resistance value
	 * @retval None
	 */
	void setResistance(unsigned int def, unsigned int min, unsigned int max);

	/**
	 * @brief  Get the resistance values.
	 * @param  None
	 * @retval Resistance of the resistor.
	 * @note See Resistance data type.
	 */
	Resistance getResistance();

private:
	
	/** object of Resistance data type to store the resistance values. */
	Resistance resistance;
};

#endif /* RESISTOR_H_ */
