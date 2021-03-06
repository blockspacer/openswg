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

#include <gsServer/sessionevents.h>
#include <gsNetwork/events.h>
#include <osSOEProtocol/soesession.h>
#include <osSOEProtocol/soesocketeventlistener.h>
#include <osSOEProtocol/sessionresponsemessage.h>

using namespace gsCore;
using namespace gsNetwork;
using namespace gsServer;
using namespace osSOEProtocol;

SOESocketEventListener::SOESocketEventListener(std::shared_ptr<SOEClientSocket> socket)
: m_socket(socket)
{}

SOESocketEventListener::~SOESocketEventListener()
{}
	
bool SOESocketEventListener::handleEvent(const Event &event)
{
	return false;
}

