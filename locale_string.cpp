#include "locale_string.h"

#include <locale>
#include <codecvt>

std::size_t string_lenght (const std::string& str) 
{
    return std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}.from_bytes(str).size();
}
