#define BOOST_TEST_MODULE FactoryTest

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "../CommandFactory.h"
#include "protocol/BlindsUPCommand.h"
#include "protocol/BlindsDOWNCommand.h"
#include "protocol/BlindsUPOnTimeCommand.h"
#include "protocol/BlindsDOWNOnTimeCommand.h"
#include "protocol/BlindsStatusCommand.h"

using namespace std;
using namespace communication;

BOOST_AUTO_TEST_SUITE( factory )

    BOOST_AUTO_TEST_CASE( calibrateMagnetometerBuilder )
    {
        CommandFactory factory;
        BlindsUPCommand command;

        auto commandFromVec = static_pointer_cast<BlindsUPCommand, Command>(factory.createCommand(command.getFrameBytes()));
        BOOST_CHECK( commandFromVec->getFrameBytes() == command.getFrameBytes());
        BOOST_CHECK( commandFromVec->getCommandType() == command.getCommandType());
        BOOST_CHECK( 1 == commandFromVec->getSystemVersion());
        BOOST_CHECK( commandFromVec->getDataSize() == command.getDataSize());
        BOOST_CHECK( commandFromVec->getName() == command.getName());
    }

    BOOST_AUTO_TEST_CASE( collectDataBuilder )
    {
        CommandFactory factory;
        BlindsDOWNCommand command;

        auto commandFromVec = static_pointer_cast<BlindsDOWNCommand, Command>(factory.createCommand(command.getFrameBytes()));

        BOOST_CHECK( commandFromVec->getFrameBytes() == command.getFrameBytes());
        BOOST_CHECK( commandFromVec->getCommandType() == command.getCommandType());
        BOOST_CHECK( 1 == commandFromVec->getSystemVersion());
        BOOST_CHECK( commandFromVec->getDataSize() == command.getDataSize());
        BOOST_CHECK( commandFromVec->getName() == command.getName());
    }

    BOOST_AUTO_TEST_CASE( endConnectionBuilder )
    {
        CommandFactory factory;
        uint32_t epochTime = 3546732;
        BlindsUPOnTimeCommand command(epochTime);

        auto commandFromVec = static_pointer_cast<BlindsUPOnTimeCommand, Command>(factory.createCommand(command.getFrameBytes()));

        BOOST_CHECK( commandFromVec->getEpochDateAndTime() == command.getEpochDateAndTime());
        BOOST_CHECK( commandFromVec->getFrameBytes() == command.getFrameBytes());
        BOOST_CHECK( commandFromVec->getCommandType() == command.getCommandType());
        BOOST_CHECK( 1 == commandFromVec->getSystemVersion());
        BOOST_CHECK( commandFromVec->getDataSize() == command.getDataSize());
        BOOST_CHECK( commandFromVec->getName() == command.getName());
    }

    BOOST_AUTO_TEST_CASE( initConnectionBuilder )
    {
        CommandFactory factory;
        uint32_t epochTime = 3546732;
        BlindsDOWNOnTimeCommand command(epochTime);

        auto commandFromVec = static_pointer_cast<BlindsDOWNOnTimeCommand, Command>(factory.createCommand(command.getFrameBytes()));

        BOOST_CHECK( commandFromVec->getEpochDateAndTime() == command.getEpochDateAndTime());
        BOOST_CHECK( commandFromVec->getFrameBytes() == command.getFrameBytes());
        BOOST_CHECK( commandFromVec->getCommandType() == command.getCommandType());
        BOOST_CHECK( 1 == commandFromVec->getSystemVersion());
        BOOST_CHECK( commandFromVec->getDataSize() == command.getDataSize());
        BOOST_CHECK( commandFromVec->getName() == command.getName());
    }

    BOOST_AUTO_TEST_CASE( setPlaneMagnetometerBuilder )
    {
        CommandFactory factory;
        BlindsStatusCommand command;

        auto commandFromVec = static_pointer_cast<BlindsStatusCommand, Command>(factory.createCommand(command.getFrameBytes()));

        BOOST_CHECK( commandFromVec->getFrameBytes() == command.getFrameBytes());
        BOOST_CHECK( commandFromVec->getCommandType() == command.getCommandType());
        BOOST_CHECK( 1 == commandFromVec->getSystemVersion());
        BOOST_CHECK( commandFromVec->getDataSize() == command.getDataSize());
        BOOST_CHECK( commandFromVec->getName() == command.getName());
    }

BOOST_AUTO_TEST_SUITE_END()
