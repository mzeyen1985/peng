#pragma once

#include <peng/config.hpp>




namespace maze
{
    namespace peng
    {


        class PENG_EXPORT plugin_manager
        {
        public:
            plugin_manager() = delete;
            plugin_manager(const std::string &plugin_dir);
            ~plugin_manager();

        private:
            std::string plugin_dir;
        };


    }
}