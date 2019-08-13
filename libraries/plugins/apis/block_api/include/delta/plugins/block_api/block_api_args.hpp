#pragma once
#include <delta/plugins/block_api/block_api_objects.hpp>

#include <delta/protocol/types.hpp>
#include <delta/protocol/transaction.hpp>
#include <delta/protocol/block_header.hpp>

#include <delta/plugins/json_rpc/utility.hpp>

namespace delta { namespace plugins { namespace block_api {

/* get_block_header */

struct get_block_header_args
{
   uint32_t block_num;
};

struct get_block_header_return
{
   optional< block_header > header;
};

/* get_block */
struct get_block_args
{
   uint32_t block_num;
};

struct get_block_return
{
   optional< api_signed_block_object > block;
};

} } } // delta::block_api

FC_REFLECT( delta::plugins::block_api::get_block_header_args,
   (block_num) )

FC_REFLECT( delta::plugins::block_api::get_block_header_return,
   (header) )

FC_REFLECT( delta::plugins::block_api::get_block_args,
   (block_num) )

FC_REFLECT( delta::plugins::block_api::get_block_return,
   (block) )

