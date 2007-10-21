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

#include <osSOEProtocol/serverheadermessage.h>
#include <osSOEProtocol/opcodes.h>
#include <gsNetwork/gamesocket.h>

using namespace gsNetwork;
using namespace osSOEProtocol;

ServerHeaderMessage::ServerHeaderMessage()
: NetworkMessage()
{
	setPriority(0);
	setResend(true);
	setEncrypt(true);
	setCrc(true);
}

ServerHeaderMessage::ServerHeaderMessage(BinaryPacketPtr packet)
: NetworkMessage()
{
	setPriority(0);
	setEncrypt(true);
	setResend(true);
	setCrc(true);
	m_serializedData = packet;
}

ServerHeaderMessage::~ServerHeaderMessage()
{}

BinaryPacketPtr ServerHeaderMessage::serialize()
{
    BinaryPacketPtr packet(new BinaryPacket);
    *packet << (uint16)SOE_CHL_DATA_A;
    *packet << (uint16)htons(getSequence());
    *packet << htons(25);

    *packet << (uint8)(8+this->serverType.length());
    *packet << (uint16)2;
    *packet << (uint32)SMSG_LS_STRING;
    *packet << (uint16)this->serverType.length();
    packet->append<std::string>(this->serverType);

    *packet << (uint8)10;
    *packet << (uint16)2;
    *packet << (uint32)SMSG_LS_NUM;
    *packet << this->serverId;
	*packet << (uint8)0;
	*packet << (uint16)0;

	return packet;
}

void ServerHeaderMessage::unserialize()
{
}

