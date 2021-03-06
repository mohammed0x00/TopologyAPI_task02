/*******************************************************************************
 * @file    Nmos.h
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Nmos Class
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

#ifndef NMOS_H_
#define NMOS_H_

/* ------ Include ------ */
#include "Device.h"
#include "Attributes/Ml.h"

/* ------ Define ------ */

/**
 * @brief  String of nmos type device.
 */
#define NMOS_TYPE_STRING	(std::string) "nmos"

/**
 * @brief  Number of netlist nodes for each nmos object.
 */
#define NMOS_NETLIST_NODES			3
#define NMOS_NETLIST_NODE_DRAIN 	0
#define NMOS_NETLIST_NODE_GATE 		1
#define NMOS_NETLIST_NODE_SOURCE  	2


/**
 * @brief  Nmos class
 */
class Nmos : public Device{
public:
	/* Public functions */
	
	/**
	 * @brief  Constructor of Nmos class.
	 * It initializes the Device type as Nmos device.
	 */
	Nmos();
	
	/**
	 * @brief  Destructor of Nmos class.
	 */
	virtual ~Nmos();

	/**
	 * @brief  Set the M(l) value of the Nmos.
	 * @param  def: Default M(l) value
	 * @param  min: Minimum M(l) value
	 * @param  max: Maximum M(l) value
	 * @retval None
	 */
	void setMl(double def, double min, double max);

	/**
	 * @brief  Get the M(l) values.
	 * @param  None
	 * @retval M(l) of the nmos.
	 */
	Ml getMl();

private:
	
	/** Object of Ml data type to store the M(l) values. */
	Ml ml;
};

#endif /* NMOS_H_ */
