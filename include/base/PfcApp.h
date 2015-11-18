#ifndef PFCAPP_H
#define PFCAPP_H

#include "MooseApp.h"

class PfcApp;

template<>
InputParameters validParams<PfcApp>();

class PfcApp : public MooseApp
{
public:
  PfcApp(InputParameters parameters);
  virtual ~PfcApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* PFCAPP_H */
