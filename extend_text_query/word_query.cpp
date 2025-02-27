#include "word_query.h"

WordQuery::WordQuery(const std::string& s): query_word(s) {}

std::set<Text_query::line_no> WordQuery::eval(const Text_query& t) const {
    return t.run_query(query_word);
}

std::ostream& WordQuery::display(std::ostream& os) const {
    return os << query_word;
}