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

#ifndef OPENSWG_SOEPROTOCOL_DATACHANNELMESSAGE
#define OPENSWG_SOEPROTOCOL_DATACHANNELMESSAGE

#include <gsNetwork/binarypacket.h>
#include <gsNetwork/networkmessage.h>

#include <list>

namespace osSOEProtocol
{
	class DataChannelMessage : public gsNetwork::NetworkMessage
	{
	public:
		std::list<std::shared_ptr<gsNetwork::BinaryPacket>> segments;
		uint16_t clientSequence;
		uint16_t delta;

		DataChannelMessage();
		DataChannelMessage(std::shared_ptr<gsNetwork::BinaryPacket> packet);
		virtual ~DataChannelMessage();

		virtual std::shared_ptr<gsNetwork::BinaryPacket> serialize();
		virtual void unserialize();
	};
}

#endif // OPENSWG_SOEPROTOCOL_DATACHANNELMESSAGE

