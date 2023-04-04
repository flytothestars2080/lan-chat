# 局域网聊天程序

#### 介绍
qt 写的局域网聊天程序

#### 软件架构
软件架构说明


#### 安装教程

1.  LANChat_APP_Release文件是用windeployqt.exe 动态连接而成的在里面找到exe文件程序就可以直接运行
2. LANChat文件是项目文件，有qt项目文件和源代码
3.

#### 使用说明

1.  登录界面


![登陆界面](https://github.com/flytothestars2080/lan-chat/blob/master/P1.PNG)

密码123456，用户名随意

2.  运行界面

![运行界面](https://github.com/flytothestars2080/lan-chat/blob/master/P2.PNG)


3.文件传输
![文件转输](https://github.com/flytothestars2080/lan-chat/blob/master/P3.PNG)

不过这个文件传输在release下会失效
我还没找到原因




3.  xxxx

#### 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request


#### 特技

主要使用Qt的网络库 和线程库，局域网聊天程序即是服务器又是客户端，使用udp广播来实现用户的登录，下线等
文件传输和接收使用TCP ,继承 QTcpSocket +movetothread 来实现 多线程多文件 发送.

