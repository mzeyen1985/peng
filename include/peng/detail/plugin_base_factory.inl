#pragma once




namespace maze
{
    namespace peng
    {


        template<typename T, version cur_version, version min_version> inline
        const std::string & plugin_base_factory<T, cur_version, min_version>::interface_name() const
        {
            return this->interface_name_m;
        }
        
        
        template<typename T, version cur_version, version min_version> inline
        const version & plugin_base_factory<T, cur_version, min_version>::current_version() const
        {
            return cur_version;
        }


        template<typename T, version cur_version, version min_version> inline
        const version & plugin_base_factory<T, cur_version, min_version>::minimum_version() const
        {
            return min_version;
        }


    }
}