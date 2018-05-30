#include <peng/directory.hpp>

#include <stdexcept>
#include <queue>

#include <dirent.h>




namespace maze
{
    namespace peng
    {


        std::vector<std::string> list_files(const std::string &folder, const std::string &extension, bool recursive)
        {
            DIR *dir;
            dirent *ent;
            std::vector<std::string> result;

            // init folder traversal queue with top level folder
            std::queue<std::string> folders;
            folders.push(folder);

            // traverse folders
            while(!folders.empty())
            {
                // load folder from queue
                std::string current_folder = folders.front();
                folders.pop();
                dir = opendir(current_folder.c_str());
                if(dir == nullptr)
                {
                    throw std::runtime_error("Opening directory failed! " + current_folder);
                }

                // scan for files and sub-directories
                while((ent = readdir(dir)) != nullptr)
                {
                    // get the item in current folder and create path
                    std::string name(ent->d_name);
                    std::string path = current_folder + "/" + name;

                    // check if current item is a directory
                    if(ent->d_type == DT_DIR)
                    {
                        // ignore "." and ".." directories
                        if(name.compare(".") == 0 || name.compare("..") == 0)
                        {
                            continue;
                        }

                        // queue folder if recursive traversal is set to true
                        if(recursive)
                        {
                            folders.push(path);
                        }
                    }
                    else
                    {
                        // if no extension is specified return all files
                        if(extension.empty())
                        {
                            result.push_back(path);
                        }
                        else
                        {
                            // get file extension of current file
                            std::string ext = name.substr(name.find_last_of('.') + 1)

                            // add file to results if its extension matches
                            if(ext.compare(extension) == 0)
                            {
                                result.push_back(path);
                            }
                        }
                    }
                }

                // close current folder
                closedir(dir);
            }

            return result;
        }


    }
}