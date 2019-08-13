#pragma once

#include <delta/chain/util/asset.hpp>
#include <delta/chain/delta_objects.hpp>

#include <delta/protocol/asset.hpp>
#include <delta/protocol/config.hpp>
#include <delta/protocol/types.hpp>
#include <delta/protocol/misc_utilities.hpp>

#include <fc/reflect/reflect.hpp>

#include <fc/uint128.hpp>

namespace delta { namespace chain { namespace util {

using delta::protocol::asset;
using delta::protocol::price;
using delta::protocol::share_type;

using fc::uint128_t;

struct comment_reward_context
{
   share_type rshares;
   uint16_t   reward_weight = 0;
   asset      max_dbd;
   uint128_t  total_reward_shares2;
   asset      total_reward_fund_delta;
   price      current_delta_price;
   protocol::curve_id   reward_curve = protocol::quadratic;
   uint128_t  content_constant = DELTA_CONTENT_CONSTANT_HF0;
};

uint64_t get_rshare_reward( const comment_reward_context& ctx );

inline uint128_t get_content_constant_s()
{
   return DELTA_CONTENT_CONSTANT_HF0; // looking good for posters
}

uint128_t evaluate_reward_curve( const uint128_t& rshares, const protocol::curve_id& curve = protocol::quadratic, const uint128_t& content_constant = DELTA_CONTENT_CONSTANT_HF0 );

inline bool is_comment_payout_dust( const price& p, uint64_t delta_payout )
{
   return to_dbd( p, asset( delta_payout, DELTA_SYMBOL ) ) < DELTA_MIN_PAYOUT_DBD;
}

} } } // delta::chain::util

FC_REFLECT( delta::chain::util::comment_reward_context,
   (rshares)
   (reward_weight)
   (max_dbd)
   (total_reward_shares2)
   (total_reward_fund_delta)
   (current_delta_price)
   (reward_curve)
   (content_constant)
   )
