#include <libudph/GUI/Application.h>

wxIMPLEMENT_APP(UD::Application::Application_wxWrapper);

auto UD::Application::Application::arguments() -> Arguments&
{
  return _arguments;
}
void UD::Application::Application::InternalStartup(int argc, char** argv)
{
  if (argc > 1)
  {
    _arguments.assign(argv + 1, argv + argc);
  }
  Startup();
}
void UD::Application::Application::InternalSetup()
{
  Setup();
}
void UD::Application::Application::InternalMain()
{
  Main();
}
void UD::Application::Application::InternalTeardown()
{
  Teardown();
}
void UD::Application::Application::InternalShutdown()
{
  Shutdown();
}
void UD::Application::Application::Startup() {}
void UD::Application::Application::Setup() {}
void UD::Application::Application::Main() {}
void UD::Application::Application::Teardown() {}
void UD::Application::Application::Shutdown() {}
auto UD::Application::Application::GetNextID() -> ID
{
  return _next_id++;
}
void UD::Application::Application::Run(int argc, char** argv)
{
  InternalStartup(argc, argv);
}
auto UD::Application::Application_wxWrapper::OnInit() -> bool
{
  udStartup();
  if (!_application)
  {
    return false;
  }
  _application->InternalStartup(this->argc, this->argv);
  return true;
}
UD::Application::Application_wxWrapper::Application_wxWrapper()
    : _application{nullptr}
{
}
auto UD::Application::Application_wxWrapper::application() -> Application&
{
  return *_application;
}
