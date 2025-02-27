#ifndef BINARY_QUERY_H
#define BINARY_QUERY_H

#include "query.h"

class BinaryQuery: public Query_base {
protected:
    BinaryQuery(const Query& l, const Query& r, std::string s);
    std::ostream& display(std::ostream& os) const;
    Query lhs, rhs;
    std::string op;
};

#endif