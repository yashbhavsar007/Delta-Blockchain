#pragma once
#include <delta/protocol/base.hpp>
#include <delta/protocol/block_header.hpp>
#include <delta/protocol/asset.hpp>
#include <delta/protocol/validation.hpp>
#include <delta/protocol/legacy_asset.hpp>

#include <fc/crypto/equihash.hpp>

namespace delta { namespace protocol {

   struct required_action : public base_operation
   {
      account_name_type account;

      void validate()const;
      void get_required_active_authorities( flat_set<account_name_type>& a )const{ a.insert(account); }
   };

} } // delta::protocol

FC_REFLECT( delta::protocol::required_action, (account) )
