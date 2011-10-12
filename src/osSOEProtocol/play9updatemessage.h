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

#ifndef OPENSWG_SOEPROTOCOL_PLAY9UPDATEMESSAGE
#define OPENSWG_SOEPROTOCOL_PLAY9UPDATEMESSAGE

#include <gsNetwork/binarypacket.h>
#include <gsNetwork/networkmessage.h>

namespace osSOEProtocol
{
	class Play9UpdateMessage : public gsNetwork::NetworkMessage
	{
	public:
		uint64_t objectId;

		Play9UpdateMessage();
		Play9UpdateMessage(gsNetwork::BinaryPacketPtr packet);
		virtual ~Play9UpdateMessage();

		virtual gsNetwork::BinaryPacketPtr serialize();
		virtual void unserialize();
	};
}

#endif // OPENSWG_SOEPROTOCOL_PLAY9UPDATEMESSAGE