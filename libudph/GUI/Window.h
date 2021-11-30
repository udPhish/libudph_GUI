//#pragma once
//
//#include <libudph/Class/Event.h>
//#include <libudph/Class/Interface.h>
//#include <libudph/GUI/ApplicationTypes.h>
//#include <libudph/Math/Tensor.h>
//
//#include "wx/frame.h"
//
//namespace UD::Application::GUI
//{
//class Window
//    : public UD::Interface::Interface<Window, UD::Interface::SimpleModifiers>
//{
//  wxFrame* _wx_frame = nullptr;
//  ID       _id       = 0;
//
//  void OnExit(wxCommandEvent&)
//  {
//    _wx_frame->Close(true);
//  }
//
// public:
//  using EventClose = UD::Event::Event<ID>;
//  EventClose close;
//
//  //TODO: Send RequestID Event to populate id without knowing parent application
//  //      Possibly implement Event::Chain in UD::Event
//  Window(std::string                title,
//         UD::Tensor::Vector<2, int> position,
//         UD::Tensor::Vector<2, int> size)
//      : _wx_frame(new wxFrame(nullptr,
//                              wxID_ANY,
//                              title,
//                              wxPoint(position.x(), position.y()),
//                              wxSize(size.x(), size.y())))
//      , _id(2)
//  {
//    _wx_frame->Bind(wxEVT_COMMAND_MENU_SELECTED,
//                    &Window::OnExit,
//                    this,
//                    wxID_EXIT);
//  }
//  void Show()
//  {
//    _wx_frame->Show();
//  }
//  auto id() -> ID
//  {
//    return _id;
//  }
//};
//}  // namespace UD::Application::GUI