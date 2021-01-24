#include "tcpmeta.h"

TcpMeta::TcpMeta()
{

}
tpkgfull *TcpMeta::makePack(tpkgtype t, char *dat, unsigned short stvna, unsigned short frvna){
    tpkgfull *fpkg = new tpkgfull;
    char len = sizeof(dat);
    if(sizeof(dat) > 255){
        delete fpkg;
        return nullptr;
    }
    fpkg->th.ACT=fpkg->th.DBG=fpkg->th.ERT=fpkg->th.FLQ=fpkg->th.IFB=fpkg->th.LGQ=fpkg->th.MSG=fpkg->th.USQ=false;
    fpkg->th.STVNADR=stvna;
    fpkg->th.FRVNADR=frvna;
    fpkg->th.body_size = len;
    switch(t){
    case LOGIN:
        fpkg->th.LGQ=true;
        break;
    case FILEQUE:
        fpkg->th.FLQ=true;
        break;
    case ERROR:
        fpkg->th.ERT=true;
        break;
    case FILEBLOK:
        fpkg->th.IFB=true;
    case MESSAGE:
        fpkg->th.MSG=true;
        break;
    case ACT:
        fpkg->th.ACT=true;
        break;
    case USERQUE:
        fpkg->th.USQ = true;
        break;
    case DEBUG:
        fpkg->th.DBG = true;
        break;
    default:
        delete fpkg;
        return nullptr;
    }
    fpkg->body = dat;
    return fpkg;
}
tpkgtype TcpMeta::getPackType(tpkgfull * fpkg){
    tpkghead t = fpkg->th;
    if(t.ACT){
        return ACT;
    }else if(t.DBG){
        return DEBUG;
    }else if(t.ERT){
        return ERROR;
    }else if(t.FLQ){
        return FILEQUE;
    }else if(t.LGQ){
        return LOGIN;
    }else if(t.USQ){
        return USERQUE;
    }else if(t.MSG){
        return t.IFB?FILEBLOK:MESSAGE;
    }else{
        _THROW_BAD_ALLOC;
        return (tpkgtype)-1;
    }
}
