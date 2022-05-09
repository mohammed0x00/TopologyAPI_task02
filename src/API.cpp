/*
 * API.cpp
 *
 *  Created on: May 6, 2022
 *      Author: mohammed
 */

#include <iostream>
#include <fstream>

/* ------ Include ------ */
#include "API.h"

/* ------ Variables ------ */
std::vector<Topology *> API::topologies;

/* ------ Functions ------ */
API::Result API::readJSON(FileName file)
{
	Topology * newTopology;
	Topology::TopologyIdType newTopologyId;
	Result status = Done;
    Json::Reader reader;
    Json::Value obj;

    std::ifstream ifs((std::string) file);
    if(reader.parse(ifs, obj))
    {
    	status = Done;
    	newTopologyId = (Topology::TopologyIdType)obj["id"].asString();
    }
    else
    {
    	status = Failed;
    }


    if(status == Done)
    {
    	for(Topology * t : topologies)
		{
			if(t->getId() == newTopologyId)
			{
				status = TopologyExists;
				break;
			}
		}
    }


    if(status == Done)
    {
    	newTopology = new Topology(newTopologyId);
    	newTopology->setId(newTopologyId);
    	topologies.push_back((TopologyListElement)newTopology);
    	const Json::Value& components = obj["components"]; // array of components
        for (Json::Value component : components){
        	std::string type = component["type"].asString();
        	if(type == RESISTOR_TYPE_STRING)
        	{
        		Resistor * newResistor = new Resistor();
        		Resistor::ResistanceNode def = component["resistance"]["default"].asUInt();
        		Resistor::ResistanceNode min = component["resistance"]["min"].asUInt();
        		Resistor::ResistanceNode max = component["resistance"]["max"].asUInt();
        		Device::NetlistNode t1 = component["netlist"]["t1"].asString();
        		Device::NetlistNode t2 = component["netlist"]["t2"].asString();
        		newTopology->addDevice(newResistor);
        		newResistor->setID(component["id"].asString());
        		newResistor->setResistance(def, min, max);
        		newResistor->setNetlistNode(Resistor::T1, t1);
        		newResistor->setNetlistNode(Resistor::T2, t2);

        	}
        	else if(type == NMOS_TYPE_STRING)
        	{
        		Nmos * newNmos = new Nmos();
        		Nmos::MlNode def = component["m(l)"]["default"].asDouble();
        		Nmos::MlNode min = component["m(l)"]["min"].asDouble();
        		Nmos::MlNode max = component["m(l)"]["max"].asDouble();
        		Device::NetlistNode drain = component["netlist"]["drain"].asString();
        		Device::NetlistNode gate = component["netlist"]["gate"].asString();
        		Device::NetlistNode source = component["netlist"]["source"].asString();
        		newTopology->addDevice(newNmos);
        		newNmos->setID(component["id"].asString());
        		newNmos->setMl(def, min, max);
        		newNmos->setNetlistNode(Nmos::drain, drain);
        		newNmos->setNetlistNode(Nmos::gate, gate);
        		newNmos->setNetlistNode(Nmos::source, source);
        	}
        	else
        	{

        	}
        }
    }

    if(status == Done)
    {
    	ifs.close();
    }
    return status;
}

