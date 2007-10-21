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

#ifndef GALAXY_SERVER_SESSIONEVENTS
#define GALAXY_SERVER_SESSIONEVENTS

#include <gsCore/eventmanager.h>
#include <gsCore/globals.h>
#include <gsCore/macros.h>
#include <gsServer/session.h>

namespace gsServer
{
    /**
     * 
     */
    struct GS_SERVER_EXPORT EventData_Acknowledge : public gsCore::IEventData
    {
		explicit EventData_Acknowledge(gsNetwork::NetworkMessagePtr inMessage, gsServer::Session* inSession)
            : message(inMessage)
			, session(inSession)
        {}

		gsNetwork::NetworkMessagePtr message;
		gsServer::Session* session;
    };

    class GS_SERVER_EXPORT Event_Acknowledge : public gsCore::Event
    {
    public:
        static char const * const gkName;
        explicit Event_Acknowledge(gsNetwork::NetworkMessagePtr message, gsServer::Session* session)
            : gsCore::Event(gkName,
                    0,
                    gsCore::IEventDataPtr(GS_NEW EventData_Acknowledge(message, session)))
        {}        
    };

    /**
     * 
     */
    struct GS_SERVER_EXPORT EventData_DisconnectRequested : public gsCore::IEventData
    {
		explicit EventData_DisconnectRequested(gsNetwork::NetworkMessagePtr inMessage, gsServer::Session* inSession)
            : message(inMessage)
			, session(inSession)
        {}

		gsServer::Session* session;
		gsNetwork::NetworkMessagePtr message;
    };

    class GS_SERVER_EXPORT Event_DisconnectRequested : public gsCore::Event
    {
    public:
        static char const * const gkName;
		explicit Event_DisconnectRequested(gsNetwork::NetworkMessagePtr message, gsServer::Session* session)
            : gsCore::Event(gkName,
                    0,
                    gsCore::IEventDataPtr(GS_NEW EventData_DisconnectRequested(message, session)))
        {}        
    };

    /**
     * 
     */
    struct GS_SERVER_EXPORT EventData_SessionRequested : public gsCore::IEventData
    {
		explicit EventData_SessionRequested(gsNetwork::NetworkMessagePtr inMessage, gsNetwork::NetworkAddressPtr inAddress, gsNetwork::GameSocket* inSocket)
            : message(inMessage)
			, address(inAddress)
			, socket(inSocket)
        {}

		gsNetwork::NetworkMessagePtr message;
		gsNetwork::NetworkAddressPtr address;
		gsNetwork::GameSocket* socket;
    };

    class GS_SERVER_EXPORT Event_SessionRequested : public gsCore::Event
    {
    public:
        static char const * const gkName;
        explicit Event_SessionRequested(gsNetwork::NetworkMessagePtr message, gsNetwork::NetworkAddressPtr address, gsNetwork::GameSocket* socket)
            : gsCore::Event(gkName,
                    0,
                    gsCore::IEventDataPtr(GS_NEW EventData_SessionRequested(message, address, socket)))
        {}        
    };

    /**
     * 
     */
    struct GS_SERVER_EXPORT EventData_SessionCreated : public gsCore::IEventData
    {
        explicit EventData_SessionCreated(SessionPtr inSessionPtr)
            : session(inSessionPtr)
        {}

        SessionPtr session;
    };

    class GS_SERVER_EXPORT Event_SessionCreated : public gsCore::Event
    {
    public:
        static char const * const gkName;
        explicit Event_SessionCreated(SessionPtr session)
            : gsCore::Event(gkName,
                    0,
                    gsCore::IEventDataPtr(GS_NEW EventData_SessionCreated(session)))
        {}        
    };
}

#endif // GALAXY_SERVER_SESSIONEVENTS

