#pragma once

#include <string>

#include <peng/version.hpp>
#include <peng/config.hpp>




namespace maze
{
    namespace peng
    {


        class PENG_EXPORT factory_base
        {
        public:
            virtual ~factory_base() = default;

            virtual const std::string & interface_name() const;
            virtual const std::string & plugin_name() const;
            virtual const version & current_version() const = 0;
            virtual const version & minimum_version() const = 0;

            bool is_compatible(const factory_base *factory) const;
        };


    }
}