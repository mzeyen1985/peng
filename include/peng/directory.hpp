#pragma once

#include <string>
#include <vector>

#include <peng/config.hpp>




namespace maze
{
    namespace peng
    {


        class PENG_NO_EXPORT directory
        {
        public:
            directory() = delete;

            static std::vector<std::string> list_files(const std::string &folder, const std::string &extension="", bool recursive=false);
        };


    }
}