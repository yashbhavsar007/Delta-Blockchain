
#pragma once

#include <delta/schema/abstract_schema.hpp>
#include <delta/schema/schema_impl.hpp>

#include <delta/protocol/types.hpp>

namespace delta { namespace schema { namespace detail {

//////////////////////////////////////////////
// account_name_type                        //
//////////////////////////////////////////////

struct schema_account_name_type_impl
   : public abstract_schema
{
   DELTA_SCHEMA_CLASS_BODY( schema_account_name_type_impl )
};

}

template<>
struct schema_reflect< delta::protocol::account_name_type >
{
   typedef detail::schema_account_name_type_impl           schema_impl_type;
};

} }

namespace fc {

template<>
struct get_typename< delta::protocol::account_name_type >
{
   static const char* name()
   {
      return "delta::protocol::account_name_type";
   }
};

}
