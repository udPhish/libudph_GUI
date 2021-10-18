#pragma once

#include <libudph/Class/Event.h>
#include <libudph/Class/Interface.h>
#include <libudph/Math/Tensor.h>
#include <libudph/GUI/ApplicationTypes.h>

#include "wx/wx.h"


namespace UD::Application::GUI
{
class Window
    : public UD::Interface::Interface<Window, UD::Interface::SimpleModifiers>
{
  wxFrame* _wx_frame = nullptr;
  UD::Application::ID       _id       = 0;

  void OnExit(wxCommandEvent&)
  {
    _wx_frame->Close(true);
  }
 public:
   using EventClose =UD::Event::Event<UD::Application::ID>;
   EventClose close;
   
  Window(std::string                title,
         UD::Tensor::Vector<2, int> position,
         UD::Tensor::Vector<2, int> size)
      : _wx_frame(new wxFrame(nullptr,
                              wxID_ANY,
                              title,
                              wxPoint(position.x(), position.y()),
                              wxSize(size.x(), size.y())))
  {
    _wx_frame->Bind(wxEVT_COMMAND_MENU_SELECTED, &Window::OnExit, this, wxID_EXIT);
  }
  void Show()
  {
    _wx_frame->Show();
  }
};
}  // namespace UD::Application::GUI