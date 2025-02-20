#include "query.h"
#include "and_query.h"
#include "or_query.h"
#include "not_query.h"

inline Query operator&(const Query& lhs, const Query& rhs) {
    //explicit manner: return Query(new AndQuery(lhs, rhs));
    //implicit manner: return new AndQuery(lhs, rhs);
    return new AndQuery(lhs, rhs);
}

inline Query operator|(const Query& lhs, const Query& rhs) {
    //explicit manner: return Query(new OrQuery(lhs, rhs));
    //implicit manner: return new OrQuery(lhs, rhs);
    return new OrQuery(lhs, rhs);
}

inline Query operator~(const Query& q) {
    //explicit manner: return Query(new NotQuery(q));
    //implicit manner: return new NotQuery(q);
    return new NotQuery(q);
}

inline std::ostream& operator<<(std::ostream& os, const Query& q){
    return q.display(os);
}