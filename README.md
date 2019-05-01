32-channel-relay-controller-board-remote-control-by-C++Builder-internet

This code is a sample project for 32 channel relay control in WAN by web http string. It's very easy to use. 

The software according to KinCony's KC868-H32/W smart controller's protocol. the relay will be ON/OFF that you send string to Server.

This project use C++Builder 10.2.3 coding.


***Sample for relay remote control:***

Let's take the simplest example of sending a http command string through a web browser to turn on the first relay switch.

First, let's look at the command structure of sending http strings remotely.
 

Interface address: http://sdk.kincony.com:8080/smarthome.imcplatform/device/v1.0/sendcommand.action


Example:

HTTP Request:

http://sdk.kincony.com:8080/smarthome.IMCPlatform/device/v1.0/sendCommand.action?deviceCode=56a890e6888793c97XXXXXXX&command=RELAY-SET-1,1,1

Cloud server returns:

{"message": "command: relay-set-1,1,1 was sent to device:

56a890e6888793c97XXXXXXX successfully.",

"result": "RELAY-SET-1,1,1,oku0000",

"status": "0"}

 

DeviceCode is the serial number of the device. There will be sticky QR code and serial number on the shell. If the serial number is not found, it can also be obtained by using the communication protocol to read the serial number.

 

What follow the Command is the protocol commands from the communication protocol we talked about earlier, including control relay switch, check relay status and read input status protocol content.

 

Note: when we are using the http protocol to remote the device, all the byte parameters including “package number” from the communication protocol will be self-assigned when the command is sending every time. The range is 1 to 255. If the parameter sent by the first command is “1”, the second will be “2”, the third will be “3” …... when the parameter is up to “255”, it will change back into “1” and loop again.

![32 channel relay controller](https://ae01.alicdn.com/kf/HTB13sbVaIfrK1Rjy0Fmq6xhEXXao.jpg)

![Code window](https://ae01.alicdn.com/kf/HTB1OmvJaInrK1RkHFrdq6xCoFXaG.jpg)

![Network Relay Board](https://ae01.alicdn.com/kf/HTB1fXvHaLLsK1Rjy0Fbq6xSEXXah.jpg)

![Turn ON OFF Relay](https://ae01.alicdn.com/kf/HTB1.ArMaODxK1Rjy1zcq6yGeXXae.jpg)

***If you need the hardware in here:***

32 Channel relay controller: https://www.aliexpress.com/store/product/32-Channel-Relay-controller-Module-Ethernet-RS232-PC-Serial-Port-Smart-Home-Control-tcp-ip/807891_555335460.html?spm=a2g1y.12024536.productList_14403156.pic_0

8 Channel relay controller: https://www.aliexpress.com/store/product/8-Channel-Relay-controller-Module-Ethernet-RS232-PC-Serial-Port-Smart-Home-Control-tcp-ip/807891_555377986.html?spm=a2g1y.12024536.productList_14403156.pic_2

If you are looking for network relay remote control solutions , see more details can visit KinCony's webpage: https://www.kincony.com
