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

#ifndef OPENSWG_SOEPROTOCOL_CREATUREOBJECTPROXY
#define OPENSWG_SOEPROTOCOL_CREATUREOBJECTPROXY

#include <osSOEProtocol/moods.h>
#include <osSOEProtocol/objectproxy.h>

namespace osSOEProtocol
{
	class CreatureObjectProxy : public ObjectProxy
	{
	public:
		CreatureObjectProxy();
		virtual void createTemplate();
		virtual void loadFromDatabaseId(uint64_t objectId) {};
		virtual void addInRange(std::shared_ptr<ObjectProxy> object){};
		virtual void sendInRange(gsNetwork::NetworkMessagePtr message){};
		virtual void sendReliableUpdate(gsServer::Session* session);
		virtual void store() {}

		virtual void update(uint64_t updateTimestamp) {}
		virtual void buildPropertyMap();

	protected:
		virtual void createObject();
	};

	typedef std::shared_ptr<CreatureObjectProxy> CreatureObjectProxyPtr;
}

#endif // OPENSWG_SOEPROTOCOL_CREATUREOBJECTPROXY

