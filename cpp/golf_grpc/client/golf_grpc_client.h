#ifndef CPP_GOLF_GRPC_CLIENT_GOLF_GRPC_CLIENT_H
#define CPP_GOLF_GRPC_CLIENT_GOLF_GRPC_CLIENT_H

#include <memory>
#include <string>

#include "absl/status/status.h"
#include "protos/golf_grpc/golf.grpc.pb.h"

namespace golf_grpc {

class GolfClient {
 public:
  explicit GolfClient(std::shared_ptr<Golf::StubInterface> stub) : stub_(std::move(stub)) {}

  absl::Status RegisterUser(const std::string& user_id);

 private:
  std::shared_ptr<Golf::StubInterface> stub_;
};

}  // namespace golf_grpc

#endif  // CPP_GOLF_GRPC_CLIENT_GOLF_GRPC_CLIENT_H