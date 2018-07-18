#include <peng/plugin_manager.hpp>

#include <cstdint>
#include <stdexcept>

#include <peng/directory.hpp>
#include <peng/plugin.hpp>




namespace maze
{
    namespace peng
    {


        plugin_manager::~plugin_manager()
        {
            for(auto it = this->plugin_store.begin(); it != this->plugin_store.end(); ++it)
            {
                this->disconnect(it->first);
            }
        }


        void plugin_manager::load(const std::string &plugin_name, const std::string &folder, bool recursive)
        {
            if(plugin_name.empty())
            {
                std::vector<std::string> files = directory::list_files(folder, PENG_PLUGIN_EXTENSION, recursive);
                for(auto it = files.begin(); it != files.end(); ++it)
                {
                    this->plugin_store[this->get_plugin_name(*it)] = plugin(*it);
                }
            }
            else
            {
                std::string path;
                if(folder[folder.size() - 1] == '/' || folder[folder.size() - 1] == '\\')
                {
                    path = folder + plugin_name;
                }
                else
                {
                    path = folder + '/' + plugin_name;
                }

                this->plugin_store[plugin_name] = plugin(path);
            }
        }


        void plugin_manager::unload(const std::string &plugin_name)
        {

        }


        void plugin_manager::connect(const std::string &plugin_name)
        {
            typedef bool connector(plugin_manager *);
            connector conn = reinterpret_cast<connector>(this->plugin_store[plugin_name].symbol("connect"));
            if(!conn)
            {
                throw std::runtime_error("Failed to load plugin connector: " + plugin_name);
            }

            if(!conn(this))
            {
                throw std::runtime_error("Connector function failed on plugin: " + plugin_name);
            }
        }


        void plugin_manager::disconnect(const std::string &plugin_name)
        {

        }


        std::string plugin_manager::get_plugin_name(const std::string &path)
        {
            std::uint64_t last_dash = path.find_last_of("/\\");
            std::uint64_t last_dot = path.find_last_of(".");
            if(last_dash == std::string::npos)
            {
                last_dash = 0;
            }
            else
            {
                ++last_dash;
            }

            if(last_dot < last_dash || last_dot == std::string::npos)
            {
                last_dot = path.length();
            }

            return path.substr(last_dash, last_dot - last_dash);
        }


    }
}