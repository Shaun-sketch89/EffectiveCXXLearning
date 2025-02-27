#include "query.h"

class NotQuery: public Query_base {
    friend Query operator~(const Query&);
    NotQuery(const Query&);
    std::set<Text_query::line_no> eval(const Text_query&) const;
    std::ostream& display(std::ostream&) const;
    const Query query;
};

inline Query operator~(const Query& q) {
    //explicit manner: return Query(new NotQuery(q));
    //implicit manner: return new NotQuery(q);
    return new NotQuery(q);
}