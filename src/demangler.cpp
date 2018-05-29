#include <peng/demangler.hpp>

#include <peng/config.hpp>

#if defined(PENG_GCC) || defined(PENG_CLANG)
#include <cstdlib>
#include <memory>

#include <cxxabi.h>
#endif




namespace maze
{
    namespace peng
    {


        std::string demangler::apply(const char *name)
        {
        #if defined(PENG_GCC) || defined(PENG_CLANG)
            int status = -4;

            std::unique_ptr<char, void(*)(void*)> res {
                abi::__cxa_demangle(name, NULL, NULL, &status),
                std::free
            };

            return (status==0) ? res.get() : name;
        #else
            return name;
        #endif
        }


    }
}