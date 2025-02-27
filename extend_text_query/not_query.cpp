#include "not_query.h"

NotQuery::NotQuery(const Query& q): query(q){}

std::set<Text_query::line_no> NotQuery::eval(const Text_query& text) const {
    std::set<Text_query::line_no> ret_lines = query.eval(text);
    return ret_lines;
}

std::ostream& NotQuery::display(std::ostream& os) const {
    return os << "~(" << query << ")";
}