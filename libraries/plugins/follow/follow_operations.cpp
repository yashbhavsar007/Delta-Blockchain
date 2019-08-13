#include <delta/plugins/follow/follow_operations.hpp>

#include <delta/protocol/operation_util_impl.hpp>

namespace delta { namespace plugins{ namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } } //delta::plugins::follow

DELTA_DEFINE_OPERATION_TYPE( delta::plugins::follow::follow_plugin_operation )
