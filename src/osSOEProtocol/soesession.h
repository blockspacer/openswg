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

#ifndef OPENSWG_SOEPROTOCOL_SOESESSION
#define OPENSWG_SOEPROTOCOL_SOESESSION

#include <gsNetwork/network_address.h>
#include <gsServer/session.h>

#include <memory>

#include <map>

namespace osSOEProtocol
{
	class SOESession : public gsServer::Session
    {
    public:
		SOESession(std::shared_ptr<gsNetwork::NetworkAddress> address, std::shared_ptr<gsNetwork::UdpEventSocket> socket);

		void handleSOELayer(std::shared_ptr<gsNetwork::BinaryPacket> packet);
		void processClientCommand(std::shared_ptr<gsNetwork::BinaryPacket> packet);
		
		uint32_t getConnectionId() { return m_connectionId; }
		void setConnectionId(uint32_t connectionId) { m_connectionId = connectionId; }

		uint32_t getMaxPacketSize() { return m_maxPacketSize; }
		void setMaxPacketSize(uint32_t maxPacketSize) { m_maxPacketSize = maxPacketSize; }

	protected:
		virtual void processIncomingQueue();

		uint32_t m_crcSeed;
		uint32_t m_connectionId;
		uint32_t m_maxPacketSize;
    };

	typedef std::shared_ptr<SOESession> SOESessionPtr;
}

#endif // OPENSWG_SOEPROTOCOL_SOESESSION

