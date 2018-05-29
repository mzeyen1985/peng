#pragma once

#include <string>




namespace maze
{
    namespace peng
    {


        class plugin_loader
        {
        public:
            plugin() = default;
            ~plugin();

            static plugin * load(const std::string &path);
            void * get_symbol(const std::string &symbol);

        private:
            void *handle;
        };


    }
}