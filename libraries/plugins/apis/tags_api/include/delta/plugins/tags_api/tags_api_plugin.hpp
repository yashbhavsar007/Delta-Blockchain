#pragma once
#include <delta/plugins/tags/tags_plugin.hpp>
#include <delta/plugins/json_rpc/json_rpc_plugin.hpp>

#include <appbase/application.hpp>

#define DELTA_TAGS_API_PLUGIN_NAME "tags_api"


namespace delta { namespace plugins { namespace tags {

using namespace appbase;

class tags_api_plugin : public appbase::plugin< tags_api_plugin >
{
public:
   APPBASE_PLUGIN_REQUIRES(
      (delta::plugins::tags::tags_plugin)
      (delta::plugins::json_rpc::json_rpc_plugin)
   )

   tags_api_plugin();
   virtual ~tags_api_plugin();

   static const std::string& name() { static std::string name = DELTA_TAGS_API_PLUGIN_NAME; return name; }

   virtual void set_program_options( options_description& cli, options_description& cfg ) override;

   virtual void plugin_initialize( const variables_map& options ) override;
   virtual void plugin_startup() override;
   virtual void plugin_shutdown() override;

   std::shared_ptr< class tags_api > api;
};

} } } // delta::plugins::tags
