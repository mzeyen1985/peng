#pragma once

#include <peng/factory_base.hpp>




namespace maze
{
    namespace peng
    {


        template<typename T, version cur_version, version min_version>
        class plugin_base_factory : public factory_base
        {
        public:
            virtual ~plugin_base_factory() = default;

            virtual T * create(const config_t &config) = 0;

            const version & current_version() const override;
            const version & minimum_version() const override;
        };


    }
}


#include <peng/detail/plugin_base_factory.inl>