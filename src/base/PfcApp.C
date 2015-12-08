#include "PfcApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "Factory.h"

#include "BoundingBoxFuncIC.h"
#include "CoupledPFC.h"
#include "BasePFC.h"

template<>
InputParameters validParams<PfcApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

PfcApp::PfcApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
//  ModulesApp::registerObjects(_factory);
  PfcApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
//  ModulesApp::associateSyntax(_syntax, _action_factory);
  PfcApp::associateSyntax(_syntax, _action_factory);
}

PfcApp::~PfcApp()
{
}

// External entry point for dynamic application loading
extern "C" void PfcApp__registerApps() { PfcApp::registerApps(); }
void
PfcApp::registerApps()
{
  registerApp(PfcApp);
}

// External entry point for dynamic object registration
extern "C" void PfcApp__registerObjects(Factory & factory) { PfcApp::registerObjects(factory); }
void
PfcApp::registerObjects(Factory & factory)
{
  registerInitialCondition(BoundingBoxFuncIC);   //<-- Register kernels here
  registerKernel(CoupledPFC); 
  registerKernel(BasePFC);
}

// External entry point for dynamic syntax association
extern "C" void PfcApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { PfcApp::associateSyntax(syntax, action_factory); }
void
PfcApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
