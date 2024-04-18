#include"tools.h"


namespace Tools
{
    void loger(const char* str)
    {
        using namespace std;
        qDebug() << "==> [log:" << str << "]";
        //qDebug()本身会默认附加空格和换行的，即在拼接的字符串之间加空格，最后换行
    }
}