API::Result API::writeJSON(Topology::TopologyIdType id)
{
	Result status = Done;
	Json::Value jsonValueTopology;
	Topology * myTopology;
	std::ofstream ofs;

	if(status == Done)
	{
		status = TopologyNotExists;
		for(Topology * top : topologies)
		{
			if(top->getId() == id)
			{
				status = Done;
				myTopology = (Topology *)top;
				break;
			}
		}
	}

	if(status == Done)
	{
		ofs.open (((std::string) myTopology->getId()) + ".json");
		if(ofs.is_open())
		{
			status = Done;
		}
		else
		{
			status = Failed;
		}
	}

	if(status == Done)
	{
		Json::Value components(Json::arrayValue);
		jsonValueTopology["id"] = ((std::string)myTopology->getId());
		Topology::DeviceList myDevList = myTopology->getDevices();
		for(size_t i = 0; i < myDevList.size; i++)
		{
			Device * dev = myDevList.list[i];
			if(dev->getType() == Device::resistor)
			{
				Resistor * res = (Resistor *)dev;
				Json::Value jsonResistor, jsonNetlist, jsonResistance;
				const Resistor::ResistanceType * resistance = res->getResistance();
				jsonResistor["type"] = RESISTOR_TYPE_STRING;
				jsonResistor["id"] = ((std::string)res->getID());
				jsonNetlist["t1"] = ((std::string)res->getNetlistNode(Resistor::T1));
				jsonNetlist["t2"] = ((std::string)res->getNetlistNode(Resistor::T2));
				jsonResistance["default"] = (int)(resistance->def);
				jsonResistance["min"] = (int)(resistance->min);
				jsonResistance["max"] = (int)(resistance->max);
				jsonResistor["resistance"] = jsonResistance;
				jsonResistor["netlist"] = jsonNetlist;
				components.append(jsonResistor);
			}
			else if(dev->getType() == Device::nmos)
			{
				Nmos * nmos = (Nmos *)dev;
				Json::Value jsonNmos, jsonNetlist, jsonMl;
				const Nmos::MlType * ml = nmos->getMl();
				jsonNmos["type"] = NMOS_TYPE_STRING;
				jsonNmos["id"] = ((std::string)nmos->getID());
				jsonNetlist["drain"] = ((std::string)nmos->getNetlistNode(Nmos::drain));
				jsonNetlist["gate"] = ((std::string)nmos->getNetlistNode(Nmos::gate));
				jsonNetlist["source"] = ((std::string)nmos->getNetlistNode(Nmos::source));
				jsonMl["default"] = (double)(ml->def);
				jsonMl["min"] = (double)(ml->min);
				jsonMl["max"] = (double)(ml->max);
				jsonNmos["m(l)"] = jsonMl;
				jsonNmos["netlist"] = jsonNetlist;
				components.append(jsonNmos);
			}
		}
		jsonValueTopology["components"] = components;
	}

	if(status == Done)
	{
		ofs << jsonValueTopology << std::endl;
		ofs.close();
	}
	return status;
}

API::TopologyList API::queryTopologies()
{
	return {topologies.data(), topologies.size()};
}

API::Result API::deleteTopology(Topology::TopologyIdType id)
{
	Result status = TopologyNotExists;
	for(size_t i = 0; i < topologies.size(); i++)
	{
		if(topologies[i]->getId() == id)
		{
			delete topologies[i];
			topologies.erase(topologies.begin() + i);
			status = Done;
			break;
		}
	}
	return status;
}
Topology::DeviceList API::queryDevices(Topology::TopologyIdType id)
{
	for(Topology * top : topologies)
	{
		if(top->getId() == id)
		{
			return top->getDevices();
		}
	}
	return {NULL, 0};
}

Topology::DeviceList API::queryDevicesWithNetlistNode(Topology::TopologyIdType topology_id, Device::NetlistNode node_id)
{
	std::vector<Topology::DeviceListElement> * list = new std::vector<Topology::DeviceListElement>;
	Topology::DeviceList toReturn;
	toReturn.size = 0;
	for(Topology * top : topologies)
	{
		if(top->getId() == topology_id)
		{
			for(size_t i = 0; i < top->getDevices().size; i++)
			{
				Device * dev = top->getDevices().list[i];
				if(dev->getType() == Device::resistor)
				{
					if(((Resistor *)dev)->getNetlistNode(Resistor::T1) == node_id)
					{
						list->push_back(dev);
						(toReturn.size)++;
					}
					else if(((Resistor *)dev)->getNetlistNode(Resistor::T2) == node_id)
					{
						list->push_back(dev);
						(toReturn.size)++;
					}
				}
				else if(dev->getType() == Device::nmos)
				{
					if(((Nmos *)dev)->getNetlistNode(Nmos::drain) == node_id)
					{
						list->push_back(dev);
						(toReturn.size)++;
					}
					else if(((Nmos *)dev)->getNetlistNode(Nmos::gate) == node_id)
					{
						list->push_back(dev);
						(toReturn.size)++;
					}
					else if(((Nmos *)dev)->getNetlistNode(Nmos::source) == node_id)
					{
						list->push_back(dev);
						(toReturn.size)++;
					}
				}
			}
		}
	}
	toReturn.list = list->data();
	return toReturn;
}

