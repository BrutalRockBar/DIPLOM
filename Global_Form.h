//---------------------------------------------------------------------------

#ifndef Global_FormH
#define Global_FormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Menus.hpp>
#include "frxClass.hpp"
#include "frxPreview.hpp"
#include "frxDBSet.hpp"
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "frxExportCSV.hpp"
#include "frxExportHTML.hpp"
#include "frxExportImage.hpp"
#include "frxExportPDF.hpp"
#include "frxExportRTF.hpp"
#include "frxExportText.hpp"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdExplicitTLSClientServerBase.hpp>
#include <IdMessageClient.hpp>
#include <IdSMTP.hpp>
#include <IdSMTPBase.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdMessage.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	TPageControl *PageControl1;
	TImageList *ImageList1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TStatusBar *StatusBar1;
	TGroupBox *GroupBox1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TCheckBox *CheckBox1;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TLabel *Label4;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TfrxDBDataset *frxDBDataset1;
	TADOTable *ADOTable1;
	TfrxPDFExport *frxPDFExport1;
	TfrxHTMLExport *frxHTMLExport1;
	TfrxRTFExport *frxRTFExport1;
	TfrxBMPExport *frxBMPExport1;
	TfrxJPEGExport *frxJPEGExport1;
	TfrxTIFFExport *frxTIFFExport1;
	TfrxGIFExport *frxGIFExport1;
	TfrxSimpleTextExport *frxSimpleTextExport1;
	TfrxCSVExport *frxCSVExport1;
	TfrxDBDataset *frxDBDataset2;
	TADOTable *ADOTable2;
	TMenuItem *N10;
	TTimer *Timer1;
	TIdSMTP *IdSMTP1;
	TIdMessage *IdMessage1;
	TADOQuery *ADOQuery1;
	TfrxReport *frxReport1;
	void __fastcall WriteGrid(AnsiString query);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall TabUpdate(AnsiString query);
	int __fastcall Online(void);
	void __fastcall Offline(void);
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall StringGrid1DblClick(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall ComboBox2DropDown(TObject *Sender);
	void __fastcall ComboBox1Select(TObject *Sender);
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall RadioButton2Click(TObject *Sender);
	void __fastcall RadioButton3Click(TObject *Sender);
	void __fastcall ComboBox2Select(TObject *Sender);
	void __fastcall ComboBox1DropDown(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall N10Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall IdMessage1InitializeISO(System::WideChar &VHeaderEncoding, UnicodeString &VCharSet);



private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void __fastcall Form_Shadow(int n);
	void __fastcall TForm1::Form_shadow_OnClick(TObject *Sender);
	void __fastcall TForm1::Form_shadow_ContextPopup(TObject *Sender, TPoint &MousePos,
		  bool &Handled);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
