#include "query_base.h"

class BinaryQuery: public Query_base {
protected:
    BinaryQuery(const Query& l, const Query& r, std::string s): Query_base(l, r, s){}
    Query lhs, rhs;
};