#pragma once

#include <typeinfo>

#include <peng/factory_base.hpp>
#include <peng/config.hpp>
#include <peng/demangler.hpp>




namespace maze
{
    namespace peng
    {


        template<typename T, version cur_version, version min_version>
        class PENG_EXPORT plugin_base_factory : public factory_base
        {
        public:
            using plugin_base = T;

            virtual ~plugin_base_factory() = default;

            virtual T * create(const config_t &config) = 0;

            const std::string & interface_name() const override;
            const version & current_version() const override;
            const version & minimum_version() const override;

        protected:
            std::string interface_name_m = demangler::apply(typeid(T).name());
        };


    }
}


#include <peng/detail/plugin_base_factory.inl>