//---------------------------------------------------------------------------

#pragma hdrstop

#include "EddyThemeManager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TEddyThemeManager *TEddyThemeManager::pInstance_ = nullptr;

__fastcall TEddyThemeManager::TEddyThemeManager()
{

    // 초기는 Light
    primaryColor_ = (TColor)0x00D77800;    // 짙은 파랑 (VCL TColor는 0x00BBGGRR 형식)
    backgroundColor_ = (TColor)0x00333333; // 짙은 회색
    textColor_ = clWhite;
}

TEddyThemeManager *__fastcall TEddyThemeManager::GetInstance()
{
    if (pInstance_ == nullptr)
    {
        pInstance_ = new TEddyThemeManager();
    }
    return pInstance_;
}

void __fastcall TEddyThemeManager::SetPrimaryColor(TColor color)
{
    primaryColor_ = color;
}

TColor __fastcall TEddyThemeManager::GetPrimaryColor()
{
    return primaryColor_;
}

void __fastcall TEddyThemeManager::SetBackgroundColor(TColor color)
{
    backgroundColor_ = color;
}

TColor __fastcall TEddyThemeManager::GetBackgroundColor()
{
    return backgroundColor_;
}

void __fastcall TEddyThemeManager::SetTextColor(TColor color)
{
    textColor_ = color;
}

TColor __fastcall TEddyThemeManager::GetTextColor()
{
    return textColor_;
}

