/**
 * Galaxy Open-Source Massively Multiplayer Game Simulation Engine
 * Copyright (C) 2007 OpenSWG Team <http://www.openswg.com>
 */

// *********************************************************************
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// To read the license please visit http://www.gnu.org/copyleft/gpl.html
// *********************************************************************

#ifndef OPENSWG_SOEPROTOCOL_PLAYERCREATUREOBJECT
#define OPENSWG_SOEPROTOCOL_PLAYERCREATUREOBJECT

#include <osSOEProtocol/export.h>
#include <boost/shared_ptr.hpp>
#include <osSOEProtocol/creatureobject.h>

namespace osSOEProtocol
{
	class OS_SOEPROTOCOL_EXPORT PlayerCreatureObject : public CreatureObject
	{
	public:
		PlayerCreatureObject() {}
		virtual ~PlayerCreatureObject(){}

		void setGalaxyId(uint64 galaxyId) { m_galaxyId = galaxyId; }
		uint64 getGalaxyId() { return m_galaxyId; }

		void setFirstname(std::string firstname) { m_firstname = firstname; }
		std::string getFirstname() { return m_firstname; }

		void setSurname(std::string surname) { m_surname = surname; }
		std::string getSurname() { return m_surname; }
		
		void setHair(std::string hair) { m_hair = hair; }
		std::string getHair() { return m_hair; }
		
		void setHairData(std::string hairData) { m_hairData = hairData; }
		std::string getHairData() { return m_hairData; }
		
		void setBiography(std::string biography) { m_biography = biography; }
		std::string getBiography() { return m_biography; }
		
		void setBankCredits(uint32 bankCredits) { m_bankCredits = bankCredits; }
		uint32 getBankCredits() { return m_bankCredits; }

		void setInventoryCredits(uint32 inventoryCredits) { m_inventoryCredits = inventoryCredits; }
		uint32 getInventoryCredits() { return m_inventoryCredits; }

	private:
		std::string m_firstname;
		std::string m_surname;
		std::string m_hair;
		std::string m_hairData;
		std::string m_biography;
		uint32 m_bankCredits;
		uint32 m_inventoryCredits;
		uint64 m_galaxyId;
	};

	typedef OS_SOEPROTOCOL_EXPORT boost::shared_ptr<PlayerCreatureObject> PlayerCreatureObjectPtr;
}

#endif // OPENSWG_SOEPROTOCOL_PLAYERCREATUREOBJECT