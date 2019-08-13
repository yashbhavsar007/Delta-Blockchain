#pragma once

#include <delta/protocol/asset.hpp>

namespace delta { namespace chain { namespace util {

using delta::protocol::asset;
using delta::protocol::price;

inline asset to_dbd( const price& p, const asset& delta )
{
   FC_ASSERT( delta.symbol == DELTA_SYMBOL );
   if( p.is_null() )
      return asset( 0, DBD_SYMBOL );
   return delta * p;
}

inline asset to_delta( const price& p, const asset& dbd )
{
   FC_ASSERT( dbd.symbol == DBD_SYMBOL );
   if( p.is_null() )
      return asset( 0, DELTA_SYMBOL );
   return dbd * p;
}

} } }
