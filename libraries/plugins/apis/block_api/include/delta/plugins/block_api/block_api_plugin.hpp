#pragma once
#include <delta/plugins/chain/chain_plugin.hpp>
#include <delta/plugins/json_rpc/json_rpc_plugin.hpp>

#include <appbase/application.hpp>

namespace delta { namespace plugins { namespace block_api {

using namespace appbase;

#define DELTA_BLOCK_API_PLUGIN_NAME "block_api"

class block_api_plugin : public plugin< block_api_plugin >
{
   public:
      block_api_plugin();
      virtual ~block_api_plugin();

      APPBASE_PLUGIN_REQUIRES(
         (delta::plugins::json_rpc::json_rpc_plugin)
         (delta::plugins::chain::chain_plugin)
      )

      static const std::string& name() { static std::string name = DELTA_BLOCK_API_PLUGIN_NAME; return name; }

      virtual void set_program_options(
         options_description& cli,
         options_description& cfg ) override;
      void plugin_initialize( const variables_map& options ) override;
      void plugin_startup() override;
      void plugin_shutdown() override;

      std::shared_ptr< class block_api > api;
};

} } } // delta::plugins::block_api
