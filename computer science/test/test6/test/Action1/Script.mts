' Region Login Dialog..
Dialog("Login").WinEdit("Agent Name:").Set "user1"
Dialog("Login").WinEdit("Password:").Set "MERCURY"
Dialog("Login").WinButton("OK").Click
' Region Flight Reservation
Window("Flight Reservation").ActiveX("MaskEdBox").Type "123410" ' 输入2010/12/34（是一个非法值）
Window("Flight Reservation").WinComboBox("Fly From:").Select "London" '点击Fly From中的London
' 我们在这里添加一个断言，判断是否弹出了对话框
Window("Flight Reservation").Dialog("Flight Reservations").Static("Invalid day Entered. The").CheckProperty"visible","True"

Window("Flight Reservation").Dialog("Flight Reservations").WinButton("确定").Click ' 将会弹出警告提示框，然后点击确认
Window("Flight Reservation").ActiveX("MaskEdBox").Click 2,7
Window("Flight Reservation").ActiveX("MaskEdBox").Type "1"
Window("Flight Reservation").ActiveX("MaskEdBox").Drag 52,6
Window("Flight Reservation").Drop -2,109
Window("Flight Reservation").ActiveX("MaskEdBox").Type "100921"
Window("Flight Reservation").WinComboBox("Fly From:").Select "London"
Window("Flight Reservation").WinComboBox("Fly To:").Select "Denver"
Window("Flight Reservation").WinButton("FLIGHT").Click
Window("Flight Reservation").Dialog("Flights Table").WinButton("OK").Click
Window("Flight Reservation").WinEdit("Name:").Set "航班1"
Window("Flight Reservation").WinEdit("Tickets:").SetSelection 0,1
Window("Flight Reservation").WinEdit("Tickets:").Set "2"
Window("Flight Reservation").WinRadioButton("Business").Set
'添加两个断言
Window("Flight Reservation").WinEdit("Flight No:").CheckProperty"text","20284"
Window("Flight Reservation").WinEdit("Price:").CheckProperty"text","$224.40"

Window("Flight Reservation").WinButton("Insert Order").Click






