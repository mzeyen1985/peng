#pragma once

#include <string>

#include <peng/config.hpp>




namespace maze
{
    namespace peng
    {


        class PENG_EXPORT demangler
        {
        public:
            demangler() = delete;

            static std::string apply(const char *name);
        };


    }
}