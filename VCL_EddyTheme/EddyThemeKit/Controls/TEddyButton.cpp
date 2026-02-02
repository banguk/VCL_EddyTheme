//---------------------------------------------------------------------------

#pragma hdrstop

#include "TEddyButton.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

__fastcall TEddyButton::TEddyButton(TComponent *Owner) : TEddyBaseControl(Owner)
{
    // 초기 설정
    Width = 120;
    Height = 40;
    Cursor = crHandPoint; // 마우스를 올리면 손가락 모양으로 변경
    state_ = TButtonState::Normal;
}

__fastcall TEddyButton::~TEddyButton()
{
}

void __fastcall TEddyButton::Paint(void)
{
    // [Canvas Drawing] 여기서 모든 그림을 그립니다.

    // 1. 상태에 따른 배경색 결정
    TColor backColor;
    TColor themePrimary = GetTheme()->GetPrimaryColor();

    switch (state_)
    {
    case TButtonState::Hover:
        // 마우스 올렸을 때: 메인 색상보다 조금 더 밝게 (여기선 그냥 메인 색 사용)
        backColor = themePrimary;
        break;
    case TButtonState::Pressed:
        // 눌렀을 때: 조금 어둡게 처리 (RGB값 조작 예시)
        backColor = (TColor)(themePrimary - 0x00202020);
        break;
    default: // Normal
        // 평소: 회색 톤
        backColor = (TColor)0x00505050;
        break;
    }

    // 2. 배경 사각형 그리기
    Canvas->Brush->Style = bsSolid;
    Canvas->Brush->Color = backColor;
    Canvas->Pen->Style = psClear; // 테두리 선 없음
    Canvas->Rectangle(ClientRect);

    // 3. 텍스트 그리기
    Canvas->Font->Assign(Font);                       // 사용자가 설정한 폰트 가져오기
    Canvas->Font->Color = GetTheme()->GetTextColor(); // 글자색은 테마 따름

    // 텍스트를 정중앙에 그리기 위한 플래그
    TTextFormat flags = TTextFormat() << tfCenter << tfSingleLine << tfVerticalCenter;
    TRect textRect = ClientRect;

    UnicodeString text = Caption;
    Canvas->TextRect(textRect, text, flags);
}

void __fastcall TEddyButton::MouseDown(TMouseButton Button, TShiftState Shift, int X, int Y)
{
    TEddyBaseControl::MouseDown(Button, Shift, X, Y); // 부모 기능 유지
    if (Button == mbLeft)
    {
        state_ = TButtonState::Pressed;
        Invalidate(); // "화면을 다시 그려라" -> Paint()가 호출됨
    }
}

void __fastcall TEddyButton::MouseUp(TMouseButton Button, TShiftState Shift, int X, int Y)
{
    TEddyBaseControl::MouseUp(Button, Shift, X, Y);
    if (Button == mbLeft)
    {
        // 마우스를 뗐을 때 여전히 버튼 위라면 Hover, 아니면 Normal
        TRect rect = ClientRect;
        if (rect.Contains(Point(X, Y)))
        {
            state_ = TButtonState::Hover;
        }
        else
        {
            state_ = TButtonState::Normal;
        }
        Invalidate();
    }
}

void __fastcall TEddyButton::CMMouseEnter(TMessage &Message)
{
    state_ = TButtonState::Hover;
    Invalidate();
}

void __fastcall TEddyButton::CMMouseLeave(TMessage &Message)
{
    state_ = TButtonState::Normal;
    Invalidate();
}

// --- 컴포넌트 등록 ---
namespace Eddybutton
{
void __fastcall PACKAGE Register()
{
    // 툴 팔레트의 "EddyTheme" 카테고리에 이 버튼을 등록합니다.
    TComponentClass classes[1] = {__classid(TEddyButton)};
    RegisterComponents(L"EddyTheme", classes, 0);
}
} // namespace Eddybutton

