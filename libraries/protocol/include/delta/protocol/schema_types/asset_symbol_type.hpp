
#pragma once

#include <delta/schema/abstract_schema.hpp>
#include <delta/schema/schema_impl.hpp>

#include <delta/protocol/asset_symbol.hpp>

namespace delta { namespace schema { namespace detail {

//////////////////////////////////////////////
// asset_symbol_type                        //
//////////////////////////////////////////////

struct schema_asset_symbol_type_impl
   : public abstract_schema
{
   DELTA_SCHEMA_CLASS_BODY( schema_asset_symbol_type_impl )
};

}

template<>
struct schema_reflect< delta::protocol::asset_symbol_type >
{
   typedef detail::schema_asset_symbol_type_impl           schema_impl_type;
};

} }
