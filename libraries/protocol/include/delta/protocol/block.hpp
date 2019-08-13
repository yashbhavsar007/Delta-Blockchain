#pragma once
#include <delta/protocol/block_header.hpp>
#include <delta/protocol/transaction.hpp>

namespace delta { namespace protocol {

   struct signed_block : public signed_block_header
   {
      checksum_type calculate_merkle_root()const;
      vector<signed_transaction> transactions;
   };

} } // delta::protocol

FC_REFLECT_DERIVED( delta::protocol::signed_block, (delta::protocol::signed_block_header), (transactions) )
