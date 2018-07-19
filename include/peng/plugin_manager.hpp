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


        class plugin_manager
        {
        public:
            plugin_manager() = default;
            ~plugin_manager();

            void add_plugin(const plugin &plug);
            void add_factory(const factory_base &factory);
            void remove_plugin(const std::string &plugin_name);

        private:
            template<typename T> using store = std::unordered_map<std::string, T>;
            store<plugin> plugin_store;
            store<store<store<factory_base *>>> factory_store;

            std::string get_plugin_name(const std::string &path);
        };


    }
}