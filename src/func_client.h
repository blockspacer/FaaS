#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <grpcpp/grpcpp.h>
#include "func.grpc.pb.h"
#include "warble.grpc.pb.h"
#include "enums.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using func::EventReply;
using func::EventRequest;
using func::FuncService;
using func::HookReply;
using func::HookRequest;
using func::UnhookReply;
using func::UnhookRequest;

using warble::FollowReply;
using warble::FollowRequest;
using warble::ProfileReply;
using warble::ProfileRequest;
using warble::ReadReply;
using warble::ReadRequest;
using warble::RegisteruserReply;
using warble::RegisteruserRequest;
using warble::Warble;
using warble::WarbleReply;
using warble::WarbleRequest;

namespace dylanwarble
{

// // enum for event_id
// enum FunctionID
// {
//   kRegisterUserID = 0,
//   kWarbleID = 1,
//   kFollowUserID = 2,
//   kReadID = 3,
//   kProfileID = 4,
// };

// // enum for event
// enum FunctionName
// {
//   kRegisterUser,
//   kWarble,
//   kFollowUser,
//   kRead,
//   kProfile,
// };

// Internal datastructure to package data from clclient to func_client
struct Payload
{
  int event_type;
  std::string event_function;

  std::string username;
  std::string text;
  std::string parent_id;
  std::string id;
  std::string to_follow;
};

class FuncClient
{
public:
  // Creates a new client
  FuncClient(std::shared_ptr<Channel> channel)
      : stub_(FuncService::NewStub(channel)) {}

  // Hooks an event with int event_type
  void Hook(const int event_type, const std::string &event_function);

  // Unooks an event with int event_type
  void Unhook(const int event_type);

  // Requests an event with parameters stored in Payload by clclient
  void Event(const int event_type, const Payload &p);

private:
  std::unique_ptr<FuncService::Stub> stub_;
};

} // namespace dylanwarble