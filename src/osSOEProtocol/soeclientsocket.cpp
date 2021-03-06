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

#include <gsCore/eventmanager.h>
#include <gsNetwork/events.h>
#include <gsServer/sessionevents.h>

#include <osSOEProtocol/soepackettools.h>
#include <osSOEProtocol/compression.h>
#include <osSOEProtocol/encryption.h>
#include <osSOEProtocol/soeclientsocket.h>
#include <osSOEProtocol/opcodes.h>
#include <osSOEProtocol/soesession.h>

#include <osSOEProtocol/soelayermessages.h>

using namespace gsCore;
using namespace gsNetwork;
using namespace gsServer;
using namespace osSOEProtocol;

SOEClientSocket::SOEClientSocket(SessionManager* sessionManager, boost::asio::io_service &io_service, uint16_t port)
: ClientSocket(io_service, port)
, m_sessionManager(sessionManager)
{}

bool SOEClientSocket::handleRemoteIncoming(std::shared_ptr<BinaryPacket> packet, std::shared_ptr<NetworkAddress> address)
{
	// Lookup the session in the session manager.
	boost::optional<SessionPtr> sessionLookup 
		= m_sessionManager->findSession(ToString(*address));

	// Decrypt/decompress the packet if a valid session was returned.
	if (sessionLookup && (*sessionLookup)->isValid())
	{
		Encryption::decrypt(packet, (*sessionLookup)->getCrcSeed());
		Compression::decompress(packet);
        
		(*sessionLookup)->handleIncoming(packet);
		return true;
	}	    
		
    return false;
}

void SOEClientSocket::sendPacket(std::shared_ptr<gsNetwork::BinaryPacket> packet, std::shared_ptr<gsNetwork::NetworkAddress> address, bool encrypt, bool compress, bool crc)
{
	boost::optional<SessionPtr> sessionLookup = m_sessionManager->findSession(ToString(*address));

	if (sessionLookup && (*sessionLookup)->isValid())
	{
        SOESessionPtr session(std::dynamic_pointer_cast<SOESession>(*sessionLookup));
        
		PrepareSOEPacket(packet, session, encrypt, compress, crc);

        UdpEventSocket::sendPacket(packet, address);
	}
}

