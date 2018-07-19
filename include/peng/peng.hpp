#pragma once

#include <peng/config.hpp>




namespace maze
{
    namespace peng
    {


        class plugin_manager;


        class PENG_EXPORT peng
        {
        public:
            peng() = default;
            ~peng();

            void load(const std::string &plugin_name, const std::string &folder, bool recursive=true);
            void unload(const std::string &plugin_name);
            void connect(const std::string &plugin_name);
            void disconnect(const std::string &plugin_name);
            void add(const factory_base &factory);

        private:
            plugin_manager manager;
        };


    }
}