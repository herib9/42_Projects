#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string mySed(std::string filename, const std::string &s1, const std::string &s2)
{
    if(s1.empty())
        return filename;

    std::string result = "";
    size_t      pos = 0;
    size_t      last_pos = 0;

    while((pos = filename.find(s1, last_pos)) != std::string::npos)
    {
        result.append(filename, last_pos, pos - last_pos);
        result = result + s2;
        last_pos = pos + s1.length();
    }
    result = result + filename.substr(last_pos);
    return result;
}

int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cerr << "Error!\n\nUse:\n./S&R <filename> <s1> <s2>" << std::endl;
        return -1;
    }
    std::string file = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream ifs(file.c_str());
    if(!ifs.is_open())
    {
        std::cerr << "Error!\n\nCannot open the file: " << file << std::endl;
        return -1;
    }
    std::stringstream   ss;
    ss << ifs.rdbuf();
    std::string file_content = ss.str();
    ifs.close();

    std::string finalResult = mySed(file_content, s1, s2);
    std::ofstream ofs((file + ".s&r").c_str());
    if(!ofs.is_open())
    {
        std::cerr << "Error!\n\nOutput file cannot create" << std::endl;
        return -1;
    }
    ofs << finalResult;
    ofs.close();
    return 0;
}

/**
// esto es pa probar
 * ! esto es una prueba
 * * esto tambien
 * ? esto tambien
 * TODO estl tambien
 * @param Myparam para explicar la funcion
 * /

 */