#pragma once

#include <delta/account_statistics/account_statistics_plugin.hpp>

#include <fc/api.hpp>

namespace delta { namespace app {
   struct api_context;
} }

namespace delta { namespace account_statistics {

namespace detail
{
   class account_statistics_api_impl;
}

class account_statistics_api
{
   public:
      account_statistics_api( const delta::app::api_context& ctx );

      void on_api_startup();

   private:
      std::shared_ptr< detail::account_statistics_api_impl > _my;
};

} } // delta::account_statistics

FC_API( delta::account_statistics::account_statistics_api, )