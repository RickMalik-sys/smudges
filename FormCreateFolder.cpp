//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormCreateFolder.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCreateFolderDlg *CreateFolderDlg;
//---------------------------------------------------------------------------
__fastcall TCreateFolderDlg::TCreateFolderDlg(TComponent* Owner)
     : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TCreateFolderDlg::CreateBtnClick(TObject *Sender)
{
NewFolderName = CreateNewFolder();
DirLB->Update();
}
//---------------------------------------------------------------------------

void __fastcall TCreateFolderDlg::CancelBtnClick(TObject *Sender)
{
DirLB->Update();
NewFolderLE->Text = "";
FolderLabel->Caption = DirLB->Directory + "\\";

}
//---------------------------------------------------------------------------

void __fastcall TCreateFolderDlg::CloseBtnClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TCreateFolderDlg::DirLBChange(TObject *Sender)
{
//DirLB->Update();
FolderLabel->Caption = DirLB->Directory + "\\" + NewFolderLE->Text;

}
//---------------------------------------------------------------------------

void __fastcall TCreateFolderDlg::CloseBtnMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
PanelBtnBack->Color = clRed;
CloseBtn->Font->Color = clRed;
CloseBtn->Caption = "Closing";
PanelBtnBack->BevelOuter = bvLowered;
PanelBtnBack->BevelInner = bvLowered;

}
//---------------------------------------------------------------------------

void __fastcall TCreateFolderDlg::CloseBtnMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
PanelBtnBack->Color = clBlack;
CloseBtn->Font->Color = clMaroon;
PanelBtnBack->BevelOuter = bvRaised;
PanelBtnBack->BevelInner = bvLowered;

}
//---------------------------------------------------------------------------

void __fastcall TCreateFolderDlg::FormShow(TObject *Sender)
{
NewFolderName = "";
NewFolderLE->Text = "";
FolderLabel->Caption = DirLB->Directory + "\\";
}
//---------------------------------------------------------------------------
AnsiString __fastcall TCreateFolderDlg::CreateNewFolder()
{
AnsiString s = DirLB->Directory + "\\" + NewFolderLE->Text;
if(CreateDir(s))
     {
     ShowMessage("New folder created.");
     }
     else
     {
     ShowMessage( s + " already exists.");
     }
DirLB->Update();
CloseBtn->SetFocus();
return s;

}
//--------------------------------------------------------------------------
void __fastcall TCreateFolderDlg::NewFolderLEExit(TObject *Sender)
{
CreateBtn->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TCreateFolderDlg::NewFolderLEKeyUp(TObject *Sender,
      WORD &Key, TShiftState Shift)
{

if(Key == VK_RETURN)

     {
     CreateBtn->Click();
     }
}
//---------------------------------------------------------------------------

