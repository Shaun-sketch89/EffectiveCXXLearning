#ifndef QUERY_H
#define QUERY_H

#include "word_query.h"

class Query{
    friend Query operator&(const Query&, const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator~(const Query&);
public:
    Query(const std::string&);
    Query(const Query& c);
    ~Query();
    Query& operator=(const Query&);
    std::set<Text_query::line_no> eval(const Text_query&) const;
    std::ostream& display(std::ostream& = std::cout) const;
private:
    // 这个构造方法不提供给用户，由友元重载操作符构造
    Query(Query_base* query);
    Query_base *q;
    std::size_t *use;
    void decr_use();
};

inline std::ostream& operator<<(std::ostream& os, const Query& q){
    return q.display(os);
}

#endif