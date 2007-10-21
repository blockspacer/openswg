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

#ifndef GALAXY_SERVER_SESSION
#define GALAXY_SERVER_SESSION

#include <gsCore/process.h>
#include <gsNetwork/gamesocket.h>
#include <gsNetwork/networkaddress.h>
#include <gsNetwork/networkmessage.h>
#include <gsNetwork/priorityqueue.h>
#include <gsServer/export.h>
#include <gsServer/opcodehandler.h>

#include <boost/shared_ptr.hpp>

#include <map>

namespace gsServer
{
    class GS_SERVER_EXPORT Session 
    {
    public:
		enum States
		{
			ACCEPTED = 0,
			LOGIN,
			CHARACTER_SELECTION,
			ZONING,
			ZONE_DOWN,
			READY,
			DEAD
		};
		Session(gsNetwork::NetworkAddressPtr address, gsNetwork::GameSocket* socket);

        bool isValid();
        void setValid(bool valid);

		bool isLoggedIn() { return m_isLoggedIn; }
		void setLoggedIn(bool loggedIn) { m_isLoggedIn = loggedIn; }

		bool isAuthenticated() { return m_isAuthenticated; }
		void setAuthenticated(bool authenticated) { m_isAuthenticated = authenticated; }

        void setLastUpdateTime(uint64 lastUpdateTime);
        uint64 getLastUpdateTime();

		virtual void update();

		virtual void sendToRemote(gsNetwork::NetworkMessagePtr message);
		virtual void handleIncoming(gsNetwork::BinaryPacketPtr packet);

        void setRemoteAddress(gsNetwork::NetworkAddressPtr address);
        gsNetwork::NetworkAddressPtr getRemoteAddress();
		
		void setOpcodeFactory(OpcodeFactory* opcodeFactory) { m_opcodeFactory = opcodeFactory; }
		OpcodeFactory* getOpcodeFactory() { return m_opcodeFactory; }

		std::string getUsername() {return m_username; }
		void setUsername(std::string username) { m_username = username; }

		uint32 getAccountId() {return m_accountId; }
		void setAccountId(uint32 accountId) { m_accountId = accountId; }

		void setClientSequence(uint16 sequence) {m_clientSequence = sequence; }
		uint16 getClientSequence() {return m_clientSequence; }

		void setClientVersion(uint version) { m_version = version; }
		uint getClientVersion() { return m_version; }

		uint32 getCrcSeed() { return m_crcSeed; }
		void setCrcSeed(uint32 crcSeed) { m_crcSeed = crcSeed; }
    protected:
		virtual void processIncomingQueue() {}

		uint32 m_crcSeed;
		uint m_version;
		bool m_isValid;
		bool m_isAuthenticated;
		bool m_isLoggedIn;
		uint32 m_accountId;
        uint64 m_lastUpdateTime;
		uint16 m_clientSequence;
		OpcodeFactory* m_opcodeFactory;
		std::string m_username;
		std::list<gsNetwork::BinaryPacketPtr> m_incomingQueue;
		gsNetwork::PriorityQueue* m_remoteMessageQueue;

		gsNetwork::GameSocket* m_remoteSocket;

        gsNetwork::NetworkAddressPtr m_remoteAddress;
    };

    typedef GS_SERVER_EXPORT boost::shared_ptr<Session> SessionPtr;
}

#endif // GALAXY_SERVER_SESSION

