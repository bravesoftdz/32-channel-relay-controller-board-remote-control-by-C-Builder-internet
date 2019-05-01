//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include <inifiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString light_img_1_ON,light_img_2_ON,light_img_3_ON,light_img_4_ON,light_img_5_ON,light_img_6_ON,light_img_7_ON,light_img_8_ON;
AnsiString light_img_9_ON,light_img_10_ON,light_img_11_ON,light_img_12_ON,light_img_13_ON,light_img_14_ON,light_img_15_ON,light_img_16_ON;
AnsiString light_img_17_ON,light_img_18_ON,light_img_19_ON,light_img_20_ON,light_img_21_ON,light_img_22_ON,light_img_23_ON,light_img_24_ON;
AnsiString light_img_25_ON,light_img_26_ON,light_img_27_ON,light_img_28_ON,light_img_29_ON,light_img_30_ON,light_img_31_ON,light_img_32_ON;

AnsiString light_img_1_OFF,light_img_2_OFF,light_img_3_OFF,light_img_4_OFF,light_img_5_OFF,light_img_6_OFF,light_img_7_OFF,light_img_8_OFF;
AnsiString light_img_9_OFF,light_img_10_OFF,light_img_11_OFF,light_img_12_OFF,light_img_13_OFF,light_img_14_OFF,light_img_15_OFF,light_img_16_OFF;
AnsiString light_img_17_OFF,light_img_18_OFF,light_img_19_OFF,light_img_20_OFF,light_img_21_OFF,light_img_22_OFF,light_img_23_OFF,light_img_24_OFF;
AnsiString light_img_25_OFF,light_img_26_OFF,light_img_27_OFF,light_img_28_OFF,light_img_29_OFF,light_img_30_OFF,light_img_31_OFF,light_img_32_OFF;


AnsiString SN;


int time_i=1;  //�������������������255���Զ����ص�1

////INDY HTTP CLIENT Get���� ����
String  GetData(String url,String data)
{
	 TIdHTTP *IdHttp1;
	 try{
			 IdHttp1=new TIdHTTP(Application);
			IdHttp1->Request->ContentType="application/x-www-form-urlencoded";
			if(IdHttp1==NULL)
			 {
				return "";
			 }

			AnsiString Url=url+"?"+data;
			String str =IdHttp1->Get(Url);
			delete   IdHttp1;
			return  str;
	 }
	 catch(Exception &e)
		{
		 if(IdHttp1!=NULL)
			delete IdHttp1;
			return "";
		 }

}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
   AnsiString send_buf,SN,data,Substr,temp,str,str1,str2,str3,str4;
   int i=0;
   int pos,Relay_state1,Relay_state2,Relay_state3,Relay_state4;

   TIniFile *ini;
   ini = new TIniFile( ChangeFileExt( Application->ExeName, ".INI" ) );
//   ini = new TIniFile( "c:\Net_Relay_Control.INI" );

