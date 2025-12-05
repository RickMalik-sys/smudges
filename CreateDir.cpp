//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("FormCreateFolder.cpp", CreateFolderDlg);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
     try
     {
           Application->Initialize();
           Application->Title = "Create New Folder";
           Application->CreateForm(__classid(TCreateFolderDlg), &CreateFolderDlg);
           Application->Run();
     }
     catch (Exception &exception)
     {
           Application->ShowException(&exception);
     }
     catch (...)
     {
           try
           {
                throw Exception("");
           }
           catch (Exception &exception)
           {
                Application->ShowException(&exception);
           }
     }
     return 0;
}
//---------------------------------------------------------------------------
