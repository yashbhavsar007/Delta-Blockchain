#pragma once

#include <delta/protocol/types.hpp>

#include <fc/int_array.hpp>
#include <fc/reflect/reflect.hpp>
#include <vector>

#define DELTA_NUM_RESOURCE_TYPES     5

namespace delta { namespace protocol {
struct signed_transaction;
} } // delta::protocol

namespace delta { namespace plugins { namespace rc {

enum rc_resource_types
{
   resource_history_bytes,
   resource_new_accounts,
   resource_market_bytes,
   resource_state_bytes,
   resource_execution_time
};

typedef fc::int_array< int64_t, DELTA_NUM_RESOURCE_TYPES > resource_count_type;

struct count_resources_result
{
   resource_count_type                            resource_count;
};

void count_resources(
   const delta::protocol::signed_transaction& tx,
   count_resources_result& result );

} } } // delta::plugins::rc

FC_REFLECT_ENUM( delta::plugins::rc::rc_resource_types,
    (resource_history_bytes)
    (resource_new_accounts)
    (resource_market_bytes)
    (resource_state_bytes)
    (resource_execution_time)
   )

FC_REFLECT( delta::plugins::rc::count_resources_result,
   (resource_count)
)

FC_REFLECT_TYPENAME( delta::plugins::rc::resource_count_type )
