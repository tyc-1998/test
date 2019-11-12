<p align="center">
    <img src="documents/GuiLiteCube.gif" alt="Image" width="320" height="304"/>
</p>

# GuiLite（超轻量UI框架）- 最小的GUI库
![badge_build](https://img.shields.io/badge/build-passing-brightgreen.svg) ![badge_docker](https://img.shields.io/badge/docker%20build-passing-brightgreen.svg) ![badge_platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS%20%7C%20iOS%20%7C%20Android%20%7C%20MCU-brightgreen.svg) ![badge_lincense](https://img.shields.io/badge/license-Apache%202-blue.svg) ![badge_lincense](https://img.shields.io/badge/architecture-amd64%20%7C%20arm%20%7C%20arm64-blue.svg) 
- [✨功能介绍](#功能介绍)
- [🚀快速上手](#快速上手)
- [📚开发文档](#开发文档)
- [📈学习方法](#学习方法)
- [📀视频链接](#视频链接)
- [📞社区交流](#社区交流)
***
## GuiLite是什么鬼？
GuiLite是5千行的图形界面库，可以运行在**所有平台**（例如：iOS/macOS/WathOS，Android，Linux（ARM/x86-64），Windows（包含VR），Docker和MCU）上；也可以与**多种语言**（例如： Swift, Java, Javascript, C#, Golang）协同工作。
- ✂️轻量: 5千行C++代码，可合并在：1个头文件(GuiLite.h)，1个实现文件(GuiLite.cpp)中 - 轻松[编译/移植](documents/HowToBuild.md)
- ⚡超快: 一次调用就可以完成图形渲染，与操作系统及第三方库无关 - 程序更快速，UI更流畅
- 💉可注入: 可注入在Qt/MFC/Winform/Cocoa/Web程序中运行 - 充分利用现有Qt/MFC代码，局部GuiLite优化，亦可显著提升效率
- ⚙️️最低硬件要求:

| Processor | Disk/ROM space | Memory |
| --- | --- | --- |
| 24 MHZ | 29 KB | 9 KB |

## 🔥新功能：苹果手表
GuiLite程序，可以同时运行在单片机和苹果“手表”上：

| MCU | Apple Watch |
| --- | --- |
| ![Hello3D](documents/Hello3D.gif) | ![iWatch.hello3D](documents/iWatch.hello3D.gif) |
| ![MCU](documents/HelloWave.gif) | ![iWatch.helloWave](documents/iWatch.helloWave.gif) |

## ✨功能介绍
### ⚔️卓越的跨平台能力
| ARM Linux | STM32 Without OS |
| --- | --- |
| ![ARM Linux](documents/Linux.gif) | ![MCU](documents/HelloParticle.gif) ![MCU](documents/HelloWave.gif) |

| Windows Mixed Reality | Android |
| --- | --- |
| ![Win MR](documents/WinMR.gif) | ![Android](documents/Android.gif) |

| macOS | iOS & Apple Watch |
| --- | --- |
| ![macOS](documents/Mac.gif) | ![iOS.hostMonitor](documents/iOS.gif) ![iOS.particle](documents/iOS.particle.gif) ![iWatch.helloWave](documents/iWatch.helloWave.gif) |
***
### 🔍GuiLite Previewer(所见即所得的GuiLite开发插件)
[GuiLite Previewer](https://github.com/idea4good/GuiLitePreviewer)是一个Visual Studio Code插件，它可以自动提取源代码的GUI布局信息，并实时显示在“预览”页面上(所见即所得)
![GuiLitePreviewer](documents/Previewer.gif)
***
### 😎浮夸的UI效果
![HostMonitor](documents/HostMonitor.gif)![HelloNets-pc](documents/HelloNets-pc.gif)
***
### 🔣万国语(unicode)：
![unicode](documents/unicode.jpg)
***
### 🌐IoT（物联网）和📊数据分析
- 上报“编译/运行”情况至“云端”：<br>![BuildInfo](documents/BuildInfo.png)
- 同步“运行数据”至“云端”：<br>![DataOnCloud](documents/data_on_cloud.png)
***
### 🐋支持Docker
我们把GuiLite demo做成了Docker映像，只需一行命令，就可以将最新的GuiLite demo升级/部署/运行在你的设备上了。
- `sudo docker run -it --privileged -v /dev:/dev-share idea4good/gui-lite:latest bash /run.sh`
***
## 📦3D
- ![GuiLiteGraphic](documents/GuiLite3D.gif) ![Hello3D](documents/Hello3D.gif)
- GuiLite实例[(HelloParticle, HelloWave)](https://gitee.com/idea4good/GuiLiteSamples)运行在Web及3D环境，[代码在这里](https://github.com/idea4good/GuiLiteWeb/blob/master/CubeEx/main.js)
- 在单片机上也能运行3D效果（具体参看GuiLiteSamples:Hello3D）
***
## 🚀快速上手
GuiLite只是一个框架，本身并不能生成UI。为了能够展示如何用GuiLite开发App，我们提供了一些实例程序给大家参考。
- 实例程序的代码在[这里](https://gitee.com/idea4good/GuiLiteSamples)
- 实例程序的功能说明：

| 实例名称 | 支持的平台 | 功能简介 | 编译方法 | 难度 |
| --- | --- | --- | --- | --- |
| HelloParticle | Windows, Linux, STM32F103, STM32F429 | 粒子效果的应用 | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloParticle/README.md) | ★|
| HelloStar | Windows, Linux, STM32F103, STM32F429 | 星空效果的应用 | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloStar/README.md) | ★|
| Hello3D | Windows, Linux, STM32F103 | 基于GuiLite的超轻量（单片机级别）3D引擎 | [Build](https://gitee.com/idea4good/GuiLiteSamples/blob/master/Hello3D/README.md) | ★★ |
| HelloNets | Windows, Linux, STM32F103 | 3D物理过程的应用 | [Build](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloNets/README.md) | ★★ |
| HelloGuiLite | Windows, Linux | 初始化GuiLite，加载资源，布局界面元素，按钮响应 | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloGuiLite/README.md) | ★★|
| HelloWidgets | Windows, Linux | 用于演示基本控件的使用方法 | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloWidgets/README.md) | ★★|
| HelloMario | Windows, Linux, STM32F103, STM32F429 | 多图层的UI系统 | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloMario/README.md) | ★★|
| HelloNoTouch | Windows, Linux, STM32F103, STM32F429 | 用于非触摸屏场景，通过硬按键进行UI“导航” | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloNoTouch/README.md) | ★★|
| HelloFont | Windows, Linux | 显示多种语言（不限：中、英文） | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloFont/README.md) | ★★|
| HelloAnimation | Windows, Linux | 动画的应用 | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloAnimation/README.md) | ★★|
| HelloSlide | Windows, Linux | 滑屏界面的应用 | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloSlide/README.md) | ★★★|
| HelloWave | Windows, Linux, STM32F103, STM32F429 | 波形控件的应用，及单片机移植办法 | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloWave/README.md) | ★★★|
| HostMonitor | iOS, Mac, Android, Windows, Linux | 创建复杂界面，扩展自定义控件，适配全平台 | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HostMonitor/README.md) | ★★★★|

