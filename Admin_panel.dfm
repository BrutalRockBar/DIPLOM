object Form7: TForm7
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1080
  ClientHeight = 215
  ClientWidth = 706
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 168
    Top = 191
    Width = 63
    Height = 13
    Caption = #1057#1086#1093#1088#1072#1085#1077#1085#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
    StyleElements = [seClient, seBorder]
  end
  object StringGrid1: TStringGrid
    Left = 0
    Top = 1
    Width = 697
    Height = 184
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
    ColWidths = (
      64
      64
      64
      64
      64)
  end
  object Button1: TButton
    Left = 0
    Top = 182
    Width = 41
    Height = 25
    Caption = '+'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 41
    Top = 182
    Width = 25
    Height = 25
    Caption = '-'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 65
    Top = 182
    Width = 33
    Height = 25
    Caption = #1054#1050
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 96
    Top = 182
    Width = 49
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 4
    OnClick = Button4Click
  end
  object Timer1: TTimer
    Interval = 2000
    OnTimer = Timer1Timer
    Left = 288
    Top = 168
  end
end
