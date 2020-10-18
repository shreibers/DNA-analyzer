//
// Created by a on 7/5/20.
//

#ifndef DNA_STATUS_H
#define DNA_STATUS_H

#include <cstring>
#include <list>

typedef enum {
    E_new,
    E_modified,
    E_up_to_date
}STATUSES;


class Status {
public:

    const char* getStatus()const{ return m_status;}
    void setStatus(STATUSES status){ m_status = const_cast<char *>(s_status_list[status]);}

private:
    char* m_status;
    static const char* const s_status_list[];
};


#endif //DNA_STATUS_H
