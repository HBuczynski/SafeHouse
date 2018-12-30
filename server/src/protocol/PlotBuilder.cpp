#include "PlotBuilder.h"
#include "PlotCommand.h"

using namespace std;
using namespace communication;

PlotBuilder::PlotBuilder()
{}

PlotBuilder::~PlotBuilder()
{}

unique_ptr<Command> PlotBuilder::create(const vector<uint8_t> &commandInBytes)
{
    const auto parameterType = static_cast<ParameterType>(commandInBytes[initialDataPosition]);
    const auto sensorTagType = static_cast<SensorTagType>(commandInBytes[initialDataPosition+1]);

    auto command = make_unique<PlotCommand>(parameterType, sensorTagType);

    return move(command);
}
