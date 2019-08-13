#pragma once

#include <delta/chain/evaluator.hpp>

#include <delta/private_message/private_message_operations.hpp>
#include <delta/private_message/private_message_plugin.hpp>

namespace delta { namespace private_message {

DELTA_DEFINE_PLUGIN_EVALUATOR( private_message_plugin, delta::private_message::private_message_plugin_operation, private_message )

} }
