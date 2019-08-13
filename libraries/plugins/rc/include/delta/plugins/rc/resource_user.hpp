#pragma once

#include <delta/protocol/types.hpp>

#include <fc/reflect/reflect.hpp>

namespace delta { namespace protocol {
struct signed_transaction;
} } // delta::protocol

namespace delta { namespace plugins { namespace rc {

using delta::protocol::account_name_type;
using delta::protocol::signed_transaction;

account_name_type get_resource_user( const signed_transaction& tx );

} } } // delta::plugins::rc
