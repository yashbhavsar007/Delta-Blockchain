#pragma once

#include <delta/protocol/delta_required_actions.hpp>

#include <delta/protocol/operation_util.hpp>

namespace delta { namespace protocol {

   /** NOTE: do not change the order of any actions or it will trigger a hardfork.
    */
   typedef fc::static_variant<
            required_action
         > required_automated_action;

} } // delta::protocol

DELTA_DECLARE_OPERATION_TYPE( delta::protocol::required_automated_action );
FC_REFLECT_TYPENAME( delta::protocol::required_automated_action );
