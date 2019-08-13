#pragma once

#include <delta/protocol/block.hpp>

namespace delta { namespace chain {

struct block_notification
{
   block_notification( const delta::protocol::signed_block& b ) : block(b)
   {
      block_id = b.id();
      block_num = block_header::num_from_id( block_id );
   }

   delta::protocol::block_id_type          block_id;
   uint32_t                                block_num = 0;
   const delta::protocol::signed_block&    block;
};

struct transaction_notification
{
   transaction_notification( const delta::protocol::signed_transaction& tx ) : transaction(tx)
   {
      transaction_id = tx.id();
   }

   delta::protocol::transaction_id_type          transaction_id;
   const delta::protocol::signed_transaction&    transaction;
};

struct operation_notification
{
   operation_notification( const operation& o ) : op(o) {}

   transaction_id_type trx_id;
   uint32_t            block = 0;
   uint32_t            trx_in_block = 0;
   uint32_t            op_in_trx = 0;
   uint32_t            virtual_op = 0;
   const operation&    op;
};

struct required_action_notification
{
   required_action_notification( const required_automated_action& a ) : action(a) {}

   const required_automated_action& action;
};

struct optional_action_notification
{
   optional_action_notification( const optional_automated_action& a ) : action(a) {}

   const optional_automated_action& action;
};

} }
