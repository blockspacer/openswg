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

#include <osSOEProtocol/playinitmessage.h>
#include <osSOEProtocol/opcodes.h>
#include <gsNetwork/gamesocket.h>

using namespace gsNetwork;
using namespace osSOEProtocol;

PlayInitMessage::PlayInitMessage()
: NetworkMessage()
{
	setPriority(0);
	setResend(true);
	setEncrypt(true);
	setCrc(true);
}

PlayInitMessage::PlayInitMessage(BinaryPacketPtr packet)
: NetworkMessage()
{
	setPriority(0);
	setResend(true);
	setEncrypt(true);
	setCrc(true);
	m_serializedData = packet;
}

PlayInitMessage::~PlayInitMessage()
{}

BinaryPacketPtr PlayInitMessage::serialize()
{
    BinaryPacketPtr packet(new BinaryPacket);

    *packet << (uint16_t)SOE_CHL_DATA_A;
    *packet << (uint16_t)htons(getSequence());
    *packet << (uint16_t)5;
    *packet << (uint32_t)SMSG_OBJ_INIT;
    *packet << (uint64_t)objectId+7; // Plus offset?

    // Orientation (FLOAT)
    *packet << (float)0;
    *packet << (float)0;
    *packet << (float)0;

    // UNK
    *packet << (float)1.0;

    // Player Position (FLOAT)
    *packet << (float)0;
    *packet << (float)0;
    *packet << (float)0;

    // Object CRC
    *packet << (uint32_t)0x619BAE21;

    *packet << (uint8_t)0x00; //byte flag

    *packet << (uint8_t)0 << (uint16_t)0;

	return packet;
}

void PlayInitMessage::unserialize()
{
}
