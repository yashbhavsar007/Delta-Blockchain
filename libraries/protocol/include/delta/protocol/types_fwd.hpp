#pragma once
#include <cstdint>
#include <fc/uint128.hpp>

namespace fc {
class variant;
} // fc

namespace delta { namespace protocol {
template< typename Storage = fc::uint128 >
class fixed_string_impl;

class asset_symbol_type;
class legacy_delta_asset_symbol_type;
struct legacy_delta_asset;
} } // delta::protocol

namespace fc { namespace raw {

template< typename Stream, typename Storage >
inline void pack( Stream& s, const delta::protocol::fixed_string_impl< Storage >& u );
template< typename Stream, typename Storage >
inline void unpack( Stream& s, delta::protocol::fixed_string_impl< Storage >& u, uint32_t depth = 0 );

template< typename Stream >
inline void pack( Stream& s, const delta::protocol::asset_symbol_type& sym );
template< typename Stream >
inline void unpack( Stream& s, delta::protocol::asset_symbol_type& sym, uint32_t depth = 0 );

template< typename Stream >
inline void pack( Stream& s, const delta::protocol::legacy_delta_asset_symbol_type& sym );
template< typename Stream >
inline void unpack( Stream& s, delta::protocol::legacy_delta_asset_symbol_type& sym, uint32_t depth = 0 );

} // raw

template< typename Storage >
inline void to_variant( const delta::protocol::fixed_string_impl< Storage >& s, fc::variant& v );
template< typename Storage >
inline void from_variant( const variant& v, delta::protocol::fixed_string_impl< Storage >& s );

inline void to_variant( const delta::protocol::asset_symbol_type& sym, fc::variant& v );

inline void from_variant( const fc::variant& v, delta::protocol::legacy_delta_asset& leg );
inline void to_variant( const delta::protocol::legacy_delta_asset& leg, fc::variant& v );

} // fc
