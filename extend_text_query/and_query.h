#include "binary_query.h"

class Query;
class AndQuery: public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query&, const Query&);
    std::set<line_no> eval(const Text_query&) const;
    std::ostream& display(std::ostream&) const;
};

inline Query operator&(const Query& lhs, const Query& rhs) {
    //explicit manner: return Query(new AndQuery(lhs, rhs));
    //implicit manner: return new AndQuery(lhs, rhs);
    return new AndQuery(lhs, rhs);
}