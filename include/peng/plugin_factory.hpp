#pragma once




namespace maze
{
    namespace peng
    {


        template<typename S, typename T>
        class plugin_factory : public plugin_base_factory<T>
        {
        public:
            T * create(const config_t &config);
        };


    }
}


#include <peng/detail/plugin_factory.inl>