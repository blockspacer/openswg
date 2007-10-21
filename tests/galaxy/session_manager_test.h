/**
 * session_manager_test.h: Unit tests for the SessionManager class.
 *
 * Copyright (C) 2006, 2007 OpenSWG Team <http://www.openswg.com>
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

#ifndef GALAXY_TESTS_SESSION_MANAGER_TEST_H
#define GALAXY_TESTS_SESSION_MANAGER_TEST_H

#include <cppunit/extensions/HelperMacros.h>

class SessionManagerTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(SessionManagerTest);
    CPPUNIT_TEST(testCanAddAndFindSessions);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp();
    void tearDown();

    void testCanAddAndFindSessions();
};

#endif // GALAXY_TESTS_SESSION_MANAGER_TEST_H

