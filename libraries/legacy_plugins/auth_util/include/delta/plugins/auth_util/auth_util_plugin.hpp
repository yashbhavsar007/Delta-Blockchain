
#pragma once

#include <delta/app/plugin.hpp>

namespace delta { namespace plugin { namespace auth_util {

using delta::app::application;

class auth_util_plugin : public delta::app::plugin
{
   public:
      auth_util_plugin( application* app ) ;
      virtual ~auth_util_plugin();

      virtual std::string plugin_name()const override;
      virtual void plugin_initialize( const boost::program_options::variables_map& options ) override;
      virtual void plugin_startup() override;
      virtual void plugin_shutdown() override;
};

} } }
