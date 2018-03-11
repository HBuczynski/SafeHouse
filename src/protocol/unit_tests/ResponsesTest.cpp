#define BOOST_TEST_MODULE ResponsesTest

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "../DataResponse.h"
#include "../AckResponse.h"
#include "../MotorStatusResponse.h"
#include "../BlindsStatusResponse.h"
#include "../ErrorResponse.h"

#include <string>

using namespace std;
using namespace communication;

BOOST_AUTO_TEST_SUITE( data )

    BOOST_AUTO_TEST_CASE( dataResponse )
    {
        string data("Temp data");
        DataResponse response(data);
        response.getFrameBytes();

        BOOST_CHECK( FrameType::RESPONSE == response.getFrameType());
        BOOST_CHECK( ResponseType::DATA == response.getResponseType());
        BOOST_CHECK( data == response.getData());
        BOOST_CHECK( 1 == response.getSystemVersion());
        BOOST_CHECK( (sizeof(ResponseType::DATA)+data.size()+sizeof(END_STRING_IN_FRAME)) == response.getDataSize());
        BOOST_CHECK( "DataResponse" == response.getName());
    }

    BOOST_AUTO_TEST_CASE( ackResponse )
    {
        AckResponse response(AckType::OK);
        response.getFrameBytes();

        BOOST_CHECK( FrameType::RESPONSE == response.getFrameType());
        BOOST_CHECK( ResponseType::ACK == response.getResponseType());
        BOOST_CHECK( AckType::OK == response.getAckType());
        BOOST_CHECK( 1 == response.getSystemVersion());
        BOOST_CHECK( (sizeof(ResponseType::ACK) + sizeof(AckType::FAIL)) == response.getDataSize());
        BOOST_CHECK( "AckResponse" == response.getName());
    }

    BOOST_AUTO_TEST_CASE( blindsStatusResponse )
    {
        const auto status = BlindsStatus::DOWN;
        const auto mode = BlindsMode::AUTOMATIC;
        BlindsStatusResponse response(status, mode);
        response.getFrameBytes();

        BOOST_CHECK( FrameType::RESPONSE == response.getFrameType());
        BOOST_CHECK( ResponseType::BLINDS_STATUS_RSP == response.getResponseType());
        BOOST_CHECK( status == response.getBlindsStatus());
        BOOST_CHECK( mode == response.getBlindsMode());
        BOOST_CHECK( 1 == response.getSystemVersion());
        BOOST_CHECK( (sizeof(ResponseType::BLINDS_STATUS_RSP) + sizeof(BlindsMode::AUTOMATIC) + sizeof(BlindsStatus::DOWN)) == response.getDataSize());
        BOOST_CHECK( "BlindsStatusResponse" == response.getName());
    }

    BOOST_AUTO_TEST_CASE( motorStatusResponse )
    {
        const auto status = MotorStatus::START;
        MotorStatusResponse response(status);
        response.getFrameBytes();

        BOOST_CHECK( FrameType::RESPONSE == response.getFrameType());
        BOOST_CHECK( ResponseType::MOTOR_STATUS == response.getResponseType());
        BOOST_CHECK( status == response.getMotorStatus());
        BOOST_CHECK( 1 == response.getSystemVersion());
        BOOST_CHECK( (sizeof(ResponseType::MOTOR_STATUS) + sizeof(MotorStatus::START)) == response.getDataSize());
        BOOST_CHECK( "MotorStatusResponse" == response.getName());
    }

    BOOST_AUTO_TEST_CASE( errorResponse )
    {
        const auto error = ErrorType::CONNECTION_TIMEOUT;
        ErrorResponse response(error);
        response.getFrameBytes();

        BOOST_CHECK( FrameType::RESPONSE == response.getFrameType());
        BOOST_CHECK( ResponseType::ERROR == response.getResponseType());
        BOOST_CHECK( error == response.getErrorType());
        BOOST_CHECK( 1 == response.getSystemVersion());
        BOOST_CHECK( (sizeof(ResponseType::ERROR) + sizeof(ErrorType::CONNECTION_TIMEOUT)) == response.getDataSize());
        BOOST_CHECK( "ErrorResponse" == response.getName());
    }
BOOST_AUTO_TEST_SUITE_END()

