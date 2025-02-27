#include "binary_query.h"

class Query;
class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query&, const Query&);
    std::set<line_no> eval(const Text_query&) const;
    std::ostream& display(std::ostream&) const;
};

inline Query operator|(const Query& lhs, const Query& rhs) {
    //explicit manner: return Query(new OrQuery(lhs, rhs));
    //implicit manner: return new OrQuery(lhs, rhs);
    return new OrQuery(lhs, rhs);
}