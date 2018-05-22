#include "SnapshotBuilder.h"
#include "SnapshotCommand.h"

using namespace std;
using namespace communication;

SnapshotBuilder::SnapshotBuilder()
{}

SnapshotBuilder::~SnapshotBuilder()
{}

unique_ptr<Command> SnapshotBuilder::create(const vector<uint8_t> &commandInBytes)
{
    auto command = make_unique<SnapshotCommand>();

    return move(command);
}
