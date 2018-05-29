#include <peng/plugin_loader.hpp>

#include <stdexcept>




namespace maze
{
    namespace peng
    {


        plugin_loader::plugin_loader(const std::string &path)
        {
            if(path.empty())
            {
                throw std::runtime_error("Failed to load plugin! Path is empty.");
            }

            this->handle = nullptr;

        #ifdef PENG_WINDOWS
            this->handle = LoadLibraryA(path.c_str());
            if(this->handle == nullptr)
            {
                throw std::runtime_error("Failed to load library! " + path);
            }
        #else
            this->handle = dlopen(path.c_str(), RTLD_NOW);
            if(this->handle == nullptr)
            {
                const char *error = dlerror();
                if(error != nullptr)
                {
                    throw std::runtime_error("Failed to load library! OS returned error: " + error);
                }

                throw std::runtime_error("Failed to load library!");
            }
        #endif
        }


        plugin_loader::~plugin_loader()
        {
            if(this->handle != nullptr)
            {
            #ifdef PENG_WINDOWS
                // FreeLibrary(reinterpret_cast<HMODULE>(this->handle));
                FreeLibrary(this->handle);
            #else
                dlclose(this->handle);
            #endif                  
            }
        }


        void * plugin_loader::symbol(const std::string &name)
        {
            if(this->handle == nullptr)
            {
                throw std::runtime_error("Plugin isn't loaded!");
            }

            void *res = nullptr;
        #ifdef PENG_WINDOWS
            // res = GetProcAddress(reinterpret_cast<HMODULE>(this->handle), name.c_str());
            res = GetProcAddress(this->handle, name.c_str());
        #else
            res = dlsym(this->handle, name.c_str());
        #endif

            if(res == nullptr)
            {
                return nullptr;
            }

            return res;
        }


    }
}