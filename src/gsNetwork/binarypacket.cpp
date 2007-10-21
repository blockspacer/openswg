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
#include <gsCore/macros.h>
#include <gsNetwork/binarypacket.h>
#include <sstream>

using namespace gsCore;
using namespace gsNetwork;


    BinaryPacket::BinaryPacket()
    : m_readPosition(0), m_writePosition(0)
    {
        m_packetData.reserve(DEFAULT_SIZE);
        m_timestamp = 0;
    }

    BinaryPacket::BinaryPacket(const char *data, size_t length)
    : m_readPosition(0), m_writePosition(0)
    {
        m_packetData.reserve(DEFAULT_SIZE);
        m_timestamp = 0;
		  
		for (uint i=0; i < length; ++i)
			append<char>(data[i]);
    }

    BinaryPacket::~BinaryPacket()
    {}

    char * BinaryPacket::getData() const
    {   
        return (char*)&m_packetData[0];
    }

    char * BinaryPacket::getData(uint offset) const
    {
        return (char*)&m_packetData[offset];
    }

    uint32 BinaryPacket::getLength() const
    {   
        return (uint32)m_packetData.size();
    }

    void BinaryPacket::clear()
    {
        m_packetData.clear();
        m_readPosition = m_writePosition = 0;
    }

    void BinaryPacket::setTimestamp(uint64 timestamp)
    {
        m_timestamp = timestamp;
    }

    uint64 BinaryPacket::getTimestamp()
    {
        return m_timestamp;
    }

    void BinaryPacket::setReadPosition(size_t position)
    {
        m_readPosition = position;
    }

    size_t BinaryPacket::getReadPosition()
    {
        return m_readPosition;
    }

    void BinaryPacket::setWritePosition(size_t position)
    {
        m_writePosition = position;
    }

    size_t BinaryPacket::getWritePosition()
    {
        return m_writePosition;
    }

    /**
     * Formats the packet for logging:<br>
     * YYYY-MM-DD 00:00:00   0.0.0.0:0000 -> 0.0.0.0:0000 (From -> To)<br>
     * Packet Type	Encrypted: T/F	Compressed T/F
     * <br>
     * 0000:	00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................<br>
     * 0001:	00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................<br>
     * <br><br>
     **/
    std::string BinaryPacket::getLogString()
    {
    	std::stringstream message;

        uint32 length = getLength();
    
        char* data = GS_NEW char[length];
        memcpy(data, (char*)&m_packetData[0], length);

	    uint16 lines = (uint16)(length / 16);
        uint16 extra = (uint16)(length % 16);

			char tmp[100];
        for (uint16 i = 0; i < lines; i++)
        {
			
		    sprintf(tmp, "%4.4X:   %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
			        i * 16,
                    (uint8)data[0], (uint8)data[1], (uint8)data[2], (uint8)data[3], (uint8)data[4], (uint8)data[5], (uint8)data[6], (uint8)data[7], (uint8)data[8], (uint8)data[9], (uint8)data[10], (uint8)data[11], (uint8)data[12], (uint8)data[13], (uint8)data[14], (uint8)data[15],
                    atoc(data[0]), atoc(data[1]), atoc(data[2]), atoc(data[3]), atoc(data[4]), atoc(data[5]), atoc(data[6]), atoc(data[7]), atoc(data[8]), atoc(data[9]), atoc(data[10]), atoc(data[11]), atoc(data[12]), atoc(data[13]), atoc(data[14]), atoc(data[15]));
            data+=16;
		
            message << tmp;
	    }

	    if (extra)
        {
	        sprintf(tmp, "%4.4x:   ", lines * 16);
		    message << tmp;

		    uint16 i;
            for (i = 0; i < extra; i++)
            {
				sprintf(tmp, "%2.2X ", (uint8)data[i]);
			    message << tmp;
            }

		    for (; i < 16; i++)
            {
			    message << "   ";
            }

		    message << "  ";

            for (i = 0; i < extra;i++)
            {
			    sprintf(tmp, "%c", atoc(data[i]));
			    message << tmp;
            }

		    message << std::endl;
	    }

	    return message.str();
    }

