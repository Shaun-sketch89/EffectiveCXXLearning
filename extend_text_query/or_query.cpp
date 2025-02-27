#include "or_query.h"

OrQuery::OrQuery(const Query& l, const Query& r): BinaryQuery(l, r, "|"){}

std::set<line_no> OrQuery::eval(const Text_query& text) const {
    std::set<line_no> ret_lines = lhs.eval(text);
    return ret_lines;
}

std::ostream& OrQuery::display(std::ostream& os) const {
    return os << "(" << lhs << " | " << rhs << ")";
}