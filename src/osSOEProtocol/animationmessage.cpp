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

#include <osSOEProtocol/animationmessage.h>
#include <osSOEProtocol/opcodes.h>
#include <gsNetwork/gamesocket.h>

using namespace gsNetwork;
using namespace osSOEProtocol;

AnimationMessage::AnimationMessage()
: NetworkMessage()
{
	setPriority(0);
	setResend(true);
	setEncrypt(true);
	setCrc(true);
}

AnimationMessage::AnimationMessage(BinaryPacketPtr packet)
: NetworkMessage()
{
	setPriority(0);
	setResend(true);
	setEncrypt(true);
	setCrc(true);
	m_serializedData = packet;
}

AnimationMessage::~AnimationMessage()
{}

BinaryPacketPtr AnimationMessage::serialize()
{
    BinaryPacketPtr packet(new BinaryPacket);

    *packet << (uint16)SOE_CHL_DATA_A;
    *packet << (uint16)htons(getSequence());

    *packet << (uint16)5;
    *packet << (uint32)AMSG_INT_PACKET;
    *packet << (uint32)27;
    *packet << (uint32)204;
    *packet << (uint64)objectId;
    *packet << (uint32)0;
    *packet << (uint32)animationCrc; // Animation crc?
    *packet << (uint64)objectId;
    *packet << (uint64)0;
    *packet << (uint8)posture;
	*packet << (uint8)0;
	*packet << (uint16)0;
	*packet << (uint32)0;
    *packet << (uint16)0;

    *packet << (uint8)0 << (uint16)0;

	return packet;
}

void AnimationMessage::unserialize()
{
}

