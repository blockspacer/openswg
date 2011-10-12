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

#ifndef OPENSWG_SOEPROTOCOL_TANO3MESSAGE
#define OPENSWG_SOEPROTOCOL_TANO3MESSAGE

#include <cstdint>
#include <string>

#include <gsNetwork/binarypacket.h>
#include <gsNetwork/networkmessage.h>

namespace osSOEProtocol
{
	class Tano3Message : public gsNetwork::NetworkMessage
	{
	public:
		std::string customName;
		std::string color;
		std::string type;
		std::string category; // ??
		uint64_t objectId;

		Tano3Message();
		Tano3Message(gsNetwork::BinaryPacketPtr packet);
		virtual ~Tano3Message();

		virtual gsNetwork::BinaryPacketPtr serialize();
		virtual void unserialize();
	};
}

#endif // OPENSWG_SOEPROTOCOL_TANO3MESSAGE