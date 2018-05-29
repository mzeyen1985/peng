#pragma once

#include <string>

#include <peng/config.hpp>

#ifdef PENG_WINDOWS
#include <windows.h>
#else
#include <dlfcn.h>
#endif




namespace maze
{
    namespace peng
    {


        class plugin_loader
        {
        public:
            plugin_loader() = delete;
            plugin_loader(const std::string &path);
            ~plugin_loader();

            // static plugin * load(const std::string &path);
            void * symbol(const std::string &name);

        private:
            void *handle;
        };


    }
}