#define BOOST_TEST_MODULE FactoryTest

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "../CommandFactory.h"
#include "protocol/BlindsUPCommand.h"
#include "protocol/BlindsDOWNCommand.h"
#include "protocol/BlindsUPOnTimeCommand.h"
#include "protocol/BlindsDOWNOnTimeCommand.h"
#include "protocol/BlindsStatusCommand.h"
#include "protocol/AutomaticBlindsCommand.h"
#include "protocol/TemperatureDemandCommand.h"
#include "protocol/EndConnectionCommand.h"
#include "protocol/UserOutOfHomeCommand.h"
#include "protocol/SnapshotCommand.h"

using namespace std;
using namespace communication;

BOOST_AUTO_TEST_SUITE( factory )

    BOOST_AUTO_TEST_CASE( blindUpBuilder )
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

    BOOST_AUTO_TEST_CASE( blindDownBuilder )
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

    BOOST_AUTO_TEST_CASE( blindsUpOnTimeBuilder )
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

    BOOST_AUTO_TEST_CASE( blindsDownOnTimeBuilder )
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

    BOOST_AUTO_TEST_CASE( blindsStatusBuilder )
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

    BOOST_AUTO_TEST_CASE( automaticBlindsBuilder )
    {
        CommandFactory factory;
        AutomaticBlindsCommand command;

        auto commandFromVec = static_pointer_cast<AutomaticBlindsCommand, Command>(factory.createCommand(command.getFrameBytes()));

        BOOST_CHECK( commandFromVec->getFrameBytes() == command.getFrameBytes());
        BOOST_CHECK( commandFromVec->getCommandType() == command.getCommandType());
        BOOST_CHECK( 1 == commandFromVec->getSystemVersion());
        BOOST_CHECK( commandFromVec->getDataSize() == command.getDataSize());
        BOOST_CHECK( commandFromVec->getName() == command.getName());
    }

    BOOST_AUTO_TEST_CASE( temperatureDemandBuilder )
    {
        CommandFactory factory;
        TemperatureDemandCommand command;

        auto commandFromVec = static_pointer_cast<TemperatureDemandCommand, Command>(factory.createCommand(command.getFrameBytes()));

        BOOST_CHECK( commandFromVec->getFrameBytes() == command.getFrameBytes());
        BOOST_CHECK( commandFromVec->getCommandType() == command.getCommandType());
        BOOST_CHECK( 1 == commandFromVec->getSystemVersion());
        BOOST_CHECK( commandFromVec->getDataSize() == command.getDataSize());
        BOOST_CHECK( commandFromVec->getName() == command.getName());
    }

    BOOST_AUTO_TEST_CASE( userOutOfHomeBuilder )
    {
        CommandFactory factory;
        UserOutOfHomeCommand command;

        auto commandFromVec = static_pointer_cast<UserOutOfHomeCommand, Command>(factory.createCommand(command.getFrameBytes()));

        BOOST_CHECK( commandFromVec->getFrameBytes() == command.getFrameBytes());
        BOOST_CHECK( commandFromVec->getCommandType() == command.getCommandType());
        BOOST_CHECK( 1 == commandFromVec->getSystemVersion());
        BOOST_CHECK( commandFromVec->getDataSize() == command.getDataSize());
        BOOST_CHECK( commandFromVec->getName() == command.getName());
    }

    BOOST_AUTO_TEST_CASE( snapshotBuilder )
    {
        CommandFactory factory;
        SnapshotCommand command;

        auto commandFromVec = static_pointer_cast<SnapshotCommand, Command>(factory.createCommand(command.getFrameBytes()));

        BOOST_CHECK( commandFromVec->getFrameBytes() == command.getFrameBytes());
        BOOST_CHECK( commandFromVec->getCommandType() == command.getCommandType());
        BOOST_CHECK( 1 == commandFromVec->getSystemVersion());
        BOOST_CHECK( commandFromVec->getDataSize() == command.getDataSize());
        BOOST_CHECK( commandFromVec->getName() == command.getName());
    }

    BOOST_AUTO_TEST_CASE( endConnectionBuilder )
    {
        CommandFactory factory;
        EndConnectionCommand command;

        auto commandFromVec = static_pointer_cast<EndConnectionCommand, Command>(factory.createCommand(command.getFrameBytes()));

        BOOST_CHECK( commandFromVec->getFrameBytes() == command.getFrameBytes());
        BOOST_CHECK( commandFromVec->getCommandType() == command.getCommandType());
        BOOST_CHECK( 1 == commandFromVec->getSystemVersion());
        BOOST_CHECK( commandFromVec->getDataSize() == command.getDataSize());
        BOOST_CHECK( commandFromVec->getName() == command.getName());
    }

BOOST_AUTO_TEST_SUITE_END()
