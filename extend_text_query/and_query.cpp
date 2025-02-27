#include "and_query.h"

AndQuery::AndQuery(const Query& l, const Query& r): BinaryQuery(l, r, "&"){}

std::set<line_no> AndQuery::eval(const Text_query& text) const {
    std::set<line_no> ret_lines = lhs.eval(text);
    return ret_lines;
}

std::ostream& AndQuery::display(std::ostream& os) const {
    return os << "(" << lhs << " & " << rhs << ")";
}