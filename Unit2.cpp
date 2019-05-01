//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <inifiles.hpp>

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

   TIniFile *ini;
   ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );

   Edit33->Text= ini->ReadString( "NetWork_Config", "SN",  "" ) ;


   Edit1->Text= ini->ReadString( "Device_Config", "Light1",  "Light1" ) ;
   Edit2->Text= ini->ReadString( "Device_Config", "Light2",  "Light2" ) ;
   Edit3->Text= ini->ReadString( "Device_Config", "Light3",  "Light3" ) ;
   Edit4->Text= ini->ReadString( "Device_Config", "Light4",  "Light4" ) ;
   Edit5->Text= ini->ReadString( "Device_Config", "Light5",  "Light5" ) ;
   Edit6->Text= ini->ReadString( "Device_Config", "Light6",  "Light6" ) ;
   Edit7->Text= ini->ReadString( "Device_Config", "Light7",  "Light7" ) ;
   Edit8->Text= ini->ReadString( "Device_Config", "Light8",  "Light8" ) ;
   Edit9->Text= ini->ReadString( "Device_Config", "Light9",  "Light9" ) ;
   Edit10->Text= ini->ReadString( "Device_Config", "Light10",  "Light10" ) ;
   Edit11->Text= ini->ReadString( "Device_Config", "Light11",  "Light11" ) ;
   Edit12->Text= ini->ReadString( "Device_Config", "Light12",  "Light12" ) ;
   Edit13->Text= ini->ReadString( "Device_Config", "Light13",  "Light13" ) ;
   Edit14->Text= ini->ReadString( "Device_Config", "Light14",  "Light14" ) ;
   Edit15->Text= ini->ReadString( "Device_Config", "Light15",  "Light15" ) ;
   Edit16->Text= ini->ReadString( "Device_Config", "Light16",  "Light16" ) ;
   Edit17->Text= ini->ReadString( "Device_Config", "Light17",  "Light17" ) ;
   Edit18->Text= ini->ReadString( "Device_Config", "Light18",  "Light18" ) ;
   Edit19->Text= ini->ReadString( "Device_Config", "Light19",  "Light19" ) ;
   Edit20->Text= ini->ReadString( "Device_Config", "Light20",  "Light20" ) ;
   Edit21->Text= ini->ReadString( "Device_Config", "Light21",  "Light21" ) ;
   Edit22->Text= ini->ReadString( "Device_Config", "Light22",  "Light22" ) ;
   Edit23->Text= ini->ReadString( "Device_Config", "Light23",  "Light23" ) ;
   Edit24->Text= ini->ReadString( "Device_Config", "Light24",  "Light24" ) ;
   Edit25->Text= ini->ReadString( "Device_Config", "Light25",  "Light25" ) ;
   Edit26->Text= ini->ReadString( "Device_Config", "Light26",  "Light26" ) ;
   Edit27->Text= ini->ReadString( "Device_Config", "Light27",  "Light27" ) ;
   Edit28->Text= ini->ReadString( "Device_Config", "Light28",  "Light28" ) ;
   Edit29->Text= ini->ReadString( "Device_Config", "Light29",  "Light29" ) ;
   Edit30->Text= ini->ReadString( "Device_Config", "Light30",  "Light30" ) ;
   Edit31->Text= ini->ReadString( "Device_Config", "Light31",  "Light31" ) ;
   Edit32->Text= ini->ReadString( "Device_Config", "Light32",  "Light32" ) ;

	//ShowMessage(ini->ReadString( "Device_ICO", "Light1_ON",  "Default Caption" ) );
   Image1->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light1_ON",  "Default Caption" ) );
   Image2->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light2_ON",  "Default Caption" ) );
   Image3->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light3_ON",  "Default Caption" ) );
   Image4->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light4_ON",  "Default Caption" ) );
   Image5->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light5_ON",  "Default Caption" ) );
   Image6->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light6_ON",  "Default Caption" ) );
   Image7->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light7_ON",  "Default Caption" ) );
   Image8->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light8_ON",  "Default Caption" ) );

   Image17->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light9_ON",  "Default Caption" ) );
   Image20->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light10_ON",  "Default Caption" ) );
   Image21->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light11_ON",  "Default Caption" ) );
   Image23->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light12_ON",  "Default Caption" ) );
   Image26->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light13_ON",  "Default Caption" ) );
   Image27->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light14_ON",  "Default Caption" ) );
   Image30->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light15_ON",  "Default Caption" ) );
   Image31->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light16_ON",  "Default Caption" ) );

   Image33->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light17_ON",  "Default Caption" ) );
   Image36->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light18_ON",  "Default Caption" ) );
   Image37->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light19_ON",  "Default Caption" ) );
   Image39->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light20_ON",  "Default Caption" ) );
   Image42->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light21_ON",  "Default Caption" ) );
   Image43->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light22_ON",  "Default Caption" ) );
   Image46->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light23_ON",  "Default Caption" ) );
   Image47->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light24_ON",  "Default Caption" ) );

   Image49->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light25_ON",  "Default Caption" ) );
   Image52->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light26_ON",  "Default Caption" ) );
   Image53->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light27_ON",  "Default Caption" ) );
   Image56->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light28_ON",  "Default Caption" ) );
   Image57->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light29_ON",  "Default Caption" ) );
   Image60->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light30_ON",  "Default Caption" ) );
   Image61->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light31_ON",  "Default Caption" ) );
   Image64->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light32_ON",  "Default Caption" ) );






   Image9->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light1_OFF",  "Default Caption" ) );
   Image10->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light2_OFF",  "Default Caption" ) );
   Image11->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light3_OFF",  "Default Caption" ) );
   Image12->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light4_OFF",  "Default Caption" ) );
   Image13->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light5_OFF",  "Default Caption" ) );
   Image14->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light6_OFF",  "Default Caption" ) );
   Image15->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light7_OFF",  "Default Caption" ) );
   Image16->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light8_OFF",  "Default Caption" ) );

   Image18->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light9_OFF",  "Default Caption" ) );
   Image19->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light10_OFF",  "Default Caption" ) );
   Image22->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light11_OFF",  "Default Caption" ) );
   Image24->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light12_OFF",  "Default Caption" ) );
   Image25->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light13_OFF",  "Default Caption" ) );
   Image28->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light14_OFF",  "Default Caption" ) );
   Image29->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light15_OFF",  "Default Caption" ) );
   Image32->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light16_OFF",  "Default Caption" ) );

   Image34->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light17_OFF",  "Default Caption" ) );
   Image35->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light18_OFF",  "Default Caption" ) );
   Image38->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light19_OFF",  "Default Caption" ) );
   Image40->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light20_OFF",  "Default Caption" ) );
   Image41->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light21_OFF",  "Default Caption" ) );
   Image44->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light22_OFF",  "Default Caption" ) );
   Image45->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light23_OFF",  "Default Caption" ) );
   Image48->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light24_OFF",  "Default Caption" ) );

   Image50->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light25_OFF",  "Default Caption" ) );
   Image51->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light26_OFF",  "Default Caption" ) );
   Image54->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light27_OFF",  "Default Caption" ) );
   Image55->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light28_OFF",  "Default Caption" ) );
   Image58->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light29_OFF",  "Default Caption" ) );
   Image59->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light30_OFF",  "Default Caption" ) );
   Image62->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light31_OFF",  "Default Caption" ) );
   Image63->Picture->LoadFromFile(ini->ReadString( "Device_ICO", "Light32_OFF",  "Default Caption" ) );


   delete ini;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image1->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light1_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button11Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image9->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light1_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button4Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image2->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light2_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image3->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light3_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button6Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image4->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light4_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button7Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image5->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light5_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button8Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image6->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light6_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button9Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image7->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light7_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button10Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image8->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light8_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image17->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light9_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button19Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image20->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light10_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button21Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image21->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light11_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button23Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image23->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light12_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button25Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image26->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light13_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button27Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image27->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light14_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button29Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image30->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light15_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button31Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image31->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light16_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button33Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image33->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light17_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button35Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image36->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light18_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button37Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image37->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light19_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button39Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image39->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light20_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button41Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image42->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light21_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button43Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image43->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light22_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button45Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image46->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light23_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button47Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image47->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light24_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button49Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image49->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light25_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button51Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image52->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light26_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button53Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image53->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light27_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button55Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image56->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light28_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button57Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image57->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light29_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button59Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image60->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light30_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button61Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image61->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light31_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button63Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image64->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light32_ON", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button12Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image10->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light2_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button13Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image11->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light3_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button14Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image12->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light4_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button15Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image13->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light5_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button16Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image14->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light6_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button17Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image15->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light7_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button18Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image16->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light8_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image18->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light9_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button20Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image19->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light10_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button22Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image22->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light11_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button24Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image24->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light12_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button26Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image25->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light13_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button28Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image28->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light14_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button30Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image29->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light15_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button32Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image32->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light16_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button34Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image34->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light17_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button36Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image35->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light18_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button38Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image38->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light19_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button40Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image40->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light20_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button42Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image41->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light21_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button44Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image44->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light22_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button46Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image45->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light23_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button48Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image48->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light24_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button50Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image50->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light25_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button52Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image51->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light26_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button54Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image54->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light27_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button56Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image55->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light28_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button58Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image58->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light29_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button60Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image59->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light30_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button62Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image62->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light31_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button64Click(TObject *Sender)
{
	  TIniFile *ini;
if (OpenDialog1->Execute())
 {
   Image63->Picture->LoadFromFile(OpenDialog1->FileName);

   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
   ini->WriteString ( "Device_ICO", "Light32_OFF", OpenDialog1->FileName );
   delete ini;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button65Click(TObject *Sender)
{
   TIniFile *ini;
   ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );


   ini->WriteString ( "NetWork_Config", "SN", Edit33->Text );   //保存设备序列号

   ini->WriteString ( "Device_Config", "Light1", Edit1->Text );
   ini->WriteString ( "Device_Config", "Light2", Edit2->Text );
   ini->WriteString ( "Device_Config", "Light3", Edit3->Text );
   ini->WriteString ( "Device_Config", "Light4", Edit4->Text );
   ini->WriteString ( "Device_Config", "Light5", Edit5->Text );
   ini->WriteString ( "Device_Config", "Light6", Edit6->Text );
   ini->WriteString ( "Device_Config", "Light7", Edit7->Text );
   ini->WriteString ( "Device_Config", "Light8", Edit8->Text );
   ini->WriteString ( "Device_Config", "Light9", Edit9->Text );
   ini->WriteString ( "Device_Config", "Light10", Edit10->Text );
   ini->WriteString ( "Device_Config", "Light11", Edit11->Text );
   ini->WriteString ( "Device_Config", "Light12", Edit12->Text );
   ini->WriteString ( "Device_Config", "Light13", Edit13->Text );
   ini->WriteString ( "Device_Config", "Light14", Edit14->Text );
   ini->WriteString ( "Device_Config", "Light15", Edit15->Text );
   ini->WriteString ( "Device_Config", "Light16", Edit16->Text );
   ini->WriteString ( "Device_Config", "Light17", Edit17->Text );
   ini->WriteString ( "Device_Config", "Light18", Edit18->Text );
   ini->WriteString ( "Device_Config", "Light19", Edit19->Text );
   ini->WriteString ( "Device_Config", "Light20", Edit20->Text );
   ini->WriteString ( "Device_Config", "Light21", Edit21->Text );
   ini->WriteString ( "Device_Config", "Light22", Edit22->Text );
   ini->WriteString ( "Device_Config", "Light23", Edit23->Text );
   ini->WriteString ( "Device_Config", "Light24", Edit24->Text );
   ini->WriteString ( "Device_Config", "Light25", Edit25->Text );
   ini->WriteString ( "Device_Config", "Light26", Edit26->Text );
   ini->WriteString ( "Device_Config", "Light27", Edit27->Text );
   ini->WriteString ( "Device_Config", "Light28", Edit28->Text );
   ini->WriteString ( "Device_Config", "Light29", Edit29->Text );
   ini->WriteString ( "Device_Config", "Light30", Edit30->Text );
   ini->WriteString ( "Device_Config", "Light31", Edit31->Text );
   ini->WriteString ( "Device_Config", "Light32", Edit32->Text );

   delete ini;
   Close();
}
//---------------------------------------------------------------------------
