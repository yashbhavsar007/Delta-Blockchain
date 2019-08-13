#pragma once

#include <delta/protocol/block.hpp>

namespace delta { namespace chain {

struct transaction_notification
{
   transaction_notification( const delta::protocol::signed_transaction& tx ) : transaction(tx)
   {
      transaction_id = tx.id();
   }

   delta::protocol::transaction_id_type          transaction_id;
   const delta::protocol::signed_transaction&    transaction;
};

} }
