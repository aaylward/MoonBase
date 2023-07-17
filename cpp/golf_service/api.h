#ifndef CPP_GOLF_SERVICE_API_H
#define CPP_GOLF_SERVICE_API_H

#include <functional>
#include <string>
#include <variant>

#include "absl/status/statusor.h"
#include "cpp/cards/golf/golf.h"

namespace golf_service {

typedef struct RegisterUserRequest {
  std::string username;
} RegisterUserRequest;

typedef struct NewGameRequest {
  std::string username;
  int players;
} NewGameRequest;

typedef struct JoinGameRequest {
  std::string username;
  std::string gameId;
} JoinGameRequest;

typedef struct PeekRequest {
  std::string username;
} PeekRequest;

typedef struct DiscardDrawRequest {
  std::string username;
} DiscardDrawRequest;

typedef struct SwapForDrawRequest {
  std::string username;
  golf::Position position;
} SwapForDrawRequest;

typedef struct SwapForDiscardRequest {
  std::string username;
  golf::Position position;
} SwapForDiscardRequest;

typedef struct KnockRequest {
  std::string username;
} KnockRequest;

typedef std::variant<RegisterUserRequest, NewGameRequest, JoinGameRequest, PeekRequest,
                     DiscardDrawRequest, SwapForDrawRequest, SwapForDiscardRequest, KnockRequest>
    GolfServiceRequest;

typedef std::function<void(const GolfServiceRequest&, struct mg_connection*)> handler;
typedef std::function<absl::StatusOr<GolfServiceRequest>(std::vector<std::string>)> argReader;

typedef absl::StatusOr<GolfServiceRequest> StatusOrRequest;

StatusOrRequest readRegisterUserRequest(const std::vector<std::string>& args);
StatusOrRequest readNewGameRequest(const std::vector<std::string>& args);
StatusOrRequest readJoinGameRequest(const std::vector<std::string>& args);
StatusOrRequest readPeekRequest(const std::vector<std::string>& args);
StatusOrRequest readDiscardDrawRequest(const std::vector<std::string>& args);
StatusOrRequest readSwapForDrawRequest(const std::vector<std::string>& args);
StatusOrRequest readSwapForDiscardRequest(const std::vector<std::string>& args);
StatusOrRequest readKnockRequest(const std::vector<std::string>& args);

}  // namespace golf_service

#endif
