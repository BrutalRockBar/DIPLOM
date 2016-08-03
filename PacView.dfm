object Form4: TForm4
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = #1053#1086#1074#1099#1081' '#1087#1072#1094#1080#1077#1085#1090
  ClientHeight = 323
  ClientWidth = 411
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 249
    Top = 295
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 232
    Top = 295
    Width = 75
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 2
    Visible = False
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 330
    Top = 295
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 295
    Width = 75
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 4
    Visible = False
    OnClick = Button4Click
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 1
    Width = 397
    Height = 288
    Caption = #1051#1080#1095#1085#1099#1077' '#1076#1072#1085#1085#1099#1077' '#1087#1072#1094#1080#1077#1085#1090#1072
    TabOrder = 0
    object Label1: TLabel
      Left = 130
      Top = 24
      Width = 44
      Height = 13
      Caption = #1060#1072#1084#1080#1083#1080#1103
    end
    object Label2: TLabel
      Left = 130
      Top = 46
      Width = 19
      Height = 13
      Caption = #1048#1084#1103
    end
    object Label3: TLabel
      Left = 130
      Top = 73
      Width = 49
      Height = 13
      Caption = #1054#1090#1095#1077#1089#1090#1074#1086
    end
    object Label4: TLabel
      Left = 81
      Top = 100
      Width = 73
      Height = 13
      Caption = #1043#1086#1076' '#1088#1086#1078#1076#1077#1085#1080#1103
    end
    object Label5: TLabel
      Left = 81
      Top = 127
      Width = 19
      Height = 13
      Caption = #1055#1086#1083
    end
    object Label6: TLabel
      Left = 3
      Top = 151
      Width = 35
      Height = 13
      Caption = #1040#1076#1088#1077#1089':'
    end
    object Edit1: TEdit
      Left = 3
      Top = 16
      Width = 121
      Height = 21
      MaxLength = 50
      TabOrder = 0
      OnKeyPress = Edit1KeyPress
    end
    object Edit2: TEdit
      Left = 3
      Top = 43
      Width = 121
      Height = 21
      MaxLength = 50
      TabOrder = 1
      OnKeyPress = Edit2KeyPress
    end
    object Edit3: TEdit
      Left = 3
      Top = 70
      Width = 121
      Height = 21
      MaxLength = 50
      TabOrder = 2
      OnKeyPress = Edit3KeyPress
    end
    object ComboBox2: TComboBox
      Left = 3
      Top = 124
      Width = 72
      Height = 21
      TabOrder = 4
      Text = #1052
      Items.Strings = (
        #1052
        #1046)
    end
    object Memo1: TMemo
      Left = 3
      Top = 165
      Width = 185
      Height = 60
      MaxLength = 60
      TabOrder = 5
    end
    object GroupBox2: TGroupBox
      Left = 191
      Top = 3
      Width = 203
      Height = 222
      Caption = #1059#1095#1105#1090
      TabOrder = 6
      object Label7: TLabel
        Left = 122
        Top = 19
        Width = 25
        Height = 13
        Caption = #1059#1095#1105#1090
      end
      object Label8: TLabel
        Left = 119
        Top = 46
        Width = 66
        Height = 13
        Caption = #1053#1086#1084#1077#1088' '#1082#1072#1088#1090#1099
      end
      object Label9: TLabel
        Left = 119
        Top = 73
        Width = 50
        Height = 13
        Caption = #1044#1086#1082#1091#1084#1077#1085#1090
      end
      object Label10: TLabel
        Left = 119
        Top = 100
        Width = 31
        Height = 13
        Caption = #1040#1088#1093#1080#1074
      end
      object Label11: TLabel
        Left = 119
        Top = 127
        Width = 30
        Height = 13
        Caption = #1064#1080#1092#1088
      end
      object Edit5: TEdit
        Left = 5
        Top = 43
        Width = 108
        Height = 21
        MaxLength = 40
        TabOrder = 1
      end
      object Edit6: TEdit
        Left = 5
        Top = 70
        Width = 108
        Height = 21
        MaxLength = 40
        TabOrder = 2
      end
      object Edit7: TEdit
        Left = 5
        Top = 97
        Width = 108
        Height = 21
        MaxLength = 40
        TabOrder = 3
      end
      object ComboBox3: TComboBox
        Left = 5
        Top = 16
        Width = 108
        Height = 21
        TabOrder = 0
        OnSelect = ComboBox3Select
      end
      object Edit8: TEdit
        Left = 5
        Top = 124
        Width = 108
        Height = 21
        MaxLength = 40
        TabOrder = 4
      end
      object GroupBox3: TGroupBox
        Left = 3
        Top = 149
        Width = 197
        Height = 68
        Caption = #1044#1072#1090#1072' '#1091#1095#1105#1090#1072':'
        TabOrder = 5
        object Label12: TLabel
          Left = 130
          Top = 20
          Width = 60
          Height = 13
          Caption = #1055#1086#1089#1090#1072#1085#1086#1074#1082#1080
        end
        object Label13: TLabel
          Left = 130
          Top = 47
          Width = 37
          Height = 13
          Caption = #1057#1085#1103#1090#1080#1103
        end
        object Edit9: TEdit
          Left = 3
          Top = 17
          Width = 102
          Height = 21
          MaxLength = 8
          TabOrder = 0
          OnKeyPress = Edit9KeyPress
        end
        object Edit10: TEdit
          Left = 3
          Top = 44
          Width = 102
          Height = 21
          MaxLength = 8
          TabOrder = 1
          OnKeyPress = Edit10KeyPress
        end
        object Button5: TButton
          Left = 104
          Top = 16
          Width = 20
          Height = 22
          Caption = '...'
          TabOrder = 2
          OnClick = Button5Click
        end
        object Button6: TButton
          Left = 104
          Top = 44
          Width = 20
          Height = 21
          Caption = '...'
          TabOrder = 3
          OnClick = Button6Click
        end
      end
    end
    object GroupBox4: TGroupBox
      Left = 3
      Top = 226
      Width = 391
      Height = 57
      TabOrder = 7
      object Label14: TLabel
        Left = 320
        Top = 8
        Width = 44
        Height = 13
        Caption = #1040#1085#1072#1083#1080#1079#1099
      end
      object Label15: TLabel
        Left = 320
        Top = 35
        Width = 43
        Height = 13
        Caption = #1042#1099#1087#1080#1089#1082#1080
      end
      object Edit4: TEdit
        Left = 3
        Top = 5
        Width = 311
        Height = 21
        MaxLength = 50
        TabOrder = 0
      end
      object Edit11: TEdit
        Left = 3
        Top = 32
        Width = 311
        Height = 21
        MaxLength = 50
        TabOrder = 1
      end
    end
    object ComboBox1: TComboBox
      Left = 3
      Top = 97
      Width = 72
      Height = 21
      TabOrder = 3
    end
  end
  object ComboBoxEx1: TComboBoxEx
    Left = 352
    Top = 20
    Width = 46
    Height = 22
    ItemsEx = <>
    TabOrder = 5
    Images = Form1.ImageList1
  end
  object MonthCalendar1: TMonthCalendar
    Left = 202
    Top = 14
    Width = 162
    Height = 153
    Date = 41679.976315150460000000
    TabOrder = 6
    Visible = False
    OnDblClick = MonthCalendar1DblClick
  end
end
