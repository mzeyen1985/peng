#pragma once

#include <typeinfo>
#include <string>

#include <peng/config.hpp>
#include <peng/demangler.hpp>




namespace maze
{
    namespace peng
    {


        template<typename S, typename T>
        class PENG_EXPORT plugin_factory : public T
        {
        public:
            T::plugin_base * create(const config_t &config);

            const std::string & plugin_name() const override;

        protected:
            std::string plugin_name_m = demangler::apply(typeid(S).name());
        };


    }
}


#include <peng/detail/plugin_factory.inl>