//---------------------------------------------------------------------------

#ifndef FormCreateFolderH
#define FormCreateFolderH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
class TCreateFolderDlg : public TForm
{
__published:	// IDE-managed Components
     TPanel *Panel2;
     TDriveComboBox *DriveComboBox1;
     TLabeledEdit *NewFolderLE;
     TDirectoryListBox *DirLB;
     TPanel *Panel1;
     TLabel *FolderLabel;
     TLabel *DirListBoxLabel;
     TBitBtn *CreateBtn;
     TBitBtn *CancelBtn;
     TPanel *PanelBtnBack;
     TPanel *CloseBtn;
     TLabel *Label1;
     TLabel *Label2;
     void __fastcall CreateBtnClick(TObject *Sender);
     void __fastcall CancelBtnClick(TObject *Sender);
     void __fastcall CloseBtnClick(TObject *Sender);
     void __fastcall DirLBChange(TObject *Sender);
     void __fastcall CloseBtnMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
     void __fastcall CloseBtnMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
     void __fastcall FormShow(TObject *Sender);
     void __fastcall NewFolderLEExit(TObject *Sender);
     void __fastcall NewFolderLEKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
AnsiString NewFolderName;
AnsiString __fastcall CreateNewFolder();

     __fastcall TCreateFolderDlg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCreateFolderDlg *CreateFolderDlg;
//---------------------------------------------------------------------------
#endif
