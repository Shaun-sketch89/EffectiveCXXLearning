#include "query_base.h"

class WordQuery: public Query_base {
    friend class Query;
    WordQuery(const std::string&);
    std::set<Text_query::line_no> eval(const Text_query&) const;
    std::ostream& display(std::ostream&) const;
};