## 📚开发文档
GuiLite是最简单，易学的GUI库。
1. 只有5千行C++代码
2. 只使用C++的基本特性（类和虚函数），不涉及复杂语法
3. 图形绘制以描点为基础，不使用任何算法
4. 设计简单，配有丰富的文档和实例程序；遇到问题，可以在QQ群获得帮助
    - [软件设计说明](documents/HowToWork-cn.md)
    - [如何编译和移植?](documents/HowToBuild.md)
    - [如何布局UI?](documents/HowLayoutWork.md)
    - [如何制作多种文字/位图资源?](https://github.com/idea4good/GuiLiteToolkit)
    - [如何“换肤”？](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HostMonitor/UIcode/source/resource/resource.cpp)
    - [如何传递消息?](documents/HowMessageWork.md)
    - [核心UML示意图](documents/UML.md)
    - GuiLite滑动，及多层叠加原理
        - ![GuiLiteGraphic](documents/GuiLiteGraphic.gif)
        - [完整视频](https://v.youku.com/v_show/id_XNDI4ODE1ODcwOA)
        - [Source code](https://github.com/idea4good/GuiLiteWeb/blob/master/Graphic/main.js)

## 📈学习方法
1. **外围** - 成功编译GuiLite库
2. **前戏** - 成功运行HelloXXX实例程序
3. **交流** - 研读/修改100+行的`HelloXXX/UIcode/UIcode.cpp`源代码
4. **深交** - 研读`gui`目录下的代码
5. **攻核** - 研读`core`目录下的代码
6. **分家** - 丰富，扩展自己的UI功能

## 📀视频链接:
- [GuiLite简介](https://v.youku.com/v_show/id_XMzA5NTMzMTYyOA)
- [3D GuiLite](https://v.youku.com/v_show/id_XMzYxNTE3MTI0MA)
- [GuiLite + 单片机](https://v.youku.com/v_show/id_XNDAwNzM5MTM3Ng)

## 镜像代码仓库
[GitHub链接](https://github.com/idea4good/GuiLite)

## 📞社区交流
- 感谢开发者群的所有同学，是你们塑造了今天的GuiLite！也欢迎新的大神/小白加入我们。<br>[<img src="documents/qq.group.jpg">](https://jq.qq.com/?_wv=1027&k=5EO8D9i)
