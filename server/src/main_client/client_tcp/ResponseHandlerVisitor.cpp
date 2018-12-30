#include "ResponseHandlerVisitor.h"

using namespace std;
using namespace communication;
using namespace utility;

ResponseHandlerVisitor::ResponseHandlerVisitor()
    : logger_(Logger::getInstance())
{}

ResponseHandlerVisitor::~ResponseHandlerVisitor()
{}

void ResponseHandlerVisitor::visit(AckResponse &data)
{
    if(logger_.isInformationEnable())
    {
        string message;
        if (data.getAckType() == AckType::OK) {
            message = string("ResponseHandlerVisitor :: Received AckResponse, ackTYPE: OK");
        } else {
            message = string("ResponseHandlerVisitor :: Received AckResponse, ackTYPE: FAIL");
        }

        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }
}

void ResponseHandlerVisitor::visit(DataResponse &data)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("ResponseHandlerVisitor :: Received DataResponse, data: ") + data.getData();
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }
}

void ResponseHandlerVisitor::visit(ErrorResponse &data)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("ResponseHandlerVisitor :: Received DataResponse, data: ") + to_string(data.getErrorType());
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }
}

void ResponseHandlerVisitor::visit(MotorStatusResponse &data)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("ResponseHandlerVisitor :: Received DataResponse, data: ") + to_string(data.getMotorStatus());
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }
}

void ResponseHandlerVisitor::visit(GuardStatusResponse &data)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("ResponseHandlerVisitor :: Received DataResponse, data: ") + to_string(data.getGuardStatus());
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }
}

void ResponseHandlerVisitor::visit(BlindsStatusResponse &data)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("ResponseHandlerVisitor :: Received DataResponse, data: ") + to_string(data.getBlindsStatus());
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }
}

void ResponseHandlerVisitor::visit(AuthenticateResponse& data)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("ResponseHandlerVisitor :: Received Authentication message.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }
}

void ResponseHandlerVisitor::visit(SensorTagSamplesResponse& data)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("ResponseHandlerVisitor :: Received SensorTagSamplesResponse message.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }
}

void ResponseHandlerVisitor::visit(PlotResponse& data)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("ResponseHandlerVisitor :: Received SensorTagSamplesResponse message.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }
}