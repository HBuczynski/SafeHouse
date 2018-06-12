#include "CommandHandlerVisitor.h"

#include <protocol/DataResponse.h>
#include <main_rpi/server_tcp/ClientThreadTCP.h>

#include <sys/wait.h>
#include <iostream>
#include <unistd.h>
#include <cstring>

using namespace std;
using namespace utility;
using namespace peripherials;
using namespace communication;

extern char **environ;

bool CommandHandlerVisitor::isKilled = false;
utility::Logger& CommandHandlerVisitor::logger_ = Logger::getInstance();
const std::string CommandHandlerVisitor::STREAM_SCRIPT_PATH = "../../camera_scripts/";
const std::string CommandHandlerVisitor::STREAM_SCRIPT_NAME = "stream.sh";
posix_spawn_file_actions_t CommandHandlerVisitor::action_;
pid_t CommandHandlerVisitor::pid_;

CommandHandlerVisitor::CommandHandlerVisitor()
    :   periphManager_(PeriphManager::getInstance())
{}

CommandHandlerVisitor::~CommandHandlerVisitor()
{
    stopStream();
}

void CommandHandlerVisitor::visit(BlindsDOWNOnTimeCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: BlindsDOWNOnTimeCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runBlindsDOWNOnTime(command.getEpochDateAndTime());
}

void CommandHandlerVisitor::visit(BlindsUPOnTimeCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: BlindsUPOnTimeCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runBlindsUPOnTime(command.getEpochDateAndTime());
}

void CommandHandlerVisitor::visit(BlindsUPCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: BlindsUPCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runBlindsUP();
}

void CommandHandlerVisitor::visit(BlindsDOWNCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: BlindsDOWNCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runBlindsDOWN();
}

void CommandHandlerVisitor::visit(BlindsStatusCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: BlindsStatusCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runBlindsStatus();
}

void CommandHandlerVisitor::visit(AutomaticBlindsCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: AutomaticBlindsCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runAutomaticBlinds();
}

void CommandHandlerVisitor::visit(TemperatureDemandCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: TemperatureDemandCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runTemperatureDemand();
}

void CommandHandlerVisitor::visit(UserOutOfHomeCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: UserOutOfHomeCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runUserOutOfHome();
}

void CommandHandlerVisitor::visit(UserInHomeCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: UserInHomeCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runUserInHome();
}

void CommandHandlerVisitor::visit(SnapshotCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: SnapshotCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    periphManager_.runSnapshot();
}

void CommandHandlerVisitor::visit(GuardStatusCommand& command)
{
	if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: GuardStatusCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }
	
	periphManager_.runGuardStatus();

}

void CommandHandlerVisitor::visit(MotorStatusCommand& command)
{
	if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: MotorStatusCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

	periphManager_.runMotorStatus();
}

void CommandHandlerVisitor::visit(EndConnectionCommand &command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("ClientThreadTCP :: ClientdID -") + to_string(currentClient_->getID()) + string("- end connection.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    currentClient_->stopSendAndListen();
}

void CommandHandlerVisitor::visit(StartStreamCommand& command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: StartStreamCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    startStream();
}

void CommandHandlerVisitor::visit(StopStreamCommand& command)
{
    if(logger_.isInformationEnable())
    {
        const string message = string("CommandHandlerVisitor :: StopStreamCommand was received.");
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    stopStream();
}

void CommandHandlerVisitor::initializeCurrentClient(ClientThreadTCP *client)
{
    currentClient_ = client;
}

void CommandHandlerVisitor::startStream()
{
    int status;
    int out[2];

    isKilled = false;
    char *firstArg1 = const_cast<char*>(string(STREAM_SCRIPT_PATH + STREAM_SCRIPT_NAME).c_str());
    char *firstArgs[] = {firstArg1, NULL};

    posix_spawn_file_actions_init(&action_);
    pipe(out);
    posix_spawn_file_actions_adddup2(&action_, out[1], STDOUT_FILENO);
    posix_spawn_file_actions_addclose(&action_, out[0]);

    status = posix_spawn(&pid_, firstArgs[0], &action_, NULL, firstArgs, environ);

    if(status == 0)
    {
        if(logger_.isInformationEnable())
        {
            const string message = string("CommandHandlerVisitor :: Process was initialized, process ID: ")
                                   + to_string(pid_);
            logger_.writeLog(LogType::INFORMATION_LOG, message);
        }
    }
    else
    {
        if(logger_.isErrorEnable())
        {
            const string message = string("CommandHandlerVisitor :: Process was not initialized correctly, process ID: ")
                                   + to_string(pid_);
            logger_.writeLog(LogType::INFORMATION_LOG, message);
        }
    }
}

void CommandHandlerVisitor::stopStream()
{
    if(pid_ > 0)
    {
        kill(pid_, SIGKILL);
	system("../../camera_scripts/kill_stream.sh");
	
        if(logger_.isInformationEnable())
        {
            const string message = string("CommandHandlerVisitor :: Process was killed, process ID: ") + to_string(pid_);
            logger_.writeLog(LogType::INFORMATION_LOG, message);
        }
    }
    else
    {
        if(logger_.isWarningEnable())
        {
            const string message = string("CommandHandlerVisitor :: Process tried to be killed second time, process ID: ") + to_string(pid_);
            logger_.writeLog(LogType::ERROR_LOG, message);
        }
    }


    waitOnProcess();
}

void CommandHandlerVisitor::waitOnProcess()
{
    int status;
	
    if(!isKilled)
    {
    if (waitpid(pid_, &status, 0) < 0)
    {
        if(logger_.isErrorEnable())
        {
            const string message = string("CommandHandlerVisitor :: Process ID: ") + to_string(pid_) +
                                   string(". Error - ") +  strerror(errno);
            logger_.writeLog(LogType::ERROR_LOG, message);
        }
    }
    else
    {
        if (WIFEXITED(status))
        {
            if(logger_.isInformationEnable())
            {
                const string message = string("CommandHandlerVisitor :: Process ID: ") + to_string(pid_) +
                                       string(". Child exit status - ") + to_string(WEXITSTATUS(status));
                logger_.writeLog(LogType::INFORMATION_LOG, message);
            }
        }
        else
        {
            if(logger_.isInformationEnable())
            {
                const string message = string("CommandHandlerVisitor :: Process ID: ") + to_string(pid_) +
                                       string(". Child process had been finished before waitpid was launched.");
                logger_.writeLog(LogType::INFORMATION_LOG, message);
            }
        }
    }

    isKilled = true;
    posix_spawn_file_actions_destroy(&action_);
    }
}
