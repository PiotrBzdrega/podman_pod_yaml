#include <print>
#include <span>
#include <cstdlib>
#include <string>
#include <filesystem>
#include <fstream>

constexpr auto jsonPath = "/config/cfg.json";
constexpr auto keyPath = "/platform/platform_ecdsa_public.pem";


std::string read_file(std::string_view file_path)
{
    if (!std::filesystem::exists(file_path)) 
    {
        std::println("File not found: {}",file_path);
        return {};
    }

    std::ifstream file(file_path.data(), std::ios::binary);
    if (!file) 
    {
        std::println("Failed to open file: {}",file_path);
        return {};
    }

    // Pre-allocate string space
    std::string content(std::filesystem::file_size(file_path), '\0');

    file.read(content.data(),content.size());
    return content;
}

void append(std::string_view file_path, std::string_view to_append)
{
    if (!std::filesystem::exists(file_path)) 
    {
        std::println("File not found: {}",file_path);
        return;
    }

    std::ofstream file(file_path.data(),std::ios_base::app);
    if (!file) 
    {
        std::println("Failed to open file: {}",file_path);
        return;
    }

    file << to_append;
}

int main(int argLen, char** arg)
{
    auto params = std::span<char*>(arg,argLen);

    std::println("Args:");
    for (auto p : params)
    {
        std::println("\t{}",p);
    }

    std::println("Environment Variables");
    if (auto env = std::getenv("CONFIG_KEY"))
    {
        std::println("{}",env);
    }

    std::println("platform key");
    std::println("{}",read_file(keyPath));

    if (auto env = std::getenv("PASSWORD"))
    {
        std::println("{}",env);
    }

    std::println("json File");
    std::println("{}",read_file(jsonPath));

    std::println("append to File");
    append(jsonPath,"\nadamek");

    std::println("read appended");
    std::println("{}",read_file(jsonPath));
}
