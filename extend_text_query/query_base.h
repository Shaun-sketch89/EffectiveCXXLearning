#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include <set>
#include <iostream>

#include "text_query.h"

class Query_base {
    friend class Query;
protected:
    virtual ~Query_base();
    typedef Text_query::line_no line_no;
private:
    virtual std::set<line_no> eval(const Text_query&) const = 0;
    virtual std::ostream& display(std::ostream& = std::cout) const = 0;
};

#endif