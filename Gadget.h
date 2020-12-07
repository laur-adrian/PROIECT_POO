#ifndef MAIN_CPP_GADGET_H
#define MAIN_CPP_GADGET_H

#include <iostream>
#include <cstring>


class Gadget{

private:
    char OS[15];
    char conexiune[20];

public:
    Gadget(const char vers_OS[15],const char conex[15]);

    const char *getOs() const;

    const char *getConexiune() const;

    void setOs(const char *os);

    void setConexiune(const char *conex);

    Gadget &operator=(const Gadget &ob);

    friend std::ostream &operator<<(std::ostream &os, const Gadget &gadget);

    virtual void printCaracteristici ();

    virtual ~Gadget();

};


#endif
