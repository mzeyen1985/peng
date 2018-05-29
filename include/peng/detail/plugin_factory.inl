#pragma once




namespace peng
{


    template<typename S, typename T> inline
    T * plugin_factory<S, T>::create(const config_t &config)
    {
        return new S(config);
    }


    template<typename S, typename T> inline
    const std::string & plugin_factory<S, T>::plugin_name() const
    {
        return this->plugin_name_m;
    }


}