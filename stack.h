#ifndef STACK_H
#define STACK_H
#include "literal.h"
#include "errorhandler.h"
#include <QStack>

class Stack
{

public:
      static QStack<Literal*>* getInstance();
      static void freeInstance();

private:
      static QStack<Literal*>* uniqueInstance;

};

#endif // STACK_H
