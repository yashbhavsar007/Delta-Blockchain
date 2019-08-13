#pragma once

#include <fc/container/flat.hpp>
#include <delta/protocol/operations.hpp>
#include <delta/protocol/transaction.hpp>

#include <fc/string.hpp>

namespace delta { namespace app {

using namespace fc;

void operation_get_impacted_accounts(
   const delta::protocol::operation& op,
   fc::flat_set<protocol::account_name_type>& result );

void transaction_get_impacted_accounts(
   const delta::protocol::transaction& tx,
   fc::flat_set<protocol::account_name_type>& result
   );

} } // delta::app
