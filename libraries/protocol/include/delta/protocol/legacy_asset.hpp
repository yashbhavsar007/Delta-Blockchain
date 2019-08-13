#pragma once

#include <delta/protocol/asset.hpp>

#define DELTA_SYMBOL_LEGACY_SER_1   (uint64_t(1) | (DELTA_SYMBOL_U64 << 8))
#define DELTA_SYMBOL_LEGACY_SER_2   (uint64_t(2) | (DELTA_SYMBOL_U64 << 8))
#define DELTA_SYMBOL_LEGACY_SER_3   (uint64_t(5) | (DELTA_SYMBOL_U64 << 8))
#define DELTA_SYMBOL_LEGACY_SER_4   (uint64_t(3) | (uint64_t('0') << 8) | (uint64_t('.') << 16) | (uint64_t('0') << 24) | (uint64_t('0') << 32) | (uint64_t('1') << 40))
#define DELTA_SYMBOL_LEGACY_SER_5   (uint64_t(3) | (uint64_t('6') << 8) | (uint64_t('.') << 16) | (uint64_t('0') << 24) | (uint64_t('0') << 32) | (uint64_t('0') << 40))

namespace delta { namespace protocol {

class legacy_delta_asset_symbol_type
{
   public:
      legacy_delta_asset_symbol_type() {}

      bool is_canon()const
      {   return ( ser == DELTA_SYMBOL_SER );    }

      uint64_t ser = DELTA_SYMBOL_SER;
};

struct legacy_delta_asset
{
   public:
      legacy_delta_asset() {}

      template< bool force_canon >
      asset to_asset()const
      {
         if( force_canon )
         {
            FC_ASSERT( symbol.is_canon(), "Must use canonical DELTA symbol serialization" );
         }
         return asset( amount, DELTA_SYMBOL );
      }

      static legacy_delta_asset from_amount( share_type amount )
      {
         legacy_delta_asset leg;
         leg.amount = amount;
         return leg;
      }

      static legacy_delta_asset from_asset( const asset& a )
      {
         FC_ASSERT( a.symbol == DELTA_SYMBOL );
         return from_amount( a.amount );
      }

      share_type                       amount;
      legacy_delta_asset_symbol_type   symbol;
};

} }

namespace fc { namespace raw {

template< typename Stream >
inline void pack( Stream& s, const delta::protocol::legacy_delta_asset_symbol_type& sym )
{
   switch( sym.ser )
   {
      case DELTA_SYMBOL_LEGACY_SER_1:
      case DELTA_SYMBOL_LEGACY_SER_2:
      case DELTA_SYMBOL_LEGACY_SER_3:
      case DELTA_SYMBOL_LEGACY_SER_4:
      case DELTA_SYMBOL_LEGACY_SER_5:
         wlog( "pack legacy serialization ${s}", ("s", sym.ser) );
      case DELTA_SYMBOL_SER:
         pack( s, sym.ser );
         break;
      default:
         FC_ASSERT( false, "Cannot serialize legacy symbol ${s}", ("s", sym.ser) );
   }
}

template< typename Stream >
inline void unpack( Stream& s, delta::protocol::legacy_delta_asset_symbol_type& sym, uint32_t depth )
{
   //  994240:        "account_creation_fee": "0.1 DELTA"
   // 1021529:        "account_creation_fee": "10.0 DELTA"
   // 3143833:        "account_creation_fee": "3.00000 DELTA"
   // 3208405:        "account_creation_fee": "2.00000 DELTA"
   // 3695672:        "account_creation_fee": "3.00 DELTA"
   // 4338089:        "account_creation_fee": "0.001 0.001"
   // 4626205:        "account_creation_fee": "6.000 6.000"
   // 4632595:        "account_creation_fee": "6.000 6.000"
   depth++;
   uint64_t ser = 0;

   fc::raw::unpack( s, ser, depth );
   switch( ser )
   {
      case DELTA_SYMBOL_LEGACY_SER_1:
      case DELTA_SYMBOL_LEGACY_SER_2:
      case DELTA_SYMBOL_LEGACY_SER_3:
      case DELTA_SYMBOL_LEGACY_SER_4:
      case DELTA_SYMBOL_LEGACY_SER_5:
         wlog( "unpack legacy serialization ${s}", ("s", ser) );
      case DELTA_SYMBOL_SER:
         sym.ser = ser;
         break;
      default:
         FC_ASSERT( false, "Cannot deserialize legacy symbol ${s}", ("s", ser) );
   }
}

} // fc::raw

inline void to_variant( const delta::protocol::legacy_delta_asset& leg, fc::variant& v )
{
   to_variant( leg.to_asset<false>(), v );
}

inline void from_variant( const fc::variant& v, delta::protocol::legacy_delta_asset& leg )
{
   delta::protocol::asset a;
   from_variant( v, a );
   leg = delta::protocol::legacy_delta_asset::from_asset( a );
}

template<>
struct get_typename< delta::protocol::legacy_delta_asset_symbol_type >
{
   static const char* name()
   {
      return "delta::protocol::legacy_delta_asset_symbol_type";
   }
};

} // fc

FC_REFLECT( delta::protocol::legacy_delta_asset,
   (amount)
   (symbol)
   )
