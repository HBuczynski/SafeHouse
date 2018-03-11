#define BOOST_TEST_MODULE CommandTest

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "protocol/BlindsUPCommand.h"
#include "protocol/BlindsDOWNCommand.h"
#include "protocol/BlindsUPOnTimeCommand.h"
#include "protocol/BlindsDOWNOnTimeCommand.h"
#include "protocol/BlindsStatusCommand.h"
#include "protocol/AutomaticBlindsCommand.h"
#include "protocol/TemperatureDemandCommand.h"
#include "protocol/UserOutOfHomeCommand.h"
#include "protocol/EndConnectionCommand.h"
#include "protocol/SnapshotCommand.h"

using namespace std;
using namespace communication;

BOOST_AUTO_TEST_SUITE( commands )

    BOOST_AUTO_TEST_CASE( blindsUpCommand )
    {
        BlindsUPCommand command;
        command.getFrameBytes();

        BOOST_CHECK( FrameType::COMMAND == command.getFrameType());
        BOOST_CHECK( CommandType::BLINDS_UP == command.getCommandType());
        BOOST_CHECK( 1 == command.getSystemVersion());
        BOOST_CHECK( sizeof(CommandType::BLINDS_UP) == command.getDataSize());
        BOOST_CHECK( "BlindsUPCommand" == command.getName());
    }

    BOOST_AUTO_TEST_CASE( blindsDownCommand )
    {
        BlindsDOWNCommand command;
        command.getFrameBytes();

        BOOST_CHECK( FrameType::COMMAND == command.getFrameType());
        BOOST_CHECK( CommandType::BLINDS_DOWN == command.getCommandType());
        BOOST_CHECK( 1 == command.getSystemVersion());
        BOOST_CHECK( (sizeof(CommandType::BLINDS_DOWN)) == command.getDataSize());
        BOOST_CHECK( "BlindsDOWNCommand" == command.getName());
    }

    BOOST_AUTO_TEST_CASE( blindsUpOnTimeCommand )
    {
        uint32_t epochTime = 3546732;
        BlindsUPOnTimeCommand command(epochTime);
        command.getFrameBytes();

        BOOST_CHECK( epochTime == command.getEpochDateAndTime());
        BOOST_CHECK( FrameType::COMMAND == command.getFrameType());
        BOOST_CHECK( CommandType::BLINDS_UP_ON_TIME == command.getCommandType());
        BOOST_CHECK( 1 == command.getSystemVersion());
        BOOST_CHECK( (sizeof(epochTime)+sizeof(CommandType::BLINDS_UP_ON_TIME)) == command.getDataSize());
        BOOST_CHECK( "BlindsUPOnTimeCommand" == command.getName());
    }

    BOOST_AUTO_TEST_CASE( blindsDownOnTimeCommand )
    {
        uint32_t epochTime = 3546732;
        BlindsDOWNOnTimeCommand command(epochTime);
        command.getFrameBytes();

        BOOST_CHECK( epochTime == command.getEpochDateAndTime());
        BOOST_CHECK( FrameType::COMMAND == command.getFrameType());
        BOOST_CHECK( CommandType::BLINDS_DOWN_ON_TIME == command.getCommandType());
        BOOST_CHECK( 1 == command.getSystemVersion());
        BOOST_CHECK( (sizeof(epochTime)+ sizeof(CommandType::BLINDS_DOWN_ON_TIME)) == command.getDataSize());
        BOOST_CHECK( "BlindsDOWNOnTimeCommand" == command.getName());
    }

    BOOST_AUTO_TEST_CASE( blindsStatusCommand )
    {
        BlindsStatusCommand command;
        command.getFrameBytes();

        BOOST_CHECK( FrameType::COMMAND == command.getFrameType());
        BOOST_CHECK( CommandType::BLINDS_STATUS == command.getCommandType());
        BOOST_CHECK( 1 == command.getSystemVersion());
        BOOST_CHECK( sizeof(CommandType::BLINDS_STATUS) == command.getDataSize());
        BOOST_CHECK( "BlindsStatusCommand" == command.getName());
    }

    BOOST_AUTO_TEST_CASE( automaticBlindsCommand )
    {
        AutomaticBlindsCommand command;
        command.getFrameBytes();

        BOOST_CHECK( FrameType::COMMAND == command.getFrameType());
        BOOST_CHECK( CommandType::AUTOMATIC_BLINDS == command.getCommandType());
        BOOST_CHECK( 1 == command.getSystemVersion());
        BOOST_CHECK( sizeof(CommandType::AUTOMATIC_BLINDS) == command.getDataSize());
        BOOST_CHECK( "BlindsStatusCommand" == command.getName());
    }

    BOOST_AUTO_TEST_CASE( temperatureDemandCommand )
    {
        TemperatureDemandCommand command;
        command.getFrameBytes();

        BOOST_CHECK( FrameType::COMMAND == command.getFrameType());
        BOOST_CHECK( CommandType::TEMPERATURE_DEMAND == command.getCommandType());
        BOOST_CHECK( 1 == command.getSystemVersion());
        BOOST_CHECK( sizeof(CommandType::TEMPERATURE_DEMAND) == command.getDataSize());
        BOOST_CHECK( "TemperatureDemandCommand" == command.getName());
    }

    BOOST_AUTO_TEST_CASE( userOutOfHomeCommand )
    {
        UserOutOfHomeCommand command;
        command.getFrameBytes();

        BOOST_CHECK( FrameType::COMMAND == command.getFrameType());
        BOOST_CHECK( CommandType::USER_OUT_OF_HOME == command.getCommandType());
        BOOST_CHECK( 1 == command.getSystemVersion());
        BOOST_CHECK( sizeof(CommandType::USER_OUT_OF_HOME) == command.getDataSize());
        BOOST_CHECK( "UserOutOfHomeCommand" == command.getName());
    }

    BOOST_AUTO_TEST_CASE( snapshotCommand )
    {
        SnapshotCommand command;
        command.getFrameBytes();

        BOOST_CHECK( FrameType::COMMAND == command.getFrameType());
        BOOST_CHECK( CommandType::SNAPSHOT == command.getCommandType());
        BOOST_CHECK( 1 == command.getSystemVersion());
        BOOST_CHECK( sizeof(CommandType::SNAPSHOT) == command.getDataSize());
        BOOST_CHECK( "SnapshotCommand" == command.getName());
    }

    BOOST_AUTO_TEST_CASE( endConnectionCommand )
    {
        EndConnectionCommand command;
        command.getFrameBytes();

        BOOST_CHECK( FrameType::COMMAND == command.getFrameType());
        BOOST_CHECK( CommandType::END_CONNECTION == command.getCommandType());
        BOOST_CHECK( 1 == command.getSystemVersion());
        BOOST_CHECK( sizeof(CommandType::END_CONNECTION) == command.getDataSize());
        BOOST_CHECK( "EndConnectionCommand" == command.getName());
    }


BOOST_AUTO_TEST_SUITE_END()