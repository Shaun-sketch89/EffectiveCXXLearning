#include "query_base.h"

class NotQuery: public Query_base {
    friend Query operator~(const Query&);
    NotQuery(const Query&);
    std::set<Text_query::line_no> eval(const Text_query&) const;
    std::ostream& display(std::ostream&) const;
};