#include "binary_query.h"

BinaryQuery::BinaryQuery(const Query& l, const Query& r, std::string s): lhs(l), rhs(r), op(s){}

std::ostream& BinaryQuery::display(std::ostream& os) const {
    return os << "(" << lhs << " " << op << " " << rhs << ")";
}