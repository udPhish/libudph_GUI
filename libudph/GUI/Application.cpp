#include <libudph/GUI/Application.h>

namespace UD::Application
{
auto Application::arguments() -> Arguments&
{
  return _arguments;
}
void Application::InternalStartup(int argc, char** argv)
{
  if (argc > 1)
  {
    _arguments.assign(argv + 1, argv + argc);
  }
  Startup();
}
void Application::InternalSetup()
{
  Setup();
}
void Application::InternalMain()
{
  Main();
}
void Application::InternalTeardown()
{
  Teardown();
}
void Application::InternalShutdown()
{
  Shutdown();
}
void Application::Startup() {}
void Application::Setup() {}
void Application::Main() {}
void Application::Teardown() {}
void Application::Shutdown() {}
auto Application::GetNextID() -> ID
{
  return _next_id++;
}

auto Application_wxWrapper::OnInit() -> bool
{
  udStartup();
  if (!_application)
  {
    return false;
  }
  _application->InternalStartup(this->argc, this->argv);
  return true;
}
Application_wxWrapper::Application_wxWrapper() : _application{nullptr} {}
auto Application_wxWrapper::application() -> Application&
{
  return *_application;
}

auto Get() -> Application&
{
  return wxGetApp().application();
}
}  // namespace UD::Application