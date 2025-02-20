#include <vector>
#include <string>
#include <set>
#include <iostream>

class Text_query{
    public:
        typedef std::vector<std::string>::size_type line_no;
        std::set<line_no> run_query(const std::string&) const;
};