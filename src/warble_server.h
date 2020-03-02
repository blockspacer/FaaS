#include <grpcpp/grpcpp.h>
#include "warble.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReaderWriter;
using grpc::Status;

using warble::FollowReply;
using warble::FollowRequest;
using warble::ProfileReply;
using warble::ProfileRequest;
using warble::ReadReply;
using warble::ReadRequest;
using warble::RegisteruserReply;
using warble::RegisteruserRequest;
using warble::WarbleReply;
using warble::WarbleRequest;

class Warble {
  // Registers the given username
  void registeruser(std::string username);

  // Posts a new warble by specific user and returns WarbleReply with id of new
  // warble
  WarbleReply *warble(std::string username, std::string text,
                      int reply_to_warble_id);

  // Lets specified user follow another user
  FollowReply *follow(std::string username, std::string user_to_follow);

  // Reads a warble thread from the given id
  ReadReply *read(int id);

  // Returns a warble profile
  ProfileReply *profile(std::string username);
};