//------------------------------�����������������Ϣ---------------------------
   Label1->Caption = ini->ReadString( "Device_Config", "Light1",  "Light1" ) ;
   Label2->Caption = ini->ReadString( "Device_Config", "Light2",  "Light2" ) ;
   Label3->Caption = ini->ReadString( "Device_Config", "Light3",  "Light3" ) ;
   Label4->Caption = ini->ReadString( "Device_Config", "Light4",  "Light4" ) ;
   Label5->Caption = ini->ReadString( "Device_Config", "Light5",  "Light5" ) ;
   Label6->Caption = ini->ReadString( "Device_Config", "Light6",  "Light6" ) ;
   Label7->Caption = ini->ReadString( "Device_Config", "Light7",  "Light7" ) ;
   Label8->Caption = ini->ReadString( "Device_Config", "Light8",  "Light8" ) ;

   Label9->Caption = ini->ReadString( "Device_Config", "Light9",  "Light9" ) ;
   Label10->Caption = ini->ReadString( "Device_Config", "Light10",  "Light10" ) ;
   Label11->Caption = ini->ReadString( "Device_Config", "Light11",  "Light11" ) ;
   Label12->Caption = ini->ReadString( "Device_Config", "Light12",  "Light12" ) ;
   Label13->Caption = ini->ReadString( "Device_Config", "Light13",  "Light13" ) ;
   Label14->Caption = ini->ReadString( "Device_Config", "Light14",  "Light14" ) ;
   Label15->Caption = ini->ReadString( "Device_Config", "Light15",  "Light15" ) ;
   Label16->Caption = ini->ReadString( "Device_Config", "Light16",  "Light16" ) ;

   Label17->Caption = ini->ReadString( "Device_Config", "Light17",  "Light17" ) ;
   Label18->Caption = ini->ReadString( "Device_Config", "Light18",  "Light18" ) ;
   Label19->Caption = ini->ReadString( "Device_Config", "Light19",  "Light19" ) ;
   Label20->Caption = ini->ReadString( "Device_Config", "Light20",  "Light20" ) ;
   Label21->Caption = ini->ReadString( "Device_Config", "Light21",  "Light21" ) ;
   Label22->Caption = ini->ReadString( "Device_Config", "Light22",  "Light22" ) ;
   Label23->Caption = ini->ReadString( "Device_Config", "Light23",  "Light23" ) ;
   Label24->Caption = ini->ReadString( "Device_Config", "Light24",  "Light24" ) ;

   Label25->Caption = ini->ReadString( "Device_Config", "Light25",  "Light25" ) ;
   Label26->Caption = ini->ReadString( "Device_Config", "Light26",  "Light26" ) ;
   Label27->Caption = ini->ReadString( "Device_Config", "Light27",  "Light27" ) ;
   Label28->Caption = ini->ReadString( "Device_Config", "Light28",  "Light28" ) ;
   Label29->Caption = ini->ReadString( "Device_Config", "Light29",  "Light29" ) ;
   Label30->Caption = ini->ReadString( "Device_Config", "Light30",  "Light30" ) ;
   Label31->Caption = ini->ReadString( "Device_Config", "Light31",  "Light31" ) ;
   Label32->Caption = ini->ReadString( "Device_Config", "Light32",  "Light32" ) ;

   SN=ini->ReadString( "NetWork_Config", "SN",  "" ) ;

   light_img_1_ON= ini->ReadString( "Device_ICO", "Light1_ON",  "light_50pix.png" ) ;
   light_img_2_ON= ini->ReadString( "Device_ICO", "Light2_ON",  "light_50pix.png" ) ;
   light_img_3_ON= ini->ReadString( "Device_ICO", "Light3_ON",  "light_50pix.png" ) ;
   light_img_4_ON= ini->ReadString( "Device_ICO", "Light4_ON",  "light_50pix.png" ) ;
   light_img_5_ON= ini->ReadString( "Device_ICO", "Light5_ON",  "light_50pix.png" ) ;
   light_img_6_ON= ini->ReadString( "Device_ICO", "Light6_ON",  "light_50pix.png" ) ;
   light_img_7_ON= ini->ReadString( "Device_ICO", "Light7_ON",  "light_50pix.png" ) ;
   light_img_8_ON= ini->ReadString( "Device_ICO", "Light8_ON",  "light_50pix.png" ) ;

   light_img_9_ON= ini->ReadString( "Device_ICO", "Light9_ON",  "light_50pix.png" ) ;
   light_img_10_ON= ini->ReadString( "Device_ICO", "Light10_ON",  "light_50pix.png" ) ;
   light_img_11_ON= ini->ReadString( "Device_ICO", "Light11_ON",  "light_50pix.png" ) ;
   light_img_12_ON= ini->ReadString( "Device_ICO", "Light12_ON",  "light_50pix.png" ) ;
   light_img_13_ON= ini->ReadString( "Device_ICO", "Light13_ON",  "light_50pix.png" ) ;
   light_img_14_ON= ini->ReadString( "Device_ICO", "Light14_ON",  "light_50pix.png" ) ;
   light_img_15_ON= ini->ReadString( "Device_ICO", "Light15_ON",  "light_50pix.png" ) ;
   light_img_16_ON= ini->ReadString( "Device_ICO", "Light16_ON",  "light_50pix.png" ) ;

   light_img_17_ON= ini->ReadString( "Device_ICO", "Light17_ON",  "light_50pix.png" ) ;
   light_img_18_ON= ini->ReadString( "Device_ICO", "Light18_ON",  "light_50pix.png" ) ;
   light_img_19_ON= ini->ReadString( "Device_ICO", "Light19_ON",  "light_50pix.png" ) ;
   light_img_20_ON= ini->ReadString( "Device_ICO", "Light20_ON",  "light_50pix.png" ) ;
   light_img_21_ON= ini->ReadString( "Device_ICO", "Light21_ON",  "light_50pix.png" ) ;
   light_img_22_ON= ini->ReadString( "Device_ICO", "Light22_ON",  "light_50pix.png" ) ;
   light_img_23_ON= ini->ReadString( "Device_ICO", "Light23_ON",  "light_50pix.png" ) ;
   light_img_24_ON= ini->ReadString( "Device_ICO", "Light24_ON",  "light_50pix.png" ) ;

   light_img_25_ON= ini->ReadString( "Device_ICO", "Light25_ON",  "light_50pix.png" ) ;
   light_img_26_ON= ini->ReadString( "Device_ICO", "Light26_ON",  "light_50pix.png" ) ;
   light_img_27_ON= ini->ReadString( "Device_ICO", "Light27_ON",  "light_50pix.png" ) ;
   light_img_28_ON= ini->ReadString( "Device_ICO", "Light28_ON",  "light_50pix.png" ) ;
   light_img_29_ON= ini->ReadString( "Device_ICO", "Light29_ON",  "light_50pix.png" ) ;
   light_img_30_ON= ini->ReadString( "Device_ICO", "Light30_ON",  "light_50pix.png" ) ;
   light_img_31_ON= ini->ReadString( "Device_ICO", "Light31_ON",  "light_50pix.png" ) ;
   light_img_32_ON= ini->ReadString( "Device_ICO", "Light32_ON",  "light_50pix.png" ) ;

   light_img_1_OFF= ini->ReadString( "Device_ICO", "Light1_OFF",  "off_light_50pix.png" ) ;
   light_img_2_OFF= ini->ReadString( "Device_ICO", "Light2_OFF",  "off_light_50pix.png" ) ;
   light_img_3_OFF= ini->ReadString( "Device_ICO", "Light3_OFF",  "off_light_50pix.png" ) ;
   light_img_4_OFF= ini->ReadString( "Device_ICO", "Light4_OFF",  "off_light_50pix.png" ) ;
   light_img_5_OFF= ini->ReadString( "Device_ICO", "Light5_OFF",  "off_light_50pix.png" ) ;
   light_img_6_OFF= ini->ReadString( "Device_ICO", "Light6_OFF",  "off_light_50pix.png" ) ;
   light_img_7_OFF= ini->ReadString( "Device_ICO", "Light7_OFF",  "off_light_50pix.png" ) ;
   light_img_8_OFF= ini->ReadString( "Device_ICO", "Light8_OFF",  "off_light_50pix.png" ) ;

   light_img_9_OFF= ini->ReadString( "Device_ICO", "Light9_OFF",  "light_50pix.png" ) ;
   light_img_10_OFF= ini->ReadString( "Device_ICO", "Light10_OFF",  "light_50pix.png" ) ;
   light_img_11_OFF= ini->ReadString( "Device_ICO", "Light11_OFF",  "light_50pix.png" ) ;
   light_img_12_OFF= ini->ReadString( "Device_ICO", "Light12_OFF",  "light_50pix.png" ) ;
   light_img_13_OFF= ini->ReadString( "Device_ICO", "Light13_OFF",  "light_50pix.png" ) ;
   light_img_14_OFF= ini->ReadString( "Device_ICO", "Light14_OFF",  "light_50pix.png" ) ;
   light_img_15_OFF= ini->ReadString( "Device_ICO", "Light15_OFF",  "light_50pix.png" ) ;
   light_img_16_OFF= ini->ReadString( "Device_ICO", "Light16_OFF",  "light_50pix.png" ) ;

   light_img_17_OFF= ini->ReadString( "Device_ICO", "Light17_OFF",  "light_50pix.png" ) ;
   light_img_18_OFF= ini->ReadString( "Device_ICO", "Light18_OFF",  "light_50pix.png" ) ;
   light_img_19_OFF= ini->ReadString( "Device_ICO", "Light19_OFF",  "light_50pix.png" ) ;
   light_img_20_OFF= ini->ReadString( "Device_ICO", "Light20_OFF",  "light_50pix.png" ) ;
   light_img_21_OFF= ini->ReadString( "Device_ICO", "Light21_OFF",  "light_50pix.png" ) ;
   light_img_22_OFF= ini->ReadString( "Device_ICO", "Light22_OFF",  "light_50pix.png" ) ;
   light_img_23_OFF= ini->ReadString( "Device_ICO", "Light23_OFF",  "light_50pix.png" ) ;
   light_img_24_OFF= ini->ReadString( "Device_ICO", "Light24_OFF",  "light_50pix.png" ) ;

   light_img_25_OFF= ini->ReadString( "Device_ICO", "Light25_OFF",  "light_50pix.png" ) ;
   light_img_26_OFF= ini->ReadString( "Device_ICO", "Light26_OFF",  "light_50pix.png" ) ;
   light_img_27_OFF= ini->ReadString( "Device_ICO", "Light27_OFF",  "light_50pix.png" ) ;
   light_img_28_OFF= ini->ReadString( "Device_ICO", "Light28_OFF",  "light_50pix.png" ) ;
   light_img_29_OFF= ini->ReadString( "Device_ICO", "Light29_OFF",  "light_50pix.png" ) ;
   light_img_30_OFF= ini->ReadString( "Device_ICO", "Light30_OFF",  "light_50pix.png" ) ;
   light_img_31_OFF= ini->ReadString( "Device_ICO", "Light31_OFF",  "light_50pix.png" ) ;
   light_img_32_OFF= ini->ReadString( "Device_ICO", "Light32_OFF",  "light_50pix.png" ) ;

 //--------------------------------------------------------------------------------------

	 if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }

  if (time_i<10) { i=1;      //������Ϊ1λ��

  }else if (i<100) {i=2;     //������Ϊ2λ��

		}
		else i=3;            //������Ϊ3λ��


  send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��ѯ32·���صĵ�ǰ״̬
  data = "deviceCode=" + SN + "&command=RELAY-STATE-" + IntToStr(time_i);

  String strResponse = GetData(send_buf, data);
  //{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,15,16,17,18,OK\u0000","status":"0"}
  //SubstrΪ{"message":"Command: RELAY-STATE-5 was sent to device: 56a890e6888793c97ed33f17 successfully.","result":"RELAY-STATE-5,
  Substr=AnsiString(strResponse).SubString(1,117+i*2);
  temp="{\"message\":\"Command: RELAY-STATE-"+IntToStr(time_i)+" was sent to device: "+SN+" successfully.\",\"result\":\"RELAY-STATE-"+IntToStr(time_i)+",";
  //ShowMessage(strResponse);


  if (Substr==temp) {   //��ȡ���˵�ǰ״̬���ַ���
	 str=strResponse.SubString(117+i*2+1,strResponse.Length()-117+i*2 ); //ȡ��  15,16,17,18,OK\u0000","status":"0"
	 pos=str.Pos(",");  //�ҳ����ŵ�λ��
	 str1=AnsiString(str).SubString(1,pos-1); //ȡ���̵���״ֵ̬     15  25-32·״̬
	 Relay_state1=StrToInt(str1);       //15

	 str= AnsiString(str).SubString(pos+1,str.Length()-pos);    //ȡ��   16,17,18,OK\u0000","status":"0"
	 pos=str.Pos(",");  //�ҳ����ŵ�λ��
	 str2=AnsiString(str).SubString(1,pos-1); //ȡ���̵���״ֵ̬     16   17-24·״̬
	 Relay_state2=StrToInt(str2);       //16

	 str= AnsiString(str).SubString(pos+1,str.Length()-pos);    //ȡ��   17,18,OK\u0000","status":"0"
	 pos=str.Pos(",");  //�ҳ����ŵ�λ��
	 str3=AnsiString(str).SubString(1,pos-1); //ȡ���̵���״ֵ̬     17     9-16·״̬
	 Relay_state3=StrToInt(str3);       //17

	 str= AnsiString(str).SubString(pos+1,str.Length()-pos);    //ȡ��   18,OK\u0000","status":"0"
	 pos=str.Pos(",");  //�ҳ����ŵ�λ��
	 str4=AnsiString(str).SubString(1,pos-1); //ȡ���̵���״ֵ̬     18     1-8·״̬
	 Relay_state4=StrToInt(str4);       //18


	 if ((Relay_state4&0x01)==0x01) Image1->Picture ->LoadFromFile(light_img_1_ON);    //��1·�̵���״̬ʵʱ��ʾ
		 else Image1->Picture ->LoadFromFile(light_img_1_OFF);
	 if ((Relay_state4&0x02)==0x02) Image2->Picture ->LoadFromFile(light_img_2_ON);    //��2·�̵���״̬ʵʱ��ʾ
		 else Image2->Picture ->LoadFromFile(light_img_2_OFF);
	 if ((Relay_state4&0x04)==0x04) Image3->Picture ->LoadFromFile(light_img_3_ON);    //��3·�̵���״̬ʵʱ��ʾ
		 else Image3->Picture ->LoadFromFile(light_img_3_OFF);
	 if ((Relay_state4&0x08)==0x08) Image4->Picture ->LoadFromFile(light_img_4_ON);    //��4·�̵���״̬ʵʱ��ʾ
		 else Image4->Picture ->LoadFromFile(light_img_4_OFF);
	 if ((Relay_state4&0x10)==0x10) Image5->Picture ->LoadFromFile(light_img_5_ON);    //��5·�̵���״̬ʵʱ��ʾ
		 else Image5->Picture ->LoadFromFile(light_img_5_OFF);
	 if ((Relay_state4&0x20)==0x20) Image6->Picture ->LoadFromFile(light_img_6_ON);   //��6·�̵���״̬ʵʱ��ʾ
		 else Image6->Picture ->LoadFromFile(light_img_6_OFF);
	 if ((Relay_state4&0x40)==0x40) Image7->Picture ->LoadFromFile(light_img_7_ON);    //��7·�̵���״̬ʵʱ��ʾ
		 else Image7->Picture ->LoadFromFile(light_img_7_OFF);
	 if ((Relay_state4&0x80)==0x80) Image8->Picture ->LoadFromFile(light_img_8_ON);   //��8·�̵���״̬ʵʱ��ʾ
		 else Image8->Picture ->LoadFromFile(light_img_8_OFF);


	 if ((Relay_state3&0x01)==0x01) Image9->Picture ->LoadFromFile(light_img_9_ON);    //��9·�̵���״̬ʵʱ��ʾ
		 else Image9->Picture ->LoadFromFile(light_img_9_OFF);
	 if ((Relay_state3&0x02)==0x02) Image10->Picture ->LoadFromFile(light_img_10_ON);    //��10·�̵���״̬ʵʱ��ʾ
		 else Image10->Picture ->LoadFromFile(light_img_10_OFF);
	 if ((Relay_state3&0x04)==0x04) Image11->Picture ->LoadFromFile(light_img_11_ON);    //��11·�̵���״̬ʵʱ��ʾ
		 else Image11->Picture ->LoadFromFile(light_img_11_OFF);
	 if ((Relay_state3&0x08)==0x08) Image12->Picture ->LoadFromFile(light_img_12_ON);    //��12·�̵���״̬ʵʱ��ʾ
		 else Image12->Picture ->LoadFromFile(light_img_12_OFF);
	 if ((Relay_state3&0x10)==0x10) Image13->Picture ->LoadFromFile(light_img_13_ON);    //��13·�̵���״̬ʵʱ��ʾ
		 else Image13->Picture ->LoadFromFile(light_img_13_OFF);
	 if ((Relay_state3&0x20)==0x20) Image14->Picture ->LoadFromFile(light_img_14_ON);   //��14·�̵���״̬ʵʱ��ʾ
		 else Image14->Picture ->LoadFromFile(light_img_14_OFF);
	 if ((Relay_state3&0x40)==0x40) Image15->Picture ->LoadFromFile(light_img_15_ON);    //��15·�̵���״̬ʵʱ��ʾ
		 else Image15->Picture ->LoadFromFile(light_img_15_OFF);
	 if ((Relay_state3&0x80)==0x80) Image16->Picture ->LoadFromFile(light_img_16_ON);   //��16·�̵���״̬ʵʱ��ʾ
		 else Image16->Picture ->LoadFromFile(light_img_16_OFF);

	 if ((Relay_state2&0x01)==0x01) Image17->Picture ->LoadFromFile(light_img_17_ON);    //��17·�̵���״̬ʵʱ��ʾ
		 else Image17->Picture ->LoadFromFile(light_img_17_OFF);
	 if ((Relay_state2&0x02)==0x02) Image18->Picture ->LoadFromFile(light_img_18_ON);    //��18·�̵���״̬ʵʱ��ʾ
		 else Image18->Picture ->LoadFromFile(light_img_18_OFF);
	 if ((Relay_state2&0x04)==0x04) Image19->Picture ->LoadFromFile(light_img_19_ON);    //��19·�̵���״̬ʵʱ��ʾ
		 else Image19->Picture ->LoadFromFile(light_img_19_OFF);
	 if ((Relay_state2&0x08)==0x08) Image20->Picture ->LoadFromFile(light_img_20_ON);    //��20·�̵���״̬ʵʱ��ʾ
		 else Image20->Picture ->LoadFromFile(light_img_20_OFF);
	 if ((Relay_state2&0x10)==0x10) Image21->Picture ->LoadFromFile(light_img_21_ON);    //��21·�̵���״̬ʵʱ��ʾ
		 else Image21->Picture ->LoadFromFile(light_img_21_OFF);
	 if ((Relay_state2&0x20)==0x20) Image22->Picture ->LoadFromFile(light_img_22_ON);   //��22·�̵���״̬ʵʱ��ʾ
		 else Image22->Picture ->LoadFromFile(light_img_22_OFF);
	 if ((Relay_state2&0x40)==0x40) Image23->Picture ->LoadFromFile(light_img_23_ON);    //��23·�̵���״̬ʵʱ��ʾ
		 else Image23->Picture ->LoadFromFile(light_img_23_OFF);
	 if ((Relay_state2&0x80)==0x80) Image24->Picture ->LoadFromFile(light_img_24_ON);   //��24·�̵���״̬ʵʱ��ʾ
		 else Image24->Picture ->LoadFromFile(light_img_24_OFF);

	 if ((Relay_state1&0x01)==0x01) Image25->Picture ->LoadFromFile(light_img_25_ON);    //��25·�̵���״̬ʵʱ��ʾ
		 else Image25->Picture ->LoadFromFile(light_img_25_OFF);
	 if ((Relay_state1&0x02)==0x02) Image26->Picture ->LoadFromFile(light_img_26_ON);    //��26·�̵���״̬ʵʱ��ʾ
		 else Image26->Picture ->LoadFromFile(light_img_26_OFF);
	 if ((Relay_state1&0x04)==0x04) Image27->Picture ->LoadFromFile(light_img_27_ON);    //��27·�̵���״̬ʵʱ��ʾ
		 else Image27->Picture ->LoadFromFile(light_img_27_OFF);
	 if ((Relay_state1&0x08)==0x08) Image28->Picture ->LoadFromFile(light_img_28_ON);    //��28·�̵���״̬ʵʱ��ʾ
		 else Image28->Picture ->LoadFromFile(light_img_28_OFF);
	 if ((Relay_state1&0x10)==0x10) Image29->Picture ->LoadFromFile(light_img_29_ON);    //��29·�̵���״̬ʵʱ��ʾ
		 else Image29->Picture ->LoadFromFile(light_img_29_OFF);
	 if ((Relay_state1&0x20)==0x20) Image30->Picture ->LoadFromFile(light_img_30_ON);   //��30·�̵���״̬ʵʱ��ʾ
		 else Image30->Picture ->LoadFromFile(light_img_30_OFF);
	 if ((Relay_state1&0x40)==0x40) Image31->Picture ->LoadFromFile(light_img_31_ON);    //��31·�̵���״̬ʵʱ��ʾ
		 else Image31->Picture ->LoadFromFile(light_img_31_OFF);
	 if ((Relay_state1&0x80)==0x80) Image32->Picture ->LoadFromFile(light_img_32_ON);   //��32·�̵���״̬ʵʱ��ʾ
		 else Image32->Picture ->LoadFromFile(light_img_32_OFF);

  }



   delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Exit1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::config1Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��1·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",1,1";
   String strResponse = GetData(send_buf, data);

   Image1->Picture ->LoadFromFile(light_img_1_ON);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��1·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",1,0";
   String strResponse = GetData(send_buf, data);

   Image1->Picture ->LoadFromFile(light_img_1_OFF);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Style11Click(TObject *Sender)
{
  TStyleManager::SetStyle("Sky");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Style21Click(TObject *Sender)
{
 TStyleManager::SetStyle("GLow");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
/*TStyleManager::LoadFromFile("Sky.vsf");
TStyleManager::LoadFromFile("Glow.vsf");
TStyleManager::LoadFromFile("Silver.vsf");    */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Style31Click(TObject *Sender)
{
  TStyleManager::SetStyle("Silver");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Style41Click(TObject *Sender)
{
  TStyleManager::SetStyle("Carbon");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button63Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��32·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",32,1";
   String strResponse = GetData(send_buf, data);

   Image32->Picture ->LoadFromFile(light_img_32_ON);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button64Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��32·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",32,0";
   String strResponse = GetData(send_buf, data);

   Image32->Picture ->LoadFromFile(light_img_32_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��2·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",2,1";
   String strResponse = GetData(send_buf, data);

   Image2->Picture ->LoadFromFile(light_img_2_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��3·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",3,1";
   String strResponse = GetData(send_buf, data);

   Image3->Picture ->LoadFromFile(light_img_3_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��4·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",4,1";
   String strResponse = GetData(send_buf, data);

   Image4->Picture ->LoadFromFile(light_img_4_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��5·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",5,1";
   String strResponse = GetData(send_buf, data);

   Image5->Picture ->LoadFromFile(light_img_5_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��6·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",6,1";
   String strResponse = GetData(send_buf, data);

   Image6->Picture ->LoadFromFile(light_img_6_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��7·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",7,1";
   String strResponse = GetData(send_buf, data);

   Image7->Picture ->LoadFromFile(light_img_7_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��9·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",9,1";
   String strResponse = GetData(send_buf, data);

   Image9->Picture ->LoadFromFile(light_img_9_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��10·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",10,1";
   String strResponse = GetData(send_buf, data);

   Image10->Picture ->LoadFromFile(light_img_10_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��8·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",8,1";
   String strResponse = GetData(send_buf, data);

   Image8->Picture ->LoadFromFile(light_img_8_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��11·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",11,1";
   String strResponse = GetData(send_buf, data);

   Image11->Picture ->LoadFromFile(light_img_11_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��12·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",12,1";
   String strResponse = GetData(send_buf, data);

   Image12->Picture ->LoadFromFile(light_img_12_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button25Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��13·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",13,1";
   String strResponse = GetData(send_buf, data);

   Image13->Picture ->LoadFromFile(light_img_13_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button27Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��14·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",14,1";
   String strResponse = GetData(send_buf, data);

   Image14->Picture ->LoadFromFile(light_img_14_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button29Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��15·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",15,1";
   String strResponse = GetData(send_buf, data);

   Image15->Picture ->LoadFromFile(light_img_15_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button31Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��16·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",16,1";
   String strResponse = GetData(send_buf, data);

   Image16->Picture ->LoadFromFile(light_img_16_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button33Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��17·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",17,1";
   String strResponse = GetData(send_buf, data);

   Image17->Picture ->LoadFromFile(light_img_17_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button35Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��18·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",18,1";
   String strResponse = GetData(send_buf, data);

   Image18->Picture ->LoadFromFile(light_img_18_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button37Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��19·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",19,1";
   String strResponse = GetData(send_buf, data);

   Image19->Picture ->LoadFromFile(light_img_19_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button39Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��20·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",20,1";
   String strResponse = GetData(send_buf, data);

   Image20->Picture ->LoadFromFile(light_img_20_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button41Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��21·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",21,1";
   String strResponse = GetData(send_buf, data);

   Image21->Picture ->LoadFromFile(light_img_21_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button43Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��22·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",22,1";
   String strResponse = GetData(send_buf, data);

   Image22->Picture ->LoadFromFile(light_img_22_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button45Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��23·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",23,1";
   String strResponse = GetData(send_buf, data);

   Image23->Picture ->LoadFromFile(light_img_23_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button47Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��24·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",24,1";
   String strResponse = GetData(send_buf, data);

   Image24->Picture ->LoadFromFile(light_img_24_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button49Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��25·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",25,1";
   String strResponse = GetData(send_buf, data);

   Image25->Picture ->LoadFromFile(light_img_25_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button51Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��26·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",26,1";
   String strResponse = GetData(send_buf, data);

   Image26->Picture ->LoadFromFile(light_img_26_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button53Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��27·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",27,1";
   String strResponse = GetData(send_buf, data);

   Image27->Picture ->LoadFromFile(light_img_27_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button55Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��28·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",28,1";
   String strResponse = GetData(send_buf, data);

   Image28->Picture ->LoadFromFile(light_img_28_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button57Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��29·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",29,1";
   String strResponse = GetData(send_buf, data);

   Image29->Picture ->LoadFromFile(light_img_29_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button59Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��30·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",30,1";
   String strResponse = GetData(send_buf, data);

   Image30->Picture ->LoadFromFile(light_img_30_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button61Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��31·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",31,1";
   String strResponse = GetData(send_buf, data);

   Image31->Picture ->LoadFromFile(light_img_31_ON);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��2·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",2,0";
   String strResponse = GetData(send_buf, data);

   Image2->Picture ->LoadFromFile(light_img_2_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��3·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",3,0";
   String strResponse = GetData(send_buf, data);

   Image3->Picture ->LoadFromFile(light_img_3_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��4·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",4,0";
   String strResponse = GetData(send_buf, data);

   Image4->Picture ->LoadFromFile(light_img_4_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��5·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",5,0";
   String strResponse = GetData(send_buf, data);

   Image5->Picture ->LoadFromFile(light_img_5_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��6·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",6,0";
   String strResponse = GetData(send_buf, data);

   Image6->Picture ->LoadFromFile(light_img_6_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��7·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",7,0";
   String strResponse = GetData(send_buf, data);

   Image7->Picture ->LoadFromFile(light_img_7_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��8·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",8,0";
   String strResponse = GetData(send_buf, data);

   Image8->Picture ->LoadFromFile(light_img_8_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��9·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",9,0";
   String strResponse = GetData(send_buf, data);

   Image9->Picture ->LoadFromFile(light_img_9_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��10·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",10,0";
   String strResponse = GetData(send_buf, data);

   Image10->Picture ->LoadFromFile(light_img_10_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button22Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��11·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",11,0";
   String strResponse = GetData(send_buf, data);

   Image11->Picture ->LoadFromFile(light_img_11_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button24Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��12·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",12,0";
   String strResponse = GetData(send_buf, data);

   Image12->Picture ->LoadFromFile(light_img_12_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button26Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��13·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",13,0";
   String strResponse = GetData(send_buf, data);

   Image13->Picture ->LoadFromFile(light_img_13_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button28Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��14·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",14,0";
   String strResponse = GetData(send_buf, data);

   Image14->Picture ->LoadFromFile(light_img_14_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button30Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��15·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",15,0";
   String strResponse = GetData(send_buf, data);

   Image15->Picture ->LoadFromFile(light_img_15_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button32Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��16·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",16,0";
   String strResponse = GetData(send_buf, data);

   Image16->Picture ->LoadFromFile(light_img_16_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button34Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��17·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",17,0";
   String strResponse = GetData(send_buf, data);

   Image17->Picture ->LoadFromFile(light_img_17_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button36Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��18·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",18,0";
   String strResponse = GetData(send_buf, data);

   Image18->Picture ->LoadFromFile(light_img_18_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button38Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��19·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",19,0";
   String strResponse = GetData(send_buf, data);

   Image19->Picture ->LoadFromFile(light_img_19_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button40Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��20·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",20,0";
   String strResponse = GetData(send_buf, data);

   Image20->Picture ->LoadFromFile(light_img_20_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button42Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��21·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",21,0";
   String strResponse = GetData(send_buf, data);

   Image21->Picture ->LoadFromFile(light_img_21_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button44Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��22·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",22,0";
   String strResponse = GetData(send_buf, data);

   Image22->Picture ->LoadFromFile(light_img_22_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button46Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��23·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",23,0";
   String strResponse = GetData(send_buf, data);

   Image23->Picture ->LoadFromFile(light_img_23_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button48Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��24·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",24,0";
   String strResponse = GetData(send_buf, data);

   Image24->Picture ->LoadFromFile(light_img_24_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button50Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��25·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",25,0";
   String strResponse = GetData(send_buf, data);

   Image25->Picture ->LoadFromFile(light_img_25_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button52Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��26·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",26,0";
   String strResponse = GetData(send_buf, data);

   Image26->Picture ->LoadFromFile(light_img_26_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button54Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��27·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",27,0";
   String strResponse = GetData(send_buf, data);

   Image27->Picture ->LoadFromFile(light_img_27_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button56Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��28·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",28,0";
   String strResponse = GetData(send_buf, data);

   Image28->Picture ->LoadFromFile(light_img_28_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button58Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��29·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",29,0";
   String strResponse = GetData(send_buf, data);

   Image29->Picture ->LoadFromFile(light_img_29_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button60Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��30·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",30,0";
   String strResponse = GetData(send_buf, data);

   Image30->Picture ->LoadFromFile(light_img_30_OFF);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button62Click(TObject *Sender)
{
  AnsiString send_buf,SN,data;

  SN=Form2->Edit33->Text;

   if (time_i==255)
	 {
	   time_i=1;
	 }
   else
	 {
	   time_i++;
	 }


   send_buf="http://voice.hificat.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action";  //��31·�̵�����
   data = "deviceCode=" + SN + "&command=RELAY-SET-" + IntToStr(time_i)+",31,0";
   String strResponse = GetData(send_buf, data);

   Image31->Picture ->LoadFromFile(light_img_31_OFF);
}
//---------------------------------------------------------------------------
