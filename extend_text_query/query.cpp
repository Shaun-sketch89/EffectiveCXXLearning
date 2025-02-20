#include "query.h"

Query::Query(const Query& c): q(c.q), use(c.use){
    ++*use;
}

Query::~Query() {
    decr_use();
}

Query& Query::operator=(const Query& rhs) {
    ++*rhs.use;
    decr_use();
    q = rhs.q;
    use = rhs.use;
    return *this;
}

std::set<Text_query::line_no> Query::eval(const Text_query& t) const {
    return q->eval(t);
}

std::ostream& Query::display(std::ostream& os) const {
    return q->display(os);
}

Query::Query(Query_base* query): q(query), use(new std::size_t(1)){}

void Query::decr_use() {
    if(--*use == 0){
        delete q;
        delete use;
    }
}