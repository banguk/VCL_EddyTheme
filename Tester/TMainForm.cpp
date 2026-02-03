//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TMainForm.h"
#include "TEddyButton.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent *Owner) : TForm(Owner)
{
    TEddyButton *btn = new TEddyButton(this);
    btn->Parent = this;            // 폼 위에 올리기
    btn->Caption = L"Eddy Button"; // 텍스트 설정

    // 위치 및 크기
    btn->Left = 50;
    btn->Top = 50;
    btn->Width = 120;
    btn->Height = 40;

    // 이벤트 핸들러 테스트 (람다식 사용)
    // btn->OnClick = [](TObject *Sender) { ShowMessage("버튼이 정상적으로 동작합니다!"); };
}
//---------------------------------------------------------------------------

