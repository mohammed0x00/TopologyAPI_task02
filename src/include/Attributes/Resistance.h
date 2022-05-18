/*******************************************************************************
 * @file    Resistance.h
 * @author  Mohammed Ali
 * @email   mmansour.mm5@gmailcom
 * @website https://github.com/mohammed0x00/
 * @date    10.05.2022
 *
 * @brief   Resistance Class
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

#ifndef RESISTANCE_H_
#define RESISTANCE_H_

/* ------ Include ------ */

/**
 * @brief  Resistance class
 */
class Resistance {
public:

	/* Public functions */

	/**
	 * @brief  Constructor of Resistance class.
	 */
	Resistance();
	
	/**
	 * @brief  Constructor of Resistance class.
	 * @param  def: Default resistance value
	 * @param  min: Minimum resistance value
	 * @param  max: Maximum resistance value
	 */
	Resistance(unsigned int def, unsigned int min, unsigned int max);

	/**
	 * @brief  Destructor of Resistance class.
	 */
	virtual ~Resistance();

	/**
	 * @brief  Set the default resistance value.
	 * @param  value: Default resistance value
	 * @retval None
	 */
	void setDefaultValue(unsigned int value);

	/**
	 * @brief  Set the minimum resistance value.
	 * @param  value: Minimum resistance value
	 * @retval None
	 */
	void setMinimumValue(unsigned int value);
	
	/**
	 * @brief  Set the maximum resistance value.
	 * @param  value: Maximum resistance value
	 * @retval None
	 */
	void setMaximumValue(unsigned int value);
	
	/**
	 * @brief  Get the default resistance value.
	 * @param  None
	 * @retval Default resistance value
	 */
	unsigned int getDefaultValue();

	/**
	 * @brief  Get the minimum resistance value.
	 * @param  None
	 * @retval Minimum resistance value
	 */
	unsigned int getMinimumValue();

	/**
	 * @brief  Get the maximum resistance value.
	 * @param  None
	 * @retval Maximum resistance value
	 */
	unsigned int getMaximumValue();

private:
	
	/** Object to store default value of resistance */
	unsigned int def;

	/** Object to store minimum value of resistance */
	unsigned int min;

	/** Object to store maximum value of resistance */
	unsigned int max;
};

#endif /* RESISTANCE_H_ */
