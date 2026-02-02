//---------------------------------------------------------------------------

#ifndef TEddyBaseControlH
#define TEddyBaseControlH
//---------------------------------------------------------------------------
#include "EddyThemeManager.h"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>

class PACKAGE TEddyBaseControl : public TCustomControl
{
  __published: // [프로퍼티 노출] IDE 인스펙터 창에 보일 속성들
    __property Align;
    __property Anchors;
    __property Cursor;
    __property Enabled;
    __property Font;
    __property Visible;
    __property ParentFont;

    // 표준 마우스 이벤트 노출
    __property OnClick;
    __property OnMouseEnter;
    __property OnMouseLeave;
    __property OnMouseDown;
    __property OnMouseUp;

  public:
    __fastcall TEddyBaseControl(TComponent *Owner);
    __fastcall ~TEddyBaseControl();

  protected:
    // [핵심] 화면을 그리는 함수. 자식들이 이를 오버라이드해서 자신만의 모양을 그림.
    virtual void __fastcall Paint(void);

    // 자식들이 테마 매니저를 쉽게 쓰도록 돕는 헬퍼 함수
    TEddyThemeManager *__fastcall GetTheme();
};

#endif

