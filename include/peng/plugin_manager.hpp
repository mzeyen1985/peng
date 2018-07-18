#pragma once

#include <unordered_map>
#include <string>

#include <peng/config.hpp>
#include <peng/factory_base.hpp>




namespace maze
{
    namespace peng
    {


        class plugin;


        class PENG_EXPORT plugin_manager
        {
        public:
            plugin_manager() = default;
            ~plugin_manager();

            void load(const std::string &folder, const std::string &plugin_name, bool recursive=true);
            void unload(const std::string &plugin_name);
            void connect(const std::string &plugin_name);
            void disconnect(const std::string &plugin_name);

        private:
            template<typename T> using store = std::unordered_map<std::string, T>;
            store<plugin> plugin_store;
            store<store<store<factory_base *>>> factory_store;

            std::string get_plugin_name(const std::string &path);
        };


    }
}