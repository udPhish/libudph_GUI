#pragma once
#include <libudph/Class/Interface.h>

#include "wx/wx.h"

#include "wx/app.h"

extern void udStartup();
namespace UD::Application
{
class Application_wxWrapper
    : public UD::Interface::Interface<Application_wxWrapper,
                                      UD::Pack::Pack<wxApp>,
                                      UD::Interface::SimpleModifiers>
{
  std::unique_ptr<Application> _application;

  auto OnInit() -> bool override;

 public:
  Application_wxWrapper();
  auto application() -> Application&;
  template<std::derived_from<Application> T>
  void InitApplication()
  {
    _application = std::make_unique<T>();
  }
};
}  // namespace UD::Application

wxIMPLEMENT_APP(UD::Application::Application_wxWrapper);
