#ifndef TCPMETA_H
#define TCPMETA_H

#include <QObject>
QT_BEGIN_NAMESPACE
namespace tpkg{
    typedef struct{
        unsigned short STVNADR:16;
        unsigned char body_size:8;
        bool LGQ, ERT, FLQ, MSG, IFB, ACT, USQ, DBG;
        unsigned short FRVNADR:16;
    }tpkghead;
    typedef enum{
        LOGIN=1, ERROR, FILEQUE, MESSAGE, FILEBLOK, ACT, USERQUE, DEBUG
    }tpkgtype;
    typedef struct{
        tpkghead th;
        char *body;
    }tpkgfull;
}
QT_END_NAMESPACE
using namespace tpkg;
class TcpMeta
{
    Q_OBJECT
public:
    TcpMeta();
    tpkgfull *makePack(tpkgtype, char *, unsigned short, unsigned short);
    tpkgtype getPackType(tpkgfull *);
};

#endif // TCPMETA_H
