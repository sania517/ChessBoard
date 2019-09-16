#ifndef NEEDTOREAD_H
#define NEEDTOREAD_H

enum need_to_read {emptyModeRead,not_read, read};

class NeedToRead
{
private:
    //need_to_read n_read = emptyModeRead;

public:
    NeedToRead();
    need_to_read get_need_to_read();
};

#endif // NEEDTOREAD_H
