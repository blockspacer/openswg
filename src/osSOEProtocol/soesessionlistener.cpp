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

#include <gsCore/globals.h>
#include <gsCore/log.h>
#include <gsNetwork/events.h>
#include <gsServer/sessionevents.h>
#include <osSOEProtocol/opcodes.h>
#include <osSOEProtocol/soesession.h>
#include <osSOEProtocol/soesessionlistener.h>
#include <osSOEProtocol/soelayermessages.h>

using namespace gsCore;
using namespace gsNetwork;
using namespace gsServer;
using namespace osSOEProtocol;

SOESessionListener::SOESessionListener(SessionManager* sessionManager)
: m_sessionManager(sessionManager)
{}

SOESessionListener::~SOESessionListener()
{}

bool SOESessionListener::handleEvent(Event const & event)
{
    if (_stricmp(event.getType().getStr(), Event_RemoteMessage::gkName) == 0)
    {
		EventData_RemoteMessage * eventData = event.getDataPtr<EventData_RemoteMessage>();
		
		uint16 opcode = eventData->packet->read<uint16>();
		if (opcode == SOE_SESSION_REQUEST)
		{
			boost::shared_ptr<SessionRequestMessage> message(GS_NEW SessionRequestMessage(eventData->packet));
			message->unserialize();
		
			boost::optional<SessionPtr> session = m_sessionManager->createSession(message, eventData->address, eventData->socket);
			
			if (! session)
			{
				Log::getMainLog().error("Unable to create session for %s", eventData->address->getAddressString().c_str());
				return true;			
			}
			
			Log::getMainLog().debug("Session created for [%s]", eventData->address->getAddressString().c_str());
			Log::getMainLog().debug("Session Count: [%i]", m_sessionManager->countSessions());
		}
    }

    if (_stricmp(event.getType().getStr(), Event_DisconnectRequested::gkName) == 0)
    {
        EventData_DisconnectRequested * eventData = event.getDataPtr<EventData_DisconnectRequested>();		
		eventData->session->setValid(false);	
	}

	return false;
